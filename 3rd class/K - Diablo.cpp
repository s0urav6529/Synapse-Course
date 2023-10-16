#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=150005;

int BIT[limit];
int a[limit];

void update(int pos,int val){

    while(pos<limit){
        BIT[pos]+=val;
        pos+=(pos & -pos);
    }
    return;
}

int query(int pos){

    int res=0;
    while(pos>0){
        res+=BIT[pos];
        pos-=(pos & -pos);
    }
    return res;
}

int main(){
    fast;

    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++){

        memset(BIT,0,sizeof BIT);
        int n,q,extra;
        cin>>n>>q;

        extra=n;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            update(i,1);
        }
        cout<<"Case "<<t<<":"<<endl;
        while(q--){

            char c;
            int pos,val;
            cin>>c;

            if(c=='c'){
                cin>>pos;

                int l=1,r=extra,ans=-1;

                while(l<=r){

                    int mid=l+(r-l)/2;

                    int val=query(mid);

                    if(val>=pos){
                        if(val==pos) ans=mid;
                        r=mid-1;
                    }
                    else l=mid+1;
                }
                if(ans==-1){
                    cout<<"none"<<endl;
                }
                else {
                    cout<<a[ans]<<endl;
                    update(ans,-1);
                }
            }
            else{
                cin>>val;
                a[++extra]=val;
                update(extra,1);
            }
        }
    }

    return 0;
}


