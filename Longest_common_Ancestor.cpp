#include <bits/stdc++.h>
using namespace std;

#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define int long long
#define yes cout << "YES" << "\n"
#define no cout << "NO" << "\n"
#define endl "\n"

const int mod = 1e9 + 7;
const int N = 1e5 + 9;
vector<int> graph[N];
vector<int> parent(N, -1);


void dfs(int node, int par = -1)
{
    parent[node] = par;
    for (int child : graph[node])
    {
        if (child == par)
            continue;
        
        dfs(child, node);
    }
}

vector<int> find_path(int u)
{
    vector<int> path;
    while (u != -1)
    {
        path.push_back(u);
        u = parent[u];
    }
    reverse(path.begin(), path.end());
    return path;
}


int32_t main()
{
    faster();
    int n , m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int x , y; cin >> x >> y;
    dfs(1);
    vector<int> path_x = find_path(x);
    vector<int> path_y = find_path(y);
    int lca = -1;
    for(int i = 0; i < min(path_x.size(), path_y.size()); i++){
        if(path_x[i] == path_y[i]){
            lca = path_x[i];
        }else{
            break;
        }
    }
    cout << lca << endl;

    return 0;
}