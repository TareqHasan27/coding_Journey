#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tareq()                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const int N = 2e5 + 9;
int arr[N];
int tree[4 * N];

struct LazyPropagation
{
    int initial = 0;
    int freq = 0;
};
LazyPropagation lazy[4 * N];

void buildtree(int node, int begin, int end)
{
    if (begin == end)
    {
        tree[node] = arr[begin];
        return;
    }
    int left = 2 * node, right = 2 * node + 1;
    int mid = (begin + end) / 2;
    buildtree(left, begin, mid);
    buildtree(right, mid + 1, end);
    tree[node] = (tree[left] + tree[right]);
}

void push(int node, int begin, int end , int value)
{
    if (lazy[node].freq)
    {
        tree[node] += (end - begin + 1) * (2 * lazy[node].initial + (end - begin) * lazy[node].freq) / 2;
        //tree[node] += (end - begin + 1) * value;
        if (begin != end)
        {
            int mid = (begin + end) / 2;
            int left = 2 * node;
            int right = 2 * node + 1;
            lazy[left].initial += lazy[node].initial;
            lazy[right].initial += lazy[node].initial + (mid - begin + 1) * lazy[node].freq;

            lazy[left].freq += lazy[node].freq;
            lazy[right].freq += lazy[node].freq;
        }
        lazy[node].freq = 0;
        lazy[node].initial = 0;

    }
}

void update(int node, int begin, int end, int i, int j , int value)
{
    push(node, begin, end , value);
    if (begin > j || end < i)
    {
        return;
    }
    if (begin >= i && end <= j)
    {
        lazy[node].initial += begin - i + 1;
        lazy[node].freq++;
        push(node, begin, end , value);
        return;
    }
    int left = 2 * node, right = 2 * node + 1;
    int mid = (begin + end) / 2;
    update(left, begin, mid, i, j, value);
    update(right, mid + 1, end, i, j, value);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int begin, int end, int i, int j , int value)
{
    push(node, begin, end , value);
    if (i > end || j < begin)
    {
        return 0;
    }
    if (begin >= i && end <= j)
    {
        return tree[node];
    }
    int left = 2 * node, right = 2 * node + 1;
    int mid = (begin + end) / 2;
    return query(left, begin, mid, i, j , value) + query(right, mid + 1, end, i, j , value);
}

int32_t main()
{
    tareq() int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    buildtree(1, 1, n);
    while (q--)
    {
        int type, a, b , c;
        cin >> type >> a >> b >> c;
        if (type == 1)
        {   
            update(1, 1, n, a, b, c);
        }
        else
        {   
            cout << query(1, 1, n, a, b , c) << endl;
        }
    }
}
