#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e4+5;
const int MaxN=17;

vector<pair<int,ll>>adj[limit];

ll val[limit];
int level[limit];
int LCA[limit][MaxN+5];

void dfs(int node,int par,int l,ll value){

    level[node]=l;
    val[node]=value;
    LCA[node][0]=par;

    for(pair<int,int>ch:adj[node])
        if(ch.first!=par)
            dfs(ch.first,node,l+1,val[node]+ch.second);

}


int get_lca(int a,int b){

    if(level[a]>level[b]) swap(a,b);
    int d=level[b]-level[a];

    while(d>0){

        int i=log2(d);
        b=LCA[b][i];
        d-=(1<<i);
    }
    if(a==b) return a;

    for(int i=MaxN;i>-1;i--) {

        if(LCA[a][i]!=-1 && (LCA[a][i]!=LCA[b][i])) {

            a=LCA[a][i],b=LCA[b][i];
        }
    }
    return LCA[a][0];
}


int main(){
    fast;
    int tc;
    cin>>tc;
    while(tc--){
        int n,q;
        cin>>n;

        for(int i=1;i<=n;i++)
            adj[i].clear(),val[i]=0,level[i]=0;

        for(int i=1;i<n;i++){

            int u,v,w;
            cin>>u>>v>>w;

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});

        }

        memset(LCA,-1,sizeof(LCA));

        dfs(1,-1,0,0);

        for(int i=1;i<=MaxN;i++) {

            for(int j=1;j<=n;j++) {

                if(LCA[j][i-1]!=-1) {

                    int p=LCA[j][i-1];
                    LCA[j][i]=LCA[p][i-1];
                }
            }
        }

        while(true){

            string s;
            cin>>s;
            if(s=="DIST"){
                int a,b;
                cin>>a>>b;

                int lca=get_lca(a,b);

                ll till_lca=val[lca];
                ll till_a=val[a];
                ll till_b=val[b];

                ll ans=till_a+till_b-(2*till_lca);

                cout<<ans<<endl;
            }
            else if(s=="KTH"){
                int a,b,k;
                cin>>a>>b>>k;
                k--;

                int lca=get_lca(a,b);

                int a_level=level[a];

                int b_level=level[b];

                int lca_level=level[lca];

                int dis=a_level-lca_level;

                if(dis>=k){

                    int msb=(int)log2(k);

                    int node=a;

                    for(int i=msb;i>=0;i--){

                        if((k&(1<<i)))
                            node=LCA[node][i];

                    }
                    cout<<node<<endl;

                }
                else{


                    dis=(b_level-lca_level)-(k-dis);


                    int msb=(int)log2(dis);

                    int node=b;

                    for(int i=msb;i>=0;i--){

                        if((dis&(1<<i)))
                            node=LCA[node][i];

                    }
                    cout<<node<<endl;

                }
            }
            else{
                cout<<endl;
                break;
            }
        }
    }

    return 0;
}






