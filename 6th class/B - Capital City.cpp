
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
vector<int>out;
vector<bool>vis(limit,false);
vector<int>con_group(limit);

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
}

int main(){
    fast;
    int n,e;
    cin >> n >> e;

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

    int capital_candidate=0,id;

    for(int i=1;i<c;i++){

        if(condense[i].size()==0) capital_candidate++,id=i;


    }

    if(capital_candidate>1) {
        cout<<0<<endl;
    }
    else{
        int ct=0;
        for(int i=1;i<=n;i++)
            if(con_group[i]==id)
                ct++;

        cout<<ct<<endl;

        for(int i=1;i<=n;i++)
            if(con_group[i]==id)
                cout<<i<<" ";

        cout<<endl;

    }
    return 0;
}



