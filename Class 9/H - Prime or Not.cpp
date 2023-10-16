
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
const int limit=2e5+5;
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

void run_case(){

    ll n;
    cin >> n;
    if(MillerRabin(n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return;
}

int main(){
    fast;
    ll tc=1;
    cin>>tc;
    while(tc--) run_case();
    return 0;
}
