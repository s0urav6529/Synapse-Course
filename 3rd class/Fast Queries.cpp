#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int limit=1e5+5;

#define block 700
int a[limit];
int fre[limit];
int ans[50005];
int cnt=0;


struct query{
    int l;
    int r;
    int in;
}q[50005];

bool comp(query a,query b){

    if(a.l/block!=b.l/block)
        return a.l/block<b.l/block;

    return a.r<b.r;
}

void add(int pos){
    fre[a[pos]]++;
    if(fre[a[pos]]==1) cnt++;
}

void Remove(int pos){
    fre[a[pos]]--;
    if(fre[a[pos]]==0) cnt--;
}


int main()
{
    fast;
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        int n,qq;
        cin>>n>>qq;
        for(int i=0;i<n;i++) cin>>a[i];

        for(int i=0;i<qq;i++){
            cin>>q[i].l>>q[i].r;
            q[i].l--;
            q[i].r--;
            q[i].in=i;
        }
        memset(fre,0,sizeof fre);
        sort(q,q+qq,comp);
        cnt=0;

        int ML=0,MR=-1;
        for(int i=0;i<qq;i++){

            int L=q[i].l;
            int R=q[i].r;

            while(ML>L){
                ML--,add(ML);
            }
            while(MR<R){
                MR++,add(MR);
            }

            while(ML<L){
                Remove(ML),ML++;
            }
            while(MR>R){
                Remove(MR),MR--;
            }
            ans[q[i].in]=cnt;
        }
        cout<<"Case "<<t<<":"<<endl;
        for(int i=0;i<qq;i++){
            cout<<ans[i]<<endl;
        }
    }

    return 0;
}
