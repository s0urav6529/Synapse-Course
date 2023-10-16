#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e3+5;

char Map[limit][limit];
ll dis[limit][limit];
ll xx[]={0,-1,0,1};
ll yy[]={-1,0,1,0};
ll R,C;


bool is_valid(ll x,ll y){

    if((x>=1 && x<=R) && (y>=1 && y<=C)) return true;

    return false;

}


void bfs01(ll r,ll c){

    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++) dis[i][j]=1e9;


    deque<pair<ll,ll>>dq;

    dq.push_back({r,c});

    dis[r][c]=0;

    while(dq.size()>0){

        ll x=dq.front().first;
        ll y=dq.front().second;

        dq.pop_front();

        for(int i=0;i<4;i++){

            ll nx=x+xx[i],ny=y+yy[i];

            if(is_valid(nx,ny)){

                ll cost=0;

                if(Map[x][y]!=Map[nx][ny]) cost=1;

                if(dis[nx][ny]>dis[x][y]+cost){

                    dis[nx][ny]=dis[x][y]+cost;

                    if(cost==1) dq.push_back({nx,ny});

                    else dq.push_front({nx,ny});

                }

            }

        }

    }
}


int main(){
    fast;
    ll tc=1;
    cin>>tc;

    while(tc--){

        cin>>R>>C;

        for(int i=1;i<=R;i++){
            string s;
            cin>>s;
            for(int j=1;j<=C;j++)
                Map[i][j]=s[j-1];

        }

        bfs01(1,1);

        cout<<dis[R][C]<<endl;


    }

    return 0;
}


