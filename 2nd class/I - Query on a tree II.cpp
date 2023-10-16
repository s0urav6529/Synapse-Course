#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e4+5;
const int MaxN=17;

vector<pair<int,int>>adj[limit];
int in[limit],out[limit];

ll val[limit],tr[8*limit],ft[2*limit];
int level[limit];
int LCA[limit][MaxN+5];

int timer=1;

void Euler_tour(int node,int par,int l,int value){

    level[node]=l;
    val[node]=value;
    LCA[node][0]=par;

    in[node]=timer;
    ft[timer]=val[node];
    timer++;

    for(pair<int,int>ch:adj[node]){

        if(ch.first!=par) Euler_tour(ch.first,node,l+1,ch.second);
    }

    out[node]=timer;
    ft[timer]=-val[node];
    timer++;
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


void built_tree(int node,int s,int e){

    if(s==e) {
        tr[node]=ft[s];
        return;
    }

    int mid=(s+e)/2;

    built_tree(2*node,s,mid);
    built_tree(2*node+1,mid+1,e);
    tr[node]=tr[2*node]+tr[2*node+1];
}

ll Subtree_sum(int node,int s,int e,int l,int r){

    if(e<l || s>r)
        return 0;

    if(s>=l && e<=r)
        return tr[node];

    int mid=(s+e)/2;

    ll Left=Subtree_sum(2*node,s,mid,l,r);
    ll Right=Subtree_sum(2*node+1,mid+1,e,l,r);

    return Left+Right;
}


int main(){
    fast;
    int tc;
    cin>>tc;
    while(tc--){
        int n,q;
        cin>>n;

        for(int i=1;i<=n;i++)
            adj[i].clear(),val[i]=0,in[i]=0,out[i]=0,level[i]=0;

        for(int i=1;i<n;i++){

            int u,v,w;
            cin>>u>>v>>w;

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});

        }

        memset(LCA,-1,sizeof(LCA));

        Euler_tour(1,-1,0,0);

        for(int i=1;i<=MaxN;i++) {

            for(int j=1;j<=n;j++) {

                if(LCA[j][i-1]!=-1) {

                    int p=LCA[j][i-1];
                    LCA[j][i]=LCA[p][i-1];
                }
            }
        }


        built_tree(1,1,2*n);

        while(true){

            string s;
            cin>>s;
            if(s=="DIST"){
                int a,b;
                cin>>a>>b;

                int lca=get_lca(a,b);

                ll root_to_lca=Subtree_sum(1,1,2*n,in[1],in[lca]);
                ll root_to_a = Subtree_sum(1,1,2*n,in[1],in[a]);
                ll root_to_b = Subtree_sum(1,1,2*n,in[1],in[b]);

                ll ans=root_to_a + root_to_b-(2*root_to_lca);

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
        timer=1;
    }

    return 0;
}





