#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=1e6+5;



string s;
struct info{
    int ans,lp_rem,rp_rem;
}seg_tree[4*limit];

typedef pair<int,int>pii;
typedef pair<int,pii>ans_node;

void built_tree(int node,int b,int e){

    if(b==e){
        seg_tree[node].ans=0;
        if(s[b-1]=='(')
            seg_tree[node].lp_rem=1,seg_tree[node].rp_rem=0;
        else
            seg_tree[node].lp_rem=0,seg_tree[node].rp_rem=1;
        return;
    }

    int mid=(b+e)/2;

    built_tree(node*2,b,mid);

    built_tree(node*2+1,mid+1,e);

    int match=min(seg_tree[node*2].lp_rem,seg_tree[node*2+1].rp_rem);

    seg_tree[node].ans=seg_tree[node*2].ans+seg_tree[node*2+1].ans+match;

    seg_tree[node].lp_rem=seg_tree[node*2].lp_rem+seg_tree[node*2+1].lp_rem-match;

    seg_tree[node].rp_rem=seg_tree[node*2].rp_rem+seg_tree[node*2+1].rp_rem-match;

}

ans_node answer(int node,int b,int e,int l,int r){

    if(e<l || b>r) return ans_node(0,pii(0,0));

    if(b>=l && e<=r) {

        return ans_node(seg_tree[node].ans,pii(seg_tree[node].lp_rem,seg_tree[node].rp_rem));

    }

    int mid=(b+e)/2;

    ans_node left=answer(node*2,b,mid,l,r);
    ans_node right=answer(node*2+1,mid+1,e,l,r);

    int match=min(left.second.first,right.second.second);

    int ans=left.first+right.first+match;

    int lp=left.second.first+right.second.first-match;

    int rp=left.second.second+right.second.second-match;

    return ans_node(ans,pii(lp,rp));


}

int main(){
    fast;
    int q;
    cin>>s>>q;
    int n=s.size();
    built_tree(1,1,n);
    while(q--){

        int l,r;
        cin>>l>>r;
        cout<<2*answer(1,1,n,l,r).first<<endl;

    }
    return 0;
}



