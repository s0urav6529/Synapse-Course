#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define reset(a,b)   memset(a, (b), sizeof(a))
#define sortv(k)     sort(k.begin(),k.end())
#define sortg(k)     sort(k.begin(),k.end(),greater<int>())
#define uniq(vec)    vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))
#define rev(k)       reverse(k.begin(),k.end())
#define umin(a,b)    a=min(a,b)
#define umax(a,b)    a=max(a,b)
#define min3(a,b,c)  min(a, min(b,c))
#define pyes         cout<<"YES"<<endl
#define pno          cout<<"NO"<<endl
#define pf(a)        cout<<a<<endl
#define p2f(a,b)     cout<<a<<" "<<b<<endl
#define p3f(a,b,c)  cout<<a<<" "<<b<<" "<<c<<endl
#define p4f(a,b,c)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define ff first
#define ss second
#define pb push_back
#define pi acos(-1.0)
//cin.get();
typedef long long int ll;
//typedef unsigned long long int llu;
//constexpr llu Mx=18446744073709551615;
constexpr ll MOD=1000000007;
const int limit=1e6+5;

ll a[limit] ,subsum[limit];
vector<int>adj[limit];

ll total , cost , ans = 0;

void subsum_dfs(int node,int par){

    subsum[node] = a[node];

    for(int child:adj[node]){

        if(child != par){

            subsum_dfs(child,node);

            subsum[node] += subsum[child];
        }
    }
}

void dfs(int node,int par,ll len){

    cost += len*a[node];

    for(int child:adj[node]){

        if(child != par){


            dfs(child,node,len+1);

        }
    }
}

void dfs2(int node,int par, ll cost){

    ll my_cost;

    if(node == 1){
        ans = cost;
        my_cost = cost;
    }
    else{

        my_cost = cost - subsum[node] + (total-subsum[node]);

        ans = max( ans , my_cost);
    }

    for(int child:adj[node]){

        if(child != par){

            dfs2(child , node, my_cost);

        }

    }

}


void run_case(int t){

    int n;
    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >> a[i];
        total += a[i];
    }

    for(int i=1;i<n;i++){

        int u,v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);

    }

    subsum_dfs(1,-1);

    dfs(1,-1,0ll);

    dfs2(1,-1,cost);

    cout<<ans<<endl;

    return;
}

int main(){
    fast;
    int tc=1;
    //cin>>tc;
    for(int t=1;t<=tc;t++) run_case(t);
    return 0;
}

