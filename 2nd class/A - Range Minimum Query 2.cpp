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

    int bs=sqrt(n)+1;

    vector<int>a(n),block(bs,1e9+1);

    for(int i=0;i<n;i++) {
        cin>>a[i];
        block[i/bs]=min(block[i/bs],a[i]);
    }


    cin>>q;
    while(q--) {
        int x,y;
        cin>>x>>y;

        int fb=x/bs;
        int lb=y/bs;


        int ans=1e9+1;
        if(fb==lb){

            for(int i=x;i<=y;i++) ans=min(ans,a[i]);

        }
        else{

            for(int i=x;i<((fb+1)*bs);i++) ans=min(ans,a[i]);

            for(int i=fb+1;i<lb;i++) ans=min(ans,block[i]);


            for(int i=lb*bs;i<=y;i++){
                ans=min(ans,a[i]);
            }

        }
        cout<<ans<<endl;


    }
    return 0;
}

