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
const int N = 502;

vector<int> longestCommonIncreasingSubsequence(const vector<int> &a, const vector<int> &b)
{
    int n = b.size();
    vector<int> dp(n, 0);      // Stores the length of LCIS ending at b[j]
    vector<int> parent(n, -1); // Tracks predecessors to reconstruct the sequence

    for (int x : a)
    {   
        int current_max = 0; // Tracks the maximum valid LCIS length for elements < x
        int prev_idx = -1;   // Index of the predecessor for the current element
        for (int j = 0; j < n; ++j)
        {
            if (b[j] == x)
            {
                // Update dp[j] if a longer sequence is found
                if (current_max + 1 > dp[j])
                {
                    dp[j] = current_max + 1;
                    parent[j] = prev_idx; // Link to the predecessor
                }
            }
            else if (b[j] < x)
            {
                // Update current_max if a longer valid sequence exists
                if (dp[j] > current_max)
                {
                    current_max = dp[j];
                    prev_idx = j; // Track the predecessor index
                }
            }
        }
    }

    // Find the index of the maximum length in dp
    int max_length = 0;
    int max_idx = -1;
    for (int j = 0; j < n; ++j)
    {
        if (dp[j] > max_length)
        {
            max_length = dp[j];
            max_idx = j;
        }
    }

    // Reconstruct the LCIS using the parent pointers
    vector<int> lcis;
    while (max_idx != -1)
    {
        lcis.push_back(b[max_idx]);
        max_idx = parent[max_idx];
    }
    reverse(lcis.begin(), lcis.end()); // Reverse to get the correct order

    return lcis;
}

int32_t main()
{
    // faster() int t;
    // cin >> t;
    // while (t--)
    // {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<int> result = longestCommonIncreasingSubsequence(a, b);

    cout << result.size() << endl;
    for (auto num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    // }
    return 0;
}