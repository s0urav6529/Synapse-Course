#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long int ll;
const int limit=1e5+5;

ll a[limit];
ll st[limit<<2],lazy[limit<<2];

void built_tree(int node,int b,int e){

    lazy[node]=(1ll<<31)-1;

    if(b==e){
        st[node]=a[b];
        return;
    }

    int mid=(b+e)/2;

    built_tree(node <<1 ,b,mid);

    built_tree(node <<1 | 1,mid+1,e);

    st[node]=min(st[node << 1],st[node <<1 | 1]);
}

void pushdown(int node){

    lazy[node << 1] =(lazy[node << 1] & lazy[node]);

    lazy[node << 1 | 1] =(lazy[node << 1 | 1] & lazy[node]);

    st[node << 1] =(st[node << 1] & lazy[node]);

    st[node << 1 | 1]  =(st[node << 1 |1 ] & lazy[node]);

    lazy[node]=(1ll<<31)-1;

}

void pullup(int node){

    st[node]=min(st[node<<1],st[node<<1|1]);

}

void update(int node,int b,int e,int l,int r,ll val){

    if(e<l || b>r) return;

    if(b>=l && e<=r){

        lazy[node] =(lazy[node] & val);

        st[node] =(st[node] & val);

        return;
    }

    pushdown(node);

    int mid=(b+e)/2;

    update(node<<1,b,mid,l,r,val);

    update(node<<1|1,mid+1,e,l,r,val);

    pullup(node);
}

ll answer(int node,int b,int e,int l,int r){

    if(e<l || b>r) return 1e10;

    if(b>=l && e<=r){
        return st[node];
    }

    pushdown(node);

    int mid=(b+e)/2;

    ll left=answer(node<<1,b,mid,l,r);

    ll right=answer(node<<1|1,mid+1,e,l,r);

    return min(left,right);
}



int main(){
    fast;

    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++) cin>>a[i];

    built_tree(1,1,n);

    while(q--){
        ll type,l,r,val;

        cin>>type;

        if(!type){
            cin>>l>>r;
            cout<<answer(1,1,n,l,r)<<endl;
        }
        else{
            cin>>l>>r>>val;
            update(1,1,n,l,r,val);
        }
    }

    return 0;
}


