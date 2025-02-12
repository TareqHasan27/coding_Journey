#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+1;
bool vis[N];
vector<int>g[N]; 
vector<int>ans;
bool dfsvis[N];
bool f = false;
void dfs(int u) {
    vis[u]=true;
    dfsvis[u]=true;
    for(auto v: g[u]) {
        if(!vis[v]) {
            dfs(v);             
        }
        if(vis[v] && dfsvis[v]){                                
          f =true;  /* check cycle in graph..if a node is visited 
                      and the dfs call on the node is also true
                      then it is a cyclic graph..   
                    */
        }
    } 
    ans.push_back(u); /*when node have no child then take the node
                       and make the dfs call false*/
    dfsvis[u]=false;
}


int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
    //directed graph input
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++) {
       int u, v;
       cin >> u >> v;
       g[u].push_back(v);
       
    }
    //dfs call on every node
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);           
        }         
    } 
    // for(auto u : ans){
    //   cout<<u<<" ";
    // }

    reverse(ans.begin(),ans.end());
    if(!f){
    for(auto u : ans){
      cout<<u<<" ";
    } 
    }
    else{
      cout<<"IMPOSSIBLE"<<endl;
    }
       
}