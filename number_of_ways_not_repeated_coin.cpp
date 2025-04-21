#include <bits/stdc++.h>
using namespace std;

#define int long long
#define make_faster                   \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
const int MOD = 1e9 + 7;
#define set_precision(x) cout << fixed << setprecision(x);


// this is the code using 2D dp array
// ---------------------------------------------------


// int countWays(vector<int>& coins, int amount) {
//     int len = coins.size();
//     vector<vector<int>> dp(len + 1, vector<int>(amount + 1, 0));

//     // Base Case: 1 way to make 0 amount
//     for (int i = 0; i <= len; i++)
//         dp[i][0] = 1;

//         // coins    0  1  2  3  4  5
//         // --------------------------
//         //  0     | 1  0  0  0  0  0
//         //  1     | 1  1  1  1  1  1
//         //  1,2   | 1  1  2  2  3  3
//         //  1,2,5 | 1  1  2  2  3  4
        

//     // Fill the table
//     for (int i = 1; i <= len; i++) {
//         for (int j = 1; j <= amount; j++) {
//             if (j >= coins[i - 1])
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
//             else
//                 dp[i][j] = dp[i - 1][j];
//         }
//     }

//     return dp[len][amount];
// }

// void solve()
// {    
//     int n, Sum;
//     cin >> n >> Sum;
//     vector<int> coins(n + 1);
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> coins[i];
//     }
//     cout << "Number of ways: " << countWays(coins, Sum) << endl;
    
// }

// int32_t main()
// {
//     make_faster;
//     // int t;
//     // cin >> t;
//     // while (t--)
//     // {
//     solve();
//     //}
// }



//      this is optimize code using 1D dp array
// -----------------------------------------------


int countWays(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins)
    {
        for (int j = coin; j <= amount; j++)
        {
            dp[j] += dp[j - coin];
        }
    }
    // 3 8
    // 1 3 5
    // initial dp[] = [1, 0, 0, 0, 0, 0, 0, 0, 0]
    // after 1 dp[] = [1, 1, 1, 1, 1, 1, 1, 1, 1]
    // after 3 dp[] = [1, 1, 1, 2, 2, 2, 3, 3, 3]
    // after 5 dp[] = [1, 1, 1, 2, 2, 3, 4, 4, 5]



    return dp[amount];
}

int32_t main()
{
    make_faster;
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> coins;
        int n, amount;
        cin >> n >> amount;
        coins.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }
        cout << "Number of ways: " << countWays(coins, amount) << endl;
    }
}