#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=1e5+5;

struct info{
    ll prop,sum;
}st[4*limit];


void segment_tree(int node,ll b,ll e){

    if(b==e){
        st[node].sum=0;
        st[node].prop=0;
        return;
    }
    int mid=(b+e)/2;

    segment_tree(node*2,b,mid);
    segment_tree(node*2+1,mid+1,e);

    st[node].sum=st[node*2].sum+st[node*2+1].sum;
    st[node].prop=0;
}

void update(int node,ll b,ll e,ll l,ll r,ll x){

    if(e<l || b>r) return;

    if(b>=l && e<=r){
        st[node].sum+=((e-b+1)*x);
        st[node].prop+=x;
        return;
    }
    int mid=(b+e)/2;

    update(node*2,b,mid,l,r,x);
    update(node*2+1,mid+1,e,l,r,x);
    st[node].sum=st[node*2].sum+st[node*2+1].sum+(e-b+1)*st[node].prop;

}

ll query(int node,ll b,ll e,ll l,ll r,ll carry){

    if(e<l || b>r) return 0;

    if(b>=l && e<=r){
        return st[node].sum+carry*(e-b+1);
    }

    int mid=(b+e)/2;

    ll q1=query(node*2,b,mid,l,r,carry+st[node].prop);
    ll q2=query(node*2+1,mid+1,e,l,r,carry+st[node].prop);
    return q1+q2;
}


int main(){
    fast;
    int tc=1;
    //scanf("%d",&tc);
    cin>>tc;
    for(int t=1;t<=tc;t++){
        int n,q;
        //scanf("%d%d",&n,&q);
        cin>>n>>q;
        segment_tree(1,1,n);
        //printf("Case %d:\n",t);
        cout<<"Case "<<t<<":"<<endl;
        while(q--){

            ll type,l,r,v;
            cin>>type;
            if(!type){
                cin>>l>>r>>v;l++,r++;
                update(1,1,n,l,r,v);

            }
            else{
                cin>>l>>r;l++,r++;
                ll ans=query(1,1,n,l,r,0ll);
                //printf("%d\n",ans);
                cout<<ans<<endl;
            }

        }
    }
    return 0;
}


