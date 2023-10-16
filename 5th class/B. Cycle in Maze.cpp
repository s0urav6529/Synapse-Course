#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e3+5;


ll xx[]={1,0,0,-1};
ll yy[]={0,-1,1,0};
char Move[]={'D','L','R','U'};

char maze[limit][limit];
ll dis[limit][limit];
ll n,m,k;

bool is_valid(ll x,ll y){

    if(x>0 && x<=n && y>0 && y<=m && maze[x][y]!='*')  return true;
    return false;

}

void dijkstra(ll sx,ll sy){

    memset(dis,-1,sizeof dis);

    queue<pair<int,int>>p;

    dis[sx][sy]=0;
    p.push({sx,sy});

    while(p.size()>0){

        sx=p.front().first;

        sy=p.front().second;

        p.pop();

        for(int i=0;i<4;i++){

            ll nx=sx+xx[i];

            ll ny=sy+yy[i];

            if(is_valid(nx,ny) && dis[nx][ny]==-1){

                dis[nx][ny]=dis[sx][sy]+1;
                p.push({nx,ny});
            }
        }

    }
}


int main(){
    fast;

    cin>>n>>m>>k;

    ll sx,sy;
    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++) {

            cin>>maze[i][j];

            if(maze[i][j]=='X') sx=i,sy=j;

        }

    }

    if(k&1) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    dijkstra(sx,sy);


//    for(int i=1;i<=n;i++){
//
//        for(int j=1;j<=m;j++) {
//
//           cout<<dis[i][j]<<" ";
//        }
//        cout<<endl;
//
//    }


    string path="";

    while(k){

        bool parbo=false;

        for(int i=0;i<4;i++){

            ll nx=sx+xx[i];
            ll ny=sy+yy[i];

            if(is_valid(nx,ny) && dis[nx][ny]<=k ){

                path+=Move[i];
                parbo=true;
                sx=nx,sy=ny;
                k--;
                break;
            }
        }

        if(parbo==false){

            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<path;
    return 0;
}

