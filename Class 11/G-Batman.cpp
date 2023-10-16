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
const int limit=55;

string s1,s2,s3;

int dp[limit][limit][limit];
int as,bs,cs;

int rec(int a,int b,int c){

    if(a>= as || b>=bs || c>=cs) return 0;

    int &ans = dp[a][b][c];

    if(ans!=-1) return ans;


    if(s1[a] == s2[b] && s2[b] == s3[c]) return ans = 1+rec(a+1,b+1,c+1);

    int res = 0;

    res = max( res , rec(a,b,c+1));
    res = max( res , rec(a,b+1,c+1));
    res = max( res , rec(a,b+1,c));
    res = max( res , rec(a+1,b,c));
    res = max( res , rec(a+1,b,c+1));
    res = max( res , rec(a+1,b+1,c));
    res = max( res , rec(a+1,b+1,c+1));

    return ans=res;

}


void run_case(int t){

    cin >> s1 >> s2 >> s3;

    as=s1.size();
    bs=s2.size();
    cs=s3.size();

    memset(dp,-1,sizeof dp);

    cout<<"Case "<<t<<": "<<rec(0,0,0)<<endl;

    return;
}

int main(){
    fast;
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++) run_case(t);
    return 0;
}
