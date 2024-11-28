#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tareq()                       \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);

void prims(vector<pair<int, int>> graph[], int source, int node)
{
	int cost = 0;
	bool f = false;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<bool> vis(node, false);
	pq.push({0, source});
	vector<pair<int, int>> mst;
	vector<int> parent(node + 1, -1);
	while (!pq.empty())
	{
		auto top = pq.top();
		pq.pop();
		int a = top.first;
		int b = top.second;
		if (!vis[b])
		{
			vis[b] = true;
			cost += a;
			if (parent[b] != -1)
			{
				mst.push_back({parent[b], b}); // add the edge to MST
			}

			for (auto u : graph[b])
			{
				int x = u.first;
				int y = u.second;
				if (!vis[x])
				{
					pq.push({y, x});
					parent[x] = b;
				}
			}
		}
	}
	for (int i = 1; i <= node; i++)
	{
		if (vis[i] == false)
		{
			cout << "IMPOSSIBLE";
			return;
		}
	}
	cout << cost << endl;
	for (auto u : mst)
	{
		cout << u.first << " " << u.second << endl;
	}
}

int32_t main()
{
	tareq();
	int node, edge;
	cin >> node >> edge;
	vector<pair<int, int>> graph[node + 1];
	for (int i = 0; i < edge; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	prims(graph, 1, node);

	return 0;
}