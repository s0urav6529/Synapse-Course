#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e6+5;

void run_case(int t){

    ll n , ans=0;

    cin >> n;
    vector<ll>a(n+1);

    for(int i=0;i<n;i++) cin >> a[i];

    a[n]=1e12;

    sort(a.begin(),a.end());

    for(int i=0;i<n;i++){

        for(int j=i+1;j<n;j++){

            int pos = lower_bound(a.begin(),a.end(),a[i]+a[j])-a.begin()-1;

            ans += (pos-j);

            //cout  << a[i] <<" "<<a[j]<<" " << pos-j<<endl;
        }

    }


    cout<<"Case "<<t<<": "<<ans<<endl;

}

int main(){
    fast;
    ll tc = 1;
    cin >> tc;

    for(int t=1;t<=tc;t++)
        run_case(t);

    return 0;
}



