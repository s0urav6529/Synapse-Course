

/// Find maximum prefix in range between [a, b] if less than 0 the 0 is the answer
/// update the k th index with v

#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=2e5+5;

struct Node{
    ll sum;
    ll pref_sum;
    Node(){
        sum = pref_sum =0;
    }
}st[limit << 2];

ll aa[limit];

void built_tree(int node,int b,int e){

    if(b==e){
        st[node].sum = aa[b];
        st[node].pref_sum = aa[b];
        return;
    }

    int mid =(b+ e) / 2;

    built_tree(node << 1 , b ,mid);
    built_tree(node << 1 | 1, mid+1 , e);

    st[node].sum = st[node << 1 ].sum + st[node << 1 | 1].sum;

    st[node].pref_sum = max(st[node << 1 ].pref_sum , st[node << 1 ].sum + st[node << 1 | 1].pref_sum);

}

void update(int node,int b,int e,int id){

    if(b==e){
        st[node].sum = aa[b];
        st[node].pref_sum = aa[b];
        return;
    }

    int mid =(b + e) / 2;

    if(id <= mid) update(node << 1 , b ,mid,id);
    else update(node << 1 | 1 , mid+1 , e,id);

    st[node].sum = st[node << 1 ].sum + st[node << 1 | 1].sum;

    st[node].pref_sum = max(st[node << 1 ].pref_sum , st[node << 1 ].sum + st[node << 1 | 1].pref_sum);

}

Node query(int node,int b,int e,int l,int r){


    if(b>r || e<l){
        Node emptynode;
        return emptynode;
    }

    if(b >= l && e <= r){
        return st[node];
    }

    int mid = (b+e)/2;

    Node left = query(node << 1 , b,mid , l, r);

    Node right = query(node << 1 | 1,mid+1,e, l,r);

    Node res;
    res.sum = left.sum + right.sum;
    res.pref_sum = max(left.pref_sum , left.sum + right.pref_sum);

    return res;

}


void run_case(){

    int n,q;
    scanf("%d %d", &n , &q);

    for(int i=1;i<=n;i++) {
        ll x; scanf("%lld",&x); aa[i]=x;
    }

    built_tree(1,1,n);

    while(q--){

        int  type,id,a,b;
        ll k;
        scanf("%d",&type);

        if(type==1){

            scanf("%d %lld", &id , &k);
            aa[id]=k;
            update(1,1,n,id);
        }
        else{
            scanf("%d %d", &a , &b);
            ll ans=max(query(1,1,n,a,b).pref_sum,0ll);
            printf("%lld\n",ans);
        }

    }

    return;
}

int main(){
    fast;
    run_case();
    return 0;
}
