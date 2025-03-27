/*
BISMILLAHIR RAHMANIR RAHIM..

“وَوَجَدَكَ ضَالًّا فَهَدَى”
“And He found you lost and guided you.”

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define make_faster                   \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
const int MOD = 998244353;
const int N = 1e7 + 1;
#define set_precision(x) cout << fixed << setprecision(x);

// Loops
#define fo(i, a, b) for (int i = a; i < b; i++)
#define fo1(i, a, b) for (int i = a; i <= b; i++)
#define rof(i, a, b) for (int i = a; i >= b; i--)

// Min & Max
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))

// Pair, Vector
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pii>

// Binary Search, Lower Bound, Upper Bound
#define lb(v, x) (lower_bound(all(v), x) - v.begin()) // Lower Bound index
#define ub(v, x) (upper_bound(all(v), x) - v.begin()) // Upper Bound index
#define bs(v, x) (binary_search(all(v), x))           // Binary Search boolean

// Math Functions
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a / gcd(a, b)) * b)
#define mod_exp(base, exp, mod) ([](int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; })(base, exp, mod)
#define modinv(a, m) mod_exp(a, m - 2, m)

// Bit Manipulation
#define bitcount(x) __builtin_popcountll(x)   // Count set bits
#define tzcount(x) __builtin_ctzll(x)         // Trailing zeros
#define isPowerOfTwo(x) (x && !(x & (x - 1))) // Check power of 2

// Coordinate Compression
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())

// Fast Input/Output
#define print(v)          \
    for (auto x : v)      \
        cout << x << " "; \
    cout << endl;

// Debugging
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define dbg_v(v)          \
    cerr << #v << " = ";  \
    for (auto x : v)      \
        cerr << x << " "; \
    cerr << endl;

vi small_primes;

void sieve(int limit)
{
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= limit; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= limit; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= limit; i++)
    {
        if (is_prime[i])
        {
            small_primes.push_back(i);
        }
    }
}

int32_t main()
{
    make_faster;
    int t;
    cin >> t;
    sieve(1e5);
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<bool> prime(m - n + 1, true);

        if (n == 1)
            prime[0] = false; 

        for (int p : small_primes)
        {
            if (p * p > m)
                break;

            int start = max(p * p, (n + p - 1) / p * p);

            for (int j = start; j <= m; j += p)
            {
                prime[j - n] = false;
            }
        }

        for (int i = 0; i <= m - n; i++)
        {
            if (prime[i])
            {
                cout << (n + i) << "\n";
            }
        }
        cout << endl;
    }
}