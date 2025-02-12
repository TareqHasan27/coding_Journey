#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tareq()                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
int tree[100005];
int arr[100005];

int QUERY_SUM(int indx)
{
    int sum = 0;
    for (; indx > 0; indx -= (indx & (-indx)))
    {
        sum += tree[indx];
    }
    return sum;
}

void BIT_UPDATE(int n, int indx, int value)
{
    for (; indx <= n; indx += (indx & (-indx)))
    {
        tree[indx] += value;
    }
}

void BIT_BUILD(int n)
{
    for (int i = 1; i <= n; i++)
    {
        BIT_UPDATE(n, i, arr[i]);
    }
}

int32_t main()
{
    tareq() int t;
    cin >> t;
    int cn = 0;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        tree[0] = 0;
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[j];
            tree[j] = 0;
        }
        BIT_BUILD(n);
        cout << "Case " << ++cn << ":" << endl;
        while (q--)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                int indx;
                cin >> indx;
                int val = arr[indx + 1];
                arr[indx + 1] = 0;
                cout << val << endl;
                BIT_UPDATE(n, indx + 1, val);
            }
            else if (x == 2)
            {
                int i, taka;
                cin >> i >> taka;
                arr[i + 1] += taka;
                BIT_UPDATE(n, i + 1, taka);
            }
            else
            {
                int l, r;
                cin >> l >> r;

                cout << QUERY_SUM(r + 1) - QUERY_SUM(l) << endl;
            }
        }
    }
}