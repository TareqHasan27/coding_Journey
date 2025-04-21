#include<bits/stdc++.h>
using namespace std;
#define int long long

// this is the code using 2D dp array iterative way
// ---------------------------------------------------

const int INF = 1e9; // A large value representing "infinity"

// int main() {
//     int n, amount;
//     cin >> n >> amount; // Read number of coins and target amount

//     vector<int> coins(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> coins[i];
//     }
//     // Create DP table with size (n+1) x (amount+1)
//     vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

//     // Base case: 0 coins to make amount 0 = 0 coins needed
//     for (int i = 0; i <= n; ++i)
//         dp[i][0] = 0;

//     // Fill the DP table
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= amount; ++j) {
//             if (j >= coins[i - 1]) {
//                 // min of not taking this coin or taking it (and stay on same row)
//                 dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
//             } else {
//                 // Can't take this coin
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     // Final answer
//     int result = dp[n][amount];
//     if (result >= INF)
//         cout << "\n❌ Not possible to make amount " << amount << " with given coins.\n";
//     else
//         cout << "\n✅ Minimum coins to make " << amount << " = " << result << "\n";

//     return 0;
// }


// ---------------------------------------------------
// this is the code using 1D dp array iterative way
// ---------------------------------------------------


int minCoins(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INF);
    dp[0] = 0; // Base case: 0 coins to make amount 0

    for (int coin : coins)
    {
        for (int j = coin; j <= amount; j++)
        {
            dp[j] = min(dp[j], 1 + dp[j - coin]);
        }
    }

    return dp[amount];
}

int32_t main()
{
    int n, amount;
    cin >> n >> amount; // Read number of coins and target amount

    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
    }

    int result = minCoins(coins, amount);
    if (result >= INF)
        cout << "\n❌ Not possible to make amount " << amount << " with given coins.\n";
    else
        cout << "\n✅ Minimum coins to make " << amount << " = " << result << "\n";

    return 0;
}