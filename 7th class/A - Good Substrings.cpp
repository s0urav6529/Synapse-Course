
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1600;

ll Get(char c){
    return (c-'a'+1);
}


int main(){
    fast;
    string s, g;

    ll n, k;

    cin >> s >> g >> k;

    n=s.size();

    set<pair<ll,ll>>st;

    for(int i=0;i<n;i++){

        ll bad=0 , p1 = 29 , p2 = 31, cur_p1 = 1, cur_p2 = 1;

        ll h1 = 0,h2 = 0;

        for(int j=i;j<n;j++){

            if(g[s[j]-'a']=='0') bad++;

            if(bad > k) break;

            h1 = ( h1 + (Get(s[j]) * cur_p1) % MOD ) % MOD;

            h2 = ( h2 + (Get(s[j]) * cur_p2) % MOD ) % MOD;

            st.insert({h1,h2});

            cur_p1 = (cur_p1 * p1) % MOD;

            cur_p2 = (cur_p2 * p2) %MOD;

        }

    }


    cout<<st.size()<<endl;

    return 0;
}


