#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl "\n"
#define tareq() ios_base::sync_with_stdio(false); cin.tie(NULL);


// Construction of suffix array
vector<ll> suffixArrayConstruction(const string &s) {
    ll n = s.size();
    vector<ll> suffixArr(n), c(n), cnt(max((ll)256, n), 0), p(n);
    
    for (ll i = 0; i < n; ++i)
        cnt[s[i]]++;
    for (ll i = 1; i < 256; ++i)
        cnt[i] += cnt[i - 1];
    for (ll i = n - 1; i >= 0; --i)
        suffixArr[--cnt[s[i]]] = i;

    c[suffixArr[0]] = 0;
    ll classes = 1;
    for (ll i = 1; i < n; ++i) {
        if (s[suffixArr[i]] != s[suffixArr[i - 1]])
            classes++;
        c[suffixArr[i]] = classes - 1;
    }

    vector<ll> pn(n), cn(n);
    for (ll h = 0; (1 << h) < n; ++h) {
        for (ll i = 0; i < n; ++i) {
            pn[i] = suffixArr[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }

        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (ll i = 0; i < n; ++i)
            cnt[c[pn[i]]]++;
        for (ll i = 1; i < classes; ++i)
            cnt[i] += cnt[i - 1];
        for (ll i = n - 1; i >= 0; --i)
            suffixArr[--cnt[c[pn[i]]]] = pn[i];

        cn[suffixArr[0]] = 0;
        classes = 1;
        for (ll i = 1; i < n; ++i) {
            pair<ll, ll> curr = {c[suffixArr[i]], c[(suffixArr[i] + (1 << h)) % n]};
            pair<ll, ll> prev = {c[suffixArr[i - 1]], c[(suffixArr[i - 1] + (1 << h)) % n]};
            if (curr != prev)
                ++classes;
            cn[suffixArr[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return suffixArr;
}

// Function to construct the LCP array using the Kasai algorithm
vector<ll> kasaiLCP(const string &s, const vector<ll> &suffixArr) {
    ll n = s.size();
    vector<ll> lcp(n, 0), rank(n, 0);

    for (ll i = 0; i < n; ++i) {
        rank[suffixArr[i]] = i;
    }

    ll h = 0;
    for (ll i = 0; i < n; ++i) {
        if (rank[i] > 0) {
            ll j = suffixArr[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h])
                ++h;
            lcp[rank[i]] = h;
            if (h > 0)
                --h;
        }
    }
    return lcp;
}

// Count distinct substrings
void countDistinctSubstrings(const string &s) {
    ll n = s.size();
    auto suffixArr = suffixArrayConstruction(s);
    auto lcp = kasaiLCP(s, suffixArr);
     
    ll totalSubstrings = (n-1) * (n) / 2;
    for (ll i = 1; i < n; ++i) {
        totalSubstrings -= lcp[i];
    }
    cout << totalSubstrings << endl;
   // vector< pair < int, int > > v;
   // for(int i = 0 ; i < n ; i++){
   //    v.push_back({lcp[i],suffixArr[i]});
   // }
   // sort(v.rbegin(),v.rend());
   // int indx = v[0].second;
   // if(v[0].first == 0 ){
   //    cout << "-1" << endl;
   //    return;
   // }
   // for(int i =indx; i < indx+v[0].first ; i++)
   // {
   //    cout<<s[i];
   // }
   // cout << endl;
}

int32_t main() {
    tareq()
    string s;
    cin >> s;
    s+='$';
   countDistinctSubstrings(s) ;
}