
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e5+5;

vector<int>adj[limit];
vector<int>transpose[limit];
vector<int>condense[limit];
vector<int>con_group(limit);
vector<bool>vis(limit,false);
vector<int>out;
vector<int>coins(limit);
vector<ll>total_coins(limit,0);

ll ans[limit];

int c;

void dfs_out(int node){

    vis[node]=true;

    for(int ch:adj[node]){

        if(vis[ch]==false)
            dfs_out(ch);

    }
    out.push_back(node);

}

void dfs(int node){

    vis[node]=true;

    for(int ch:transpose[node]){

        if(vis[ch]==false)
            dfs(ch);

    }
    con_group[node]=c;
    total_coins[c] += coins[node];
}

ll tree_dp(int node,int par){

    ll temp=total_coins[node];

    if(vis[node]) return ans[node];

    for(int ch:condense[node]){

        if(ch!=par){
            tree_dp(ch,node);

            temp=max(temp,total_coins[node]+ans[ch]);
        }
    }
    vis[node]=true;
    return ans[node]=temp;
}


int main(){
    fast;
    int n,e;
    cin >> n >> e;

    for(int i=1;i<=n;i++) cin >> coins[i];

    for(int i=1;i<=e;i++){
        int x,y;

        cin >> x >> y;

        if(x==y) continue;

        adj[x].push_back(y);

        transpose[y].push_back(x);
    }

    for(int i=1;i<=n;i++){

        if(vis[i]==false)
            dfs_out(i);
    }

    for(int i=1;i<=n;i++)
        vis[i]=false;

    c=1;
    for(int i=1;i<=n;i++){

        if(vis[out[n-i]]==false){
            dfs(out[n-i]);
            c++;
        }
    }

    map<pair<int,int>,bool>mp;

    for(int i=1;i<=n;i++){

        for(int ch:adj[i]){

            int par=i,child=ch;

            if(par<child) swap(par,child);

            if(con_group[par]!=con_group[child] && mp.find({par,child})==mp.end()) {

                condense[con_group[i]].push_back(con_group[ch]);
                mp[{par,child}]=true;
            }
        }
    }

    for(int i=1;i<=n;i++)
        vis[i]=false;

    for(int i=1;i<c;i++) if(vis[i]==false) tree_dp(i,-1);

    ll ct=0;

    for(int i=1;i<c;i++) ct=max(ct,ans[i]);
    cout<<ct<<endl;

    return 0;
}


