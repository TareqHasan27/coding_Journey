#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int vis[N];
vector<vector<int>> g;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        g.push_back({x, y, wt});
    }
    vector<int> dis(n , INT32_MAX);
    dis[0] = 0;
    bool cycle;
    for (int i = 0; i < n - 1; i++)
    {
        cycle = false;
        for (auto edges : g)
        {
            int u = edges[0];
            int v = edges[1];
            int w = edges[2];
            if (dis[v] > w + dis[u])
                cycle = true;
            dis[v] = min(dis[v], w + dis[u]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 1; i++) {
        for(auto edges : g){
            int u = edges[0] ; // negative cycle detection
            int v = edges[1];
            int w = edges[2];
            dis[v] = min(dis[v], w+dis[u]);

        }
    }
    if (cycle)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
}