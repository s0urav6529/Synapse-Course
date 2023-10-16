#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define reset(a,b)   memset(a, (b), sizeof(a))
#define sortv(k)     sort(k.begin(),k.end())
#define sortg(k)     sort(k.begin(),k.end(),greater<int>())
#define rev(k)       reverse(k.begin(),k.end())
#define umin(a,b)    a=min(a,b)
#define umax(a,b)    a=max(a,b)
#define min3(a,b,c)  min(a, min(b,c))
#define pyes         cout<<"Yes"<<endl
#define pno          cout<<"No"<<endl
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
const int limit=1e4+5;

ll fact[limit], inv_f[limit];

void precompute() {

  inv_f[0] = inv_f[1] = 1;
  for(int i = 2; i < limit; i++){
       inv_f[i] = MOD - 1LL * (MOD / i) * inv_f[MOD % i] % MOD;
  }

  fact[0] = fact[1] = 1;
  for(int i = 2; i < limit; i++){
       fact[i] = (1LL * fact[i-1] * i) % MOD;
       inv_f[i] = (1LL * inv_f[i] * inv_f[i-1]) % MOD;
  }

}

ll nCr(ll n, ll r) {
    if(r > n) return 0;
    return (((1LL * fact[n] * inv_f[n-r]) % MOD) * inv_f[r]) % MOD;
}


int main(){
    fast;
    precompute();
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++) {

        ll n , k;
        cin >> n >> k;

        ll a[n+5];

        for(int i=1;i<=n;i++) cin >> a[i];

        sort(a+1,a+n+1);
        ll ans = 0;
        for(int i=n;i>0;i--){

            ll temp = nCr(i-1,k-1);

            temp = ( temp * a[i] ) % MOD;

            ans = (ans + temp) % MOD;


        }

        cout<<"Case #"<<t<<": "<<ans <<endl;



    }
    return 0;
}

