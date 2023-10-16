


/// Find A^B mod P

/// Where A<=1e9 , B = 5000 digits && P=1e9+7.

/// Here  since B is large and cannot fit in ll so we can represents B = (p-1)*q + r

/// So A^(p-1)*q . A^r mod P ..... (1)

/// From farmets little theorem  A^(p-1) = 1 mod P ; Now putting the value in the equation (1) we get

/// SO  1.A^r mod p

/// r = reminder of B%(p-1)

/// Binary exponetiontion of (A^r)%P is the answer


#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e6+5;

ll Mod(ll x){
    return ((x%MOD + MOD)%MOD);
}

ll mulmod(ll a,ll b){
    return Mod(Mod(a)*Mod(b));
}

ll Binary_expo(ll a,ll p){

	ll res=1;
	while(p){

		if(p & 1)
		res=mulmod(res,a);
		p/=2;
		a=mulmod(a,a);
	}
	return res%MOD;
}

int main(){
    fast;
    ll A ;
    string B;
    cin >> A >> B;

    ll r = 0;

    ll P = MOD-1;

    for(int i=0;i<B.size();i++){

        r = r*10ll+(B[i]-'0');

        if(r>=P) r=r%P;
    }

    cout<<Binary_expo(A,r) <<endl;

    return 0;
}


