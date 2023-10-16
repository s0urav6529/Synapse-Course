
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
constexpr ll MOD=100000007;
const int limit=1e6+5;

vector<ll>perfect_power;
ll fact[limit],mod_inv[limit],inv_f[limit]  ;

void precompute(){

    for(ll i=2;i<limit;i++){

        ll j = i*i;

        while(j<=(ll)1e10){
            perfect_power.pb(j);
            j*=i;
        }

    }
    perfect_power.pb((ll)1e11);

    sortv(perfect_power);
    uniq(perfect_power);
}

void precompute2() {

  mod_inv[0] = mod_inv[1] = 1;
  for(int i = 2; i < limit; i++){
       mod_inv[i] = MOD - 1LL * (MOD / i) * mod_inv[MOD % i] % MOD;
  }

  fact[0] = fact[1] = 1;
  inv_f[0] = inv_f[1] = 1;

  for(int i = 2; i < limit; i++){
       fact[i] = (1LL * fact[i-1] * i) % MOD;
       inv_f[i] = (1LL * mod_inv[i] * inv_f[i-1]) % MOD;
  }

}

ll nCr(ll n, ll r) {
    if(r > n) return 0;
    return (((1LL * fact[n] * inv_f[n-r]) % MOD) * inv_f[r]) % MOD;
}


ll catalan_number(ll n){

    return (mod_inv[n+1] * nCr(2*n , n)) % MOD;

}



void run_case(int t){

    ll a ,  b;
    cin >> a >> b;

    ll n = upper_bound(perfect_power.begin(),perfect_power.end(),b) - lower_bound(perfect_power.begin(),perfect_power.end(),a);

    cout <<"Case "<<t<<": ";
    if(n) cout <<catalan_number(n) <<endl;
    else cout<<0<<endl;


    return;
}

int main(){
    fast;
    precompute();
    precompute2();
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++) run_case(t);
    return 0;
}
