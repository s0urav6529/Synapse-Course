#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e5+5;

ll fact[limit], inv_f[limit];

void precompute(ll n, ll mod) {

    /// first calucalte i^(-1)

    inv_f[0] = inv_f[1] = 1;
    for(int i = 2; i <= n; i++){
        inv_f[i] = mod - 1LL * (mod / i) * inv_f[mod % i] % mod;
    }

    /// Calculate Inverse factorial (i^(-1))!
    for(int i = 2; i <= n; i++){
        inv_f[i] = (1LL * inv_f[i] * inv_f[i-1]) % mod;
    }

    /// Calculate factorial i!
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= n; i++){
        fact[i] = ( 1LL * fact[i-1] * i) % mod;
    }

}

ll nCr(ll n, ll r, ll mod) {
    if(r > n) return 0;
    return (((1LL * fact[n] * inv_f[n-r]) % mod) * inv_f[r]) % mod;
}

///Convert n to some base
vector<ll> toBase(ll n, ll base) {
    vector<ll> digits;
    while(n) {
        digits.push_back(n % base);
        n /= base;
    }
    return digits;
}

ll lucas(ll n, ll r, int mod) {

    if(r > n) return 0;

    /// convert n and r to base mod
    vector<ll> N = toBase(n, mod);
    vector<ll> R = toBase(r, mod);

    /// make lengths equal by filling leading digits of R with zeros
    while(R.size() < N.size()){
        R.push_back(0);
    }

    ///Calculate answer
    ll ans = 1;
    for(int i = 0; i < N.size(); i++) {
        ans = (1LL * ans * nCr(N[i], R[i], mod)) % mod;
    }
    return ans;
}

int main() {
    ll tc=1;
    cin >> tc;
    while(tc--){
        ll n, r, p;
        cin >> n >> r >> p;
        precompute(p-1, p);
        cout << lucas(n, r, p) << endl;

    }

}




