
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
const int limit=22;

int adj[limit][limit];
ll dp[limit][1<<limit];
int n;

ll rec(int man,int mask){

    if(man == n){

        if(mask == 0) /// all are matched each other
            return 1;
        return 0;

    }

    ll &ans = dp[man][mask];
    if(ans != -1) return ans;

    ll res = 0;

    for(int woman = 0;woman<n;woman++){

        if(adj[man][woman] && (mask &(1<<woman))){

            res = (res + rec(man+1,mask^(1<<woman))) % MOD;

        }

    }
    return ans=res;



}

void run_case(int t){

    memset(dp,-1,sizeof dp);

    cin >> n;


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> adj[i][j];
    }

    cout<< rec(0,(1<<n)-1) <<endl;


    return;
}

int main(){
    fast;
    int tc=1;
    //cin>>tc;
    for(int t=1;t<=tc;t++) run_case(t);
    return 0;
}
