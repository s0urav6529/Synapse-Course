#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e2+5;

vector<pair<ll,ll>>adj[limit];

ll f_dis[limit],r_dis[limit],vis[limit];

void dijkstra(ll src,char type){

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

        for(pair<ll,ll>ch:adj[node]){

            if(type=='f'){

                if(f_dis[ch.first]>ch.second+w){

                    f_dis[ch.first]=ch.second+w;

                    pq.push({f_dis[ch.first],ch.first});

                }
            }
            else{

                if(r_dis[ch.first]>ch.second+w){

                    r_dis[ch.first]=ch.second+w;

                    pq.push({r_dis[ch.first],ch.first});
                }
            }
        }
    }
}


int main(){
    fast;
    ll tc=1;
    cin>>tc;
    for(int tt=1;tt<=tc;tt++){

        ll n,m,s,d;
        cin>>n>>m;

        for(int i=1;i<=n;i++) {
            adj[i].clear();
            f_dis[i]=r_dis[i]=200;
        }


        for(int i=0;i<m;i++) {

            ll u,v;
            cin>>u>>v;
            v++,u++;
            adj[v].push_back({u,1});
            adj[u].push_back({v,1});

        }
        cin>>s>>d;
        s++,d++;

        dijkstra(s,'f');
        dijkstra(d,'r');

        ll max_dis=0;

        for(int i=1;i<=n;i++){
            max_dis=max(max_dis,f_dis[i]+r_dis[i]);
        }

        cout<<"Case "<<tt<<": "<<max_dis<<endl;

    }
    return 0;
}


