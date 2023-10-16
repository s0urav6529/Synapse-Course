#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e6+5;



int main(){
    fast;
    int n,m,q;
    cin>>n>>m>>q;

    ll dp[n+5][n+5];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(i==j) dp[i][j]=0;
            else dp[i][j]=1e18;
    }

    for(int i=0;i<m;i++){

        ll u,v,w;
        cin>>u>>v>>w;

        dp[u][v]=min(dp[u][v],w);
        dp[v][u]=min(dp[v][u],w);

    }

    for(int mid=1;mid<=n;mid++){

        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++) {

                dp[i][j] = min ( dp[i][j] ,dp[i][mid] + dp[mid][j] );

            }
        }
    }

    while(q--){

        ll u,v;
        cin>>u>>v;

        (dp[u][v]>=1e18?cout<<-1<<endl:cout<<dp[u][v]<<endl);

    }

    return 0;
}


