#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+1;
bool vis[N];
vector<int>g[N];
vector<int>rgraph[N]; 
vector<int>ans;
bool f = false;
void dfs1(int u) {
    vis[u]=true;
    for(auto v: g[u]) {
        if(!vis[v]) {
            dfs1(v);             
        }
    } 
    ans.push_back(u); 
}

void dfs2(int u) {
    vis[u]=true;   
    for(auto v: rgraph[u]) {
        if(!vis[v]) {
            dfs2(v);             
        }
    }    
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
       rgraph[v].push_back(u);
    }
   
    //dfs call on every node
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs1(i);           
        }         
    } 
    /*
    traverse  the graph for dfs tree and store it in stack.
    reverse graph also use dfs if any node can't visit all
    of nodes then scc compnenets get increase;
    */ 
    
    for(int i =1;i<=n;i++){
        vis[i]=false;
    } 

    vector<int>scc;
    reverse(ans.begin(),ans.end());
    // while (!ans.empty()) {
    // int v = ans.top();
    // ans.pop();
    // cout<<v<<" ";
    // if (!vis[v]) {
    //   scc.push_back(v);
    //   dfs2(v);          
    // }
    // }     
    // cout<<endl;
    for(auto u : ans){
        if(!vis[u]) {
            scc.push_back(u);
            dfs2(u);
        }
    }
    cout << scc.size() << endl;
    if(scc.size()>1){
      cout<<"NO"<<endl;
      cout<<scc[1]<<" "<<scc[0]<<endl;
    }
    else{
      cout<<"YES"<<endl;
    }
       
}