#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
bool vis[N];
vector<int> g[N];

void dfs(int u)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

// complexity O(V+E);
int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans++;
            cout << "disconnected" << "\n";
            // return 0;
        }
    }
    // cout << "connected" << "\n";
    cout << ans << '\n';
}