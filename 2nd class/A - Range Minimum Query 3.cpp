#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define N 100005

int main()
{
    fast;
    int q,n;
    cin>>n;

    vector<int>a(n);
    for(int &i:a) cin>>i;

    int k=31-__builtin_clz(n)+1;  ///msb

    int sp[k][n];

    for(int i=0;i<n;i++) sp[0][i]=a[i];


    for(int i=1;i<k;i++){

        for(int j=0;j<n;j++){

            if((j+(1<<i))>n) break;

            sp[i][j]= min(sp[i-1][j],sp[i-1][j+(1<<(i-1))]);
        }
    }

    cin>>q;
    while(q--) {
        int l,r;
        cin>>l>>r;

//        int ans=1e9+1;
//
//
//        for(int i=k-1;i>=0;i--){
//
//            if((1<<i)<=(r-l+1)){
//
//                ans=min(ans,sp[i][l]);
//
//                l+=(1<<i);
//
//            }
//        }

        int msb=31-__builtin_clz(r-l+1);

        cout<<min(sp[msb][l],sp[msb][r-(1<<msb)+1])<<endl;



    }
    return 0;
}


