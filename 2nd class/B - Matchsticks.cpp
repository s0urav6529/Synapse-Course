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

    vector<double>a(n);
    for(double &i:a) cin>>i;

    int k=31-__builtin_clz(n)+1;  ///msb

    double min_sp[k][n],max_sp[k][n];

    for(int i=0;i<n;i++) min_sp[0][i]=max_sp[0][i]=a[i];


    for(int i=1;i<k;i++){

        for(int j=0;j<n;j++){

            if((j+(1<<i))>n) break;

            min_sp[i][j]= min(min_sp[i-1][j],min_sp[i-1][j+(1<<(i-1))]);

            max_sp[i][j]= max(max_sp[i-1][j],max_sp[i-1][j+(1<<(i-1))]);
        }
    }

    cin>>q;
    while(q--) {
        int l,r;
        cin>>l>>r;

        int msb=31-__builtin_clz(r-l+1);

        double ans=min(min_sp[msb][l],min_sp[msb][r-(1<<msb)+1]);

        double Range_max=max(max_sp[msb][l],max_sp[msb][r-(1<<msb)+1]);

        double whole_max=0;

        if(l-1>=0) {
            int ll=0;
            int rr=l-1;

            msb=31-__builtin_clz(rr-ll+1);

            whole_max=max(whole_max,max(max_sp[msb][0],max_sp[msb][rr-(1<<msb)+1]));
        }

        if(r+1<n){

            int ll=r+1;
            int rr=n-1;

            msb=31-__builtin_clz(rr-ll+1);

            whole_max=max(whole_max,max(max_sp[msb][ll],max_sp[msb][rr-(1<<msb)+1]));
        }



        double xx=((Range_max-ans))/2.0;

        ans+=max(xx,whole_max);

        cout<<fixed<<setprecision(1)<<ans<<endl;



    }
    return 0;
}


