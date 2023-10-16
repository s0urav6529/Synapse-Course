#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=1e5+5;
#define MaxN 17

int n;
vector<pair<int,int>>adj[limit];
int minval[MaxN+5][limit];
int maxval[MaxN+5][limit];
int LCA[MaxN+5][limit];
int level[limit];

void dfs(int node,int par,int l,int val){

    level[node]=l;
    LCA[0][node]=par;
    minval[0][node]=maxval[0][node]=val;

    for(pair<int,int> ch:adj[node]){

        if(ch.first!=par) dfs(ch.first,node,l+1,ch.second);

    }
}

int get_lca(int a,int b){

    if(level[a]>level[b]) swap(a,b);

    int d=level[b]-level[a];

    while(d>0)
    {
        int j=log2(d);
        b=LCA[j][b];
        d-=(1<<j);
    }

    if(a==b) return a;

    for(int j=MaxN;j>=0;j--){

        if(LCA[j][a]!=-1 && (LCA[j][a]!=LCA[j][b])){
            a=LCA[j][a];
            b=LCA[j][b];
        }
    }
    return LCA[0][a];

}

int main(){
    fast;

    cin>>n;

    for(int i=1;i<n;i++){

        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    for(int j=0;j<=MaxN;j++)
        for(int i=0;i<=n;i++) LCA[j][i]=-1,minval[j][i]=1e7,maxval[j][i]=0;

    dfs(1,-1,0,0);


    for(int j=1;j<=MaxN;j++){

        for(int i=1;i<=n;i++){

            if(LCA[j-1][i]==-1) continue;

            int par=LCA[j-1][i];

            LCA[j][i]=LCA[j-1][par];

            minval[j][i]=min(minval[j-1][i],minval[j-1][par]);

            maxval[j][i]=max(maxval[j-1][i],maxval[j-1][par]);


        }

    }

    int q;
    cin>>q;
    while(q--){

        int u,v;
        cin>>u>>v;
        int lca=get_lca(u,v);
        int mn=1e7,mx=0;

        int dif=level[u]-level[lca];

        int msb=(int)log2(dif);

        for(int i=msb;i>=0;i--){

            if((dif&(1<<i))){

                mn=min(mn,minval[i][u]);
                mx=max(mx,maxval[i][u]);
                u=LCA[i][u];

            }
        }

        dif=level[v]-level[lca];

        msb=(int)log2(dif);

        for(int i=msb;i>=0;i--){

            if((dif&(1<<i))){

                mn=min(mn,minval[i][v]);
                mx=max(mx,maxval[i][v]);
                v=LCA[i][v];

            }
        }
        cout<<mn<<" "<<mx<<endl;

    }

}
