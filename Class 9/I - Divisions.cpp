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
const int limit=1e6+5;

bool vis[limit];
vector<int>prime;
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {

    u64 result = 1;
    base %= mod;

    while (e) {
        if (e & 1){
            result = (u128)result * base % mod;
        }
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {

    u64 x = binpower(a, d, n);

    if (x == 1 || x == n - 1){
        return false;
    }
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;

        if (x == n - 1){
            return false;
        }
    }
    return true;
};

bool MillerRabin(u64 n) {
    if (n < 2){
        return false;
    }

    int r = 0;
    u64 d = n - 1;

    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a){
            return true;
        }
        if (check_composite(n, a, d, r)){
            return false;
        }
    }
    return true;
}

void seive(){

    vis[0]=vis[1]=1;

    for(int i=4; i<limit; i+=2) vis[i] = 1;

    for(int i=3; i*i<limit; i+=2){

        if(vis[i]) continue;
        for(int j=i*i; j<limit; j+=2*i) {

            vis[j] = 1;
        }
    }

    prime.pb(2);

    for(int j=3; j<limit; j+=2){
    	if(vis[j]==0) prime.pb(j);
    }
}

void run_case(){
    ll n;
    cin >> n;

    ll divisors = 1;

    for(int i=0; prime[i]*prime[i]<=n && i < prime.size();i++){

        ll div = 1;

        while(n%prime[i]==0){

            n/=prime[i];
            div++;
        }

        divisors *=div;

    }

    if(n>1ll){

        bool ok=false;

        if(MillerRabin(n)){
            /// it is prime
            divisors *=2ll;
            ok=true;
        }
        if(!ok){
            /// consist of p*p means perfect squars
            ll d = sqrt(n);

            if(d*d==n) {
                divisors *=3ll;
                ok=true;
            }

        }
        if(!ok){
            divisors *=4ll;
        }
    }
    cout<< divisors <<endl;
}

int main(){
    fast;
    seive();
    int tc=1;
    //cin>>tc;
    while(tc--) run_case();
    return 0;
}
