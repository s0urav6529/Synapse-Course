

/// https://www.spoj.com/problems/KQUERY/

#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=3e4+5;


int a[limit];
struct info{
    vector<int>v;
}st[4*limit];


void Marge(int node){

    int ls=st[node*2].v.size();
    int rs=st[node*2+1].v.size();
    int ni=0,li=0,ri=0;

    while(li<ls && ri<rs){

        if(st[node*2].v[li]<st[node*2+1].v[ri]){
            st[node].v.push_back(st[node*2].v[li++]);
        }
        else st[node].v.push_back(st[node*2+1].v[ri++]);

    }
    while(li<ls)
        st[node].v.push_back(st[node*2].v[li++]);

    while(ri<rs)
        st[node].v.push_back(st[node*2+1].v[ri++]);

}

void built_tree(int node,int b,int e){

    if(b==e){
        st[node].v.push_back(a[b]);
        return;
    }
    int mid=(b+e)/2;

    built_tree(node*2,b,mid);
    built_tree(node*2+1,mid+1,e);
    Marge(node);
}

int answer(int node,int b,int e,int l,int r,int k){

    if(e<l || b>r) return 0;

    if(b>=l && e<=r) {

        int idx=upper_bound(st[node].v.begin(),st[node].v.end(),k)-st[node].v.begin();

        return st[node].v.size()-idx;

    }

    int mid=(b+e)/2;
    int left=answer(node*2,b,mid,l,r,k);
    int right=answer(node*2+1,mid+1,e,l,r,k);
    return left+right;

}

int main(){
    fast;
    int n,q;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    built_tree(1,1,n);

    cin>>q;
    while(q--){

        int l,r,k;
        cin>>l>>r>>k;
        cout<<answer(1,1,n,l,r,k)<<endl;
    }
    return 0;
}




