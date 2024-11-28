#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
bool vis[N];
vector<int> g[N];
int dist[N];

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
  queue<int> q;
  q.push(1);
  vis[1] = true;
  dist[1] = 0;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (auto v : g[u])
    {
      if (!vis[v])
      {
        q.push(v);
        vis[v] = true;
        dist[v] = dist[u] + 1;
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    cout << dist[i] << " ";
  }
  cout << endl;
}
