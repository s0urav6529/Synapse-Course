

///  https://lightoj.com/problem/fast-queries

#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=1e5+5;

int a[limit];

struct info{
    set<int>s;
}st[4*limit];

set<int>ans;

void marge(int node){

    for(auto i:st[node*2].s){
        st[node].s.insert(i);
    }
    for(auto i:st[node*2+1].s){
        st[node].s.insert(i);
    }
    return;
}

void built_tree(int node,int b,int e){

    if(b==e){
        st[node].s.insert(a[b]);
        return;
    }
    int mid=(b+e)/2;

    built_tree(node*2,b,mid);
    built_tree(node*2+1,mid+1,e);
    marge(node);
}

int answer(int node,int b,int e,int l,int r){

    if(e<l || b>r) return 0;

    if(b>=l && e<=r) {
        return st[node].s.size();
    }
    int mid=(b+e)/2;

    int left=answer(node*2,b,mid,l,r);
    int right=answer(node*2+1,mid+1,e,l,r);

    return left+right;
}

int main(){
    fast;

    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){

        int q,n;
        scanf("%d%d",&n,&q);

        for(int i=1;i<=n;i++)
            st[i].s.clear();

        for(int i=1;i<=n;i++) cin>>a[i];

        built_tree(1,1,n);

        for(int i=1;i<=q;i++){
            int l,r;
            cin>>l>>r;
            cout<<answer(1,1,n,l,r)<<endl;
        }
    }
    return 0;
}




