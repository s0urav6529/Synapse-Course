#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;

const int limit=5e4+5;

struct node{
    ll tsum,pref,suff,maxsub;

    node(){
        tsum=maxsub=pref=suff=-1e16;
    }

}st[limit<<4];
ll a[limit];


node Marge(node left,node right){

    node parentnode;

    parentnode.tsum=left.tsum+right.tsum;

    parentnode.pref=max(left.pref, left.tsum + right.pref);

    parentnode.suff=max(right.suff,right.tsum+left.suff);

    parentnode.maxsub=max(max(left.maxsub,right.maxsub),left.suff+right.pref);

    return parentnode;
}



void built_tree(int Node,int b,int e){

    if(b==e){
        st[Node].tsum=st[Node].pref=st[Node].suff=st[Node].maxsub=a[b];
        return;
    }

    int mid=(b+e)/2;

    built_tree(Node*2,b,mid);
    built_tree(Node*2+1,mid+1,e);

    st[Node]=Marge(st[Node*2],st[Node*2+1]);
}

void update(int Node,int b,int e,int pos,int val){

    if(b==e){

        st[Node].tsum=st[Node].pref=st[Node].suff=st[Node].maxsub=a[b]=val;
        return;
    }

    int mid=(b+e)/2;

    if(pos<=mid)
        update(Node*2,b,mid,pos,val);

    else
        update(Node*2+1,mid+1,e,pos,val);

    st[Node]=Marge(st[Node*2],st[Node*2+1]);
}


node query(int Node,int b,int e,int l,int r){


    if(e<l || b>r) {
        node emptynode;
        return emptynode;
    }

    if(b>=l && e<=r){
        return st[Node];
    }

    int mid=(b+e)/2;

    node left=query(Node*2,b,mid,l,r);
    node right=query(Node*2+1,mid+1,e,l,r);

    node ans=Marge(left,right);
    return ans;

}

int main(){
    fast;
    int n,q;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    built_tree(1,1,n);

    cin>>q;
    for(int i=0;i<q;i++){

        int type,pos,val,l,r;
        cin>>type;
        if(!type){

            cin>>pos>>val;
            update(1,1,n,pos,val);

        }
        else{
            cin>>l>>r;
            cout<<query(1,1,n,l,r).maxsub<<endl;
        }

    }
    return 0;
}
