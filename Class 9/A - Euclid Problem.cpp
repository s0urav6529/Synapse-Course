

#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e6+5;

/// Return (d,x,y) such that ax + by = gcd(a,b) = d
/// It always returns the minimal x & y

tuple<ll, ll, ll> exgcd(ll a , ll b){

    if(b == 0){
        return {a, 1 , 0};
    }
    auto[d, _x, _y] = exgcd(b, a%b);

    ll x = _y;
    ll y = _x -(a/b)*_y;

    return {d, x, y};
}

int main(){
    fast;

    ll a, b;
    while(scanf("%lld %lld",&a,&b)!=EOF){

        auto[d, x , y] = exgcd(a , b);

        printf("%lld %lld %lld\n",x,y,d);
    }

    return 0;
}




