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

vector<int> longestCommonSubsequence(const vector<int> &a, const vector<int> &b)
{
    int len1 = a.size(), len2 = b.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    // Build DP table
    for (int i = 1; i <= len1; ++i)
    {
        for (int j = 1; j <= len2; ++j)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct LCS from DP table
    vector<int> lcs;
    int i = len1, j = len2;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs.push_back(a[i - 1]);
            --i;
            --j;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                --i;
            }
            else
            {
                --j;
            }
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int32_t main()
{
    // faster() int t;
    // cin >> t;
    // while (t--)
    // {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int m;
        cin >> m;
        vector<int> v1(m);
        for (int i = 0; i < m; i++)
        {
            cin >> v1[i];
        }
        vector<int> ans = longestCommonSubsequence(v, v1);
        cout << ans.size() << endl;
        for (auto i : ans)
            cout << i << " ";
    // }
    return 0;
}