#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+9;
int arr[N];
int tree[N]; 

void buildtree(int node, int begin, int end) {
    if(begin == end) { 
        tree[node] = arr[begin];
        return;
    }
    int left = 2 * node, right = 2 * node + 1;
    int mid = (begin + end) / 2;
    buildtree( left, begin, mid);
    buildtree( right, mid + 1, end);
    tree[node] = min(tree[left] , tree[right]);

}

int query(int node, int begin, int end, int i, int j) {
    if(begin > j || end < i) {
        return INT_MAX;
    } 
    if(begin >= i && end <= j) {
        return tree[node];
    } 
    int left = 2 * node, right = 2 * node + 1;
    int mid = (begin + end) / 2; 
    return min(query( left, begin, mid, i, j) , query( right, mid+1, end, i, j));
}

void update(int node, int begin, int end, int i, int x) {
    if(begin > i || end < i) {
        return;
    } 
    if(begin == end && begin == i) {
        tree[node] = x;
        return;
    }
    int left = 2 * node, right = 2 * node + 1;
    int mid = (begin + end) / 2;
    update( left, begin, mid, i, x);
    update( right, mid+1, end, i, x);
    tree[node] = tree[left] + tree[right];
}
int main() {
    int t , cn =0;
    cin >> t;
    while(t--){
    int n , q; cin >> n >> q; 
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    } 
    buildtree( 1, 1, n); 
    cout << "Case " << ++cn << ":" << "\n";
    for(int i = 0; i < q; i++){
        int l , r; cin >> l >> r;
        cout << query( 1, 1, n, l, r) << '\n';
    }
    }
    // cout << query( 1, 1, n, 2, n) << '\n'; 
    // update( 1, 1, n, 4, 5);
    // cout << query( 1, 1, n, 2, n) << '\n';
}