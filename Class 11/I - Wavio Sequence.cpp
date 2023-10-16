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
#define pyes         cout<<"YES"<<endl
#define pno          cout<<"NO"<<endl
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

void LIS(vector<int>&a,vector<int>&dp){

    vector<int>lis;

    for(int i=0;i<a.size();i++){

        int pos = lower_bound(lis.begin(),lis.end(),a[i])-lis.begin();

        if(pos != lis.size()){
            lis[pos] =  a[i];
        }
        else lis.pb(a[i]);

        dp.pb(pos+1);
    }
}

void run_case(int t){

    int n,ans;
    cin >> n;

    vector<int>a;

    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        a.pb(x);
    }
    vector<int>for_dp,rev_dp;

    LIS(a,for_dp);

    reverse(a.begin(),a.end());

    LIS(a,rev_dp);

//    for(int i=0;i<for_dp.size();i++) cout<<for_dp[i]<<" ";
//    cout<<endl;
//    for(int i=0;i<rev_dp.size();i++) cout<<rev_dp[i]<<" ";
//    cout<<endl;

    ans=1;
    for(int i=0;i<n;i++){
        ans = max(ans , 2* min(for_dp[i],rev_dp[n-1-i])-1);
    }



    cout<<"Case "<<t<<": "<<ans<<endl;
    return;
}

int main(){
    fast;
    //read;
    //out;
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++) run_case(t);
    return 0;
}
