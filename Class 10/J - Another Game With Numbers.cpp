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
const int limit=2e5+5;

void run_case(){

    ll n ;
    int k;
    cin >> n >> k;

    ll a[k+5];

    for(int i=0;i<k;i++) cin >> a[i];

    ll ans = 0;

    for(int mask=1;mask<(1<<k);mask++){

        ll N=n,nod=0,lcm=1;
        for(int bit=0;bit<k;bit++){

            if((mask & ( 1 << bit ))){

                nod++;

                if(nod>1){

                    lcm = (lcm * a[bit]) / __gcd(lcm , a[bit]);
                }
                else lcm = a[bit];
            }
        }
       // cout << nod<<" " <<num <<" "<<N/lcm<<endl;
        if(nod&1) ans += N/lcm;
        else ans -= N/lcm;
    }

    cout<<n-ans<<endl;


    return;
}

int main(){
    fast;
    int tc=1;
    //cin>>tc;
    while(tc--) run_case();
    return 0;
}

