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
constexpr ll MOD=998244353;
const int limit=17;

ll dp[1<<limit];

void run_case(int t){

    int n;
    cin >> n;

    ll a[n+1][n+1];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cin >> a[i][j];
        }
    }


    /// precalculating dp for every mask value
    for(int mask = 0 ; mask <(1<<n); mask++){

        for(int i=0;i<n;i++){

            if(mask & (1<<i)){

                for(int j=i+1;j<n;j++){

                    if(mask & (1<<j)){

                        dp[mask] += a[i][j];
                    }

                }
            }
        }

    }

    /// Iterating over every mask
    for(int mask = 0;mask < (1<<n); mask++){

        /// calculating answer for every musk's submask
        for(int i = mask ; i>0 ; i = (i-1)&mask){

            int j = mask^i;

            dp[mask] = max(dp[mask],dp[i]+dp[j]);

        }

    }

    cout<<dp[(1<<n)-1]<<endl;

    return;
}

int main(){
    fast;
    int tc=1;
    //cin>>tc;
    for(int t=1;t<=tc;t++) run_case(t);
    return 0;
}
