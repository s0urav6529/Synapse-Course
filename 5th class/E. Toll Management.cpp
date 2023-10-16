
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e4+5;

ll n,m,s,t,p;
ll vis[limit],f_dis[limit],r_dis[limit];
vector<pair<ll,ll>>f_adj[limit],r_adj[limit];

void dijkstra(int src,char type){

    memset(vis,0,sizeof vis);

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

    pq.push({0,src});

    if(type=='f') f_dis[src]=0;
    else r_dis[src]=0;

    while(pq.size()>0){

        ll node=pq.top().second;
        ll w=pq.top().first;
        pq.pop();

        if(vis[node]==1) continue;
        vis[node]=1;


        if(type=='f') {

            for(pair<ll,ll> ch:f_adj[node]){

                if(f_dis[ch.first]>w+ch.second){

                    f_dis[ch.first]=w+ch.second;

                    pq.push({f_dis[ch.first],ch.first});
                }
            }
        }
        else {

            for(pair<ll,ll> ch:r_adj[node]){

                if(r_dis[ch.first]>w+ch.second){

                    r_dis[ch.first]=w+ch.second;

                    pq.push({r_dis[ch.first],ch.first});
                }
            }
        }
    }
}


int main(){
    fast;

    int tc=1;
    cin>>tc;
    for(int tt=1;tt<=tc;tt++){

        cin>>n>>m>>s>>t>>p;

        for(int i=1;i<=n;i++){

            f_adj[i].clear();
            r_adj[i].clear();
            f_dis[i]=r_dis[i]=1e10;
        }

        for(int i=0;i<m;i++){

            ll u,v,w;
            cin>>u>>v>>w;

            f_adj[u].push_back({v,w});
            r_adj[v].push_back({u,w});

        }

        dijkstra(s,'f');
        dijkstra(t,'r');

        ll ans=-1;

        for(int node=1;node<=n;node++){

            for(pair<ll,ll> ch:f_adj[node]){

                if(f_dis[node]+r_dis[ch.first]+ch.second<=p)
                    ans=max(ans,ch.second);

            }

        }

        cout<<"Case "<<tt<<": "<<ans<<endl;


    }


    return 0;
}

