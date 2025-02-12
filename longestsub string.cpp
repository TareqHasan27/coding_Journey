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

int32_t main()
{
    faster()
    int n ; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int d = v[1] - v[0] , ans = 0;
    cout << ans << " " << d << endl;
    int cur = 0 , i , cnt = 0;
    for( i = 2; i < n;)
    {   
        cout << ans << " " << d << " " << i  << " " << cur << endl;
        if(v[i] - v[i-1] == d) {
            i++;
        }
        else {
            d = v[i] - v[i - 1];
            ans += ((i - cur + 1) * ((i - cur + 2)) / 2);
            cur = i - 1;
            cnt ++;
            i++;
        }
        
        
    }
    cout << ans << " " << d << " " << i  << " " << cur << endl;
    ans += ((i - cur) * ((i - cur + 1)) / 2);
    cout << ans - cnt << endl;
   

}