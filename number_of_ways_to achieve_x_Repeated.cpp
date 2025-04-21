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

// this is using recursive way
// ---------------------------------------------------

// const int N = 1e6 + 5;
// int dp[N];
// int coin[105];
// int n, Sum;

// int count(int sum)
// {
//     if(sum == 0) return 1;
//     if(dp[sum] != -1) return dp[sum];
//     int ans = 0;
//     for(int i = 1; i <= n; i++)
//     {
//         if(sum - coin[i] >= 0)
//         ans =(ans + count(sum - coin[i])) % MOD;
//     }
//     dp[sum] = ans;
//     return dp[sum];
// }

// void solve()
// {

//     cin >> n >> Sum;
//     memset(dp , -1 , sizeof dp);
//     dp[0] = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> coin[i];
//     }

//     cout << count(Sum) << endl;

// }

// int32_t main()
// {
//     make_faster;
//     solve();
// }

// ---------------------------------------------------
// this is the code using 1D dp array iterative way
// ---------------------------------------------------

int countWays(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int j = 1; j <= amount; j++)
    {
        for (int coin : coins)
        {
            if (j >= coin)
                dp[j] += dp[j - coin];
        }
    }

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