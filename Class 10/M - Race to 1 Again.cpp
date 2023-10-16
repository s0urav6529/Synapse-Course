
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
constexpr ll MOD=1000000007;
const int limit=1e5+5;

long double Expectation[limit];


void precompute(){

    for(int i=2;i<limit;i++){

        bool ok=true;
        double sum = 1 ;
        int div = 1;

        for(int j=2;j*j<=i;j++){

            if(i%j==0){

                div++;
                sum += Expectation[j];

                if((i/j) != j){
                    sum += Expectation[i/j];
                    div++;
                }
                ok=false;
            }
        }
        if(ok) { /// Prime
            Expectation[i] = 2;
        }
        else{
            Expectation[i] = (sum*1.0/div) + 1.0;
        }
    }

}


void run_case(int t){

    ll n;
    cin >> n;
    cout <<"Case "<<t<<": "<<fixed<<setprecision(9) << Expectation[n] <<endl;
    return;
}

int main(){
    fast;
    precompute();
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++) run_case(t);
    return 0;
}
