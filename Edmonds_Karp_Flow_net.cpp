// Edmonds-Karp Algorithm for Maximum Flow
// This implementation uses BFS to find augmenting paths in the flow network.
// It is more efficient than the Ford-Fulkerson algorithm and has a time complexity of O(V * E^2), where V is the number of vertices and E is the number of edges.
// This implementation is suitable for larger flow networks.


#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
int capacity[MAX][MAX];     // Original capacity
int residual[MAX][MAX];     // Residual capacity
int parent[MAX];            // To store path

bool bfs(int s, int t, int n) {
    memset(parent, -1, sizeof(parent));
    queue<int> q;
    q.push(s);
    parent[s] = -2;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < n; v++) {
            if (parent[v] == -1 && residual[u][v] > 0) {
                parent[v] = u;
                if (v == t) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int edmondsKarp(int s, int t, int n) {
    int maxFlow = 0;

    // Copy capacity to residual
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            residual[i][j] = capacity[i][j];

    while (bfs(s, t, n)) {
        int flow = INT_MAX;
        int v = t;

        // Find the minimum capacity in the path
        while (v != s) {
            int u = parent[v];
            flow = min(flow, residual[u][v]);
            v = u;
        }

        // Update residual capacities
        v = t;
        while (v != s) {
            int u = parent[v];
            residual[u][v] -= flow;
            residual[v][u] += flow;
            v = u;
        }

        maxFlow += flow;
    }

    return maxFlow;
}

int main() {
    int n, e;
    // cout << "Enter number of nodes: ";
    cin >> n;
    // cout << "Enter number of edges: ";
    cin >> e;

    memset(capacity, 0, sizeof(capacity));

    // cout << "Enter edges in format: u v cap\n";
    for (int i = 0; i < e; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        capacity[u][v] = cap;  // Directed edge
    }

    int s, t;
    // cout << "Enter source and sink: ";
    cin >> s >> t;

    int maxFlow = edmondsKarp(s, t, n);
    cout << "Maximum Flow: " << maxFlow << endl;

    cout << "\nFlow per edge (u -> v = flow/capacity):\n";
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (capacity[u][v] > 0) {
                int flowUsed = capacity[u][v] - residual[u][v];
                cout << u << " -> " << v << " = " << flowUsed << "/" << capacity[u][v] << endl;
            }
        }
    }

    return 0;
}
