#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tareq()                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const int N = 1e5 + 5;
struct Query
{
    int l, r, idx;
};

int block_size;

bool compare(Query a, Query b)
{
    if (a.l / block_size != b.l / block_size)
        return a.l / block_size < b.l / block_size;
    return a.r < b.r;
}

void moAlgorithm(vector<int> &arr, vector<Query> &queries)
{
    int n = arr.size();
    int q = queries.size();
    block_size = sqrt(n);

    // Sort queries using the compare function
    sort(queries.begin(), queries.end(), compare);
    vector<int> result(q) , freq(N);
    int currentL = 0, currentR = -1, currentSum = 0 , currentdist = 0;
    for (Query query : queries)
    {
        int L = query.l;
        int R = query.r;

        auto add = [&](int pos)
        {
            //currentSum += arr[pos];
            freq[arr[pos]]++;
            if(freq[arr[pos]] == 1) currentdist++;
        };

        auto remove = [&](int pos)
        {
            //currentSum -= arr[pos];
            freq[arr[pos]]--;
            if(freq[arr[pos]] == 0) currentdist--;
        };

        while (currentR < R)
        {
            currentR++;
            add(currentR);
        }
        while (currentR > R)
        {
            remove(currentR);
            currentR--;
        }
        while (currentL < L)
        {
            remove(currentL);
            currentL++;
        }
        while (currentL > L)
        {
            currentL--;
            add(currentL);
        }

        result[query.idx] = currentdist;
    }
    for (auto u : result)
    {
        cout << u << "\n";
    }
}

int32_t main()
{
    tareq() int n, q;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    cin >> q;
    vector<Query> queries(q);
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        queries[i] = {l, r, i};
    }
    moAlgorithm(arr, queries);

    return 0;
}
