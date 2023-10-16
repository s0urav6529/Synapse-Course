#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e6+5;

bool no_solution = false;

/// Return (d,x,y) such that ax + by = gcd(a,b) = d

tuple<ll, ll, ll> exgcd(ll a , ll b){

    if(b == 0){
        return {a, 1 , 0};
    }
    auto[d, _x, _y] = exgcd(b, a%b);

    ll x = _y;
    ll y = _x -(a/b)*_y;

    return {d, x, y};
}

/// If (c%d>0) no solution otherwise solution exits

tuple<ll,ll> diaphontine(ll a, ll b, ll c){

    auto[d, x , y] = exgcd(a , b);

    if(c % d){
        no_solution=true;
        return {-1,-1}; /// Invalid returns
    }
    else {
        ll k = c/d;
        return {x*k , y*k};
    }
}

int main(){

    fast;

    ll tc=1, a, b ,c;
    cin >> tc;
    for(int t=1;t<=tc;t++){

        no_solution=false;

        cin >> a >> b >> c;

        auto[x,y] = diaphontine(a, b , c);

        if(no_solution){

            cout<<"Case "<<t<<": No"<<endl;
        }
        else cout<<"Case "<<t<<": Yes"<<endl;
    }



    return 0;
}



