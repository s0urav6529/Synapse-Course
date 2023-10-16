#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define mxx 100005
int n;
int a[mxx];
int tree[mxx*4];

void segment_tree(int node,int b,int e){

    if(b==e){
        tree[node]=a[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;

    int mid=(b+e)/2;

    segment_tree(left,b,mid);
    segment_tree(right,mid+1,e);

    tree[node]=min(tree[left],tree[right]);
}
int mn(int node,int b,int e,int x,int y){

    if(e<x || b>y)
        return 1e9+1;

    if(b>=x && e<=y)
        return tree[node];

    int left=node*2;
    int right=node*2+1;

    int mid=(b+e)/2;

    return min(mn(left,b,mid,x,y),mn(right,mid+1,e,x,y));
}

int main()
{
    fast;
    int q;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    segment_tree(1,1,n);

    cin>>q;
    while(q--) {
        int x,y;
        cin>>x>>y;
        x++,y++;
        cout<<mn(1,1,n,x,y)<<endl;
    }
    return 0;
}
