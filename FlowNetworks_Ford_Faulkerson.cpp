// Ford-Fulkerson Algorithm for Maximum Flow in a Flow Network
// This implementation uses DFS to find augmenting paths in the flow network.
// It is less efficient than the Edmonds-Karp algorithm but simpler to implement.
// The algorithm is based on the idea of finding augmenting paths in the residual graph and updating the flow until no more augmenting paths can be found.
// The time complexity is O(E * f), where E is the number of edges and f is the maximum flow in the network.
// This implementation is suitable for small to medium-sized flow networks.

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int capacity[MAX][MAX];     // Original capacity
int residual[MAX][MAX];     // Residual capacity
bool visited[MAX];          // Visited array for DFS

int dfs(int u, int t, int flow, int n) {
    if (u == t) return flow;

    visited[u] = true;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && residual[u][v] > 0) {
            int min_cap = min(flow, residual[u][v]);
            int pushed = dfs(v, t, min_cap, n);
            if (pushed > 0) {
                residual[u][v] -= pushed;
                residual[v][u] += pushed;
                return pushed;
            }
        }
    }
    return 0;
}

int fordFulkerson(int s, int t, int n) {
    int maxFlow = 0;

    // Copy capacity to residual matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            residual[i][j] = capacity[i][j];

    while (true) {
        memset(visited, 0, sizeof(visited));
        int flow = dfs(s, t, INT_MAX, n);
        if (flow == 0) break;
        maxFlow += flow;
    }

    return maxFlow;
}

int main() {
    int n, e;
    cin >> n >> e;

    // Initialize all capacities to 0
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

    int maxFlow = fordFulkerson(s, t, n);
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
