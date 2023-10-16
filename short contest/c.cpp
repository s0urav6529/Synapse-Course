#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=5e5+5;


int arr[limit];

int main(){

    int n,q;
    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    scanf("%d",&q);

    ll block=sqrt(n);

    vector<ll>mst[n/block+5];

    for(int i=0;i<n;i++)
        mst[i/block].push_back(arr[i]);


    for(int i=0;i<block+4;i++)
        sort(mst[i].begin(),mst[i].end());

    while(q--) {

        int type;
        scanf("%d",&type);

        if(type==1) {

            int k,u;
            scanf("%d%d",&k,&u);
            k--;

            ll lft=0 , rht=mst[k/block].size()-1 , mid;

            while(lft<=rht){

                mid=(lft+rht+1)/2;

                if(mst[k/block][mid]==arr[k])
                    break;

                else if( arr[k] < mst[k/block][mid]  )
                    rht=mid-1;

                else
                    lft=mid+1;
            }

            arr[k]=u;

            mst[k/block][mid]=u;

            sort(mst[k/block].begin(),mst[k/block].end());
        }
        else {
            int l,r,k,ans=0;

            scanf("%d%d%d",&l,&r,&k);

            l--,r--;

            if(l/block == r/block){

                for(int i=l;i<=r;i++){

                   if(arr[i]>=k)
                        ans++;
                }
                printf("%d\n",ans);
            }
            else{

                ll left_block=l/block;
                ll right_block=r/block;

                for(int i=l;i<(left_block+1)*block;i++)
                    if(arr[i]>=k) ans++;

                for(int i=right_block*block;i<=r;i++)
                    if(arr[i]>=k) ans++;

                for(int i=left_block+1;i<right_block;i++){

                    ans+=(mst[i].end()-lower_bound(mst[i].begin(),mst[i].end(),k));
                }
                printf("%d\n",ans);
            }
        }
    }

    return 0;
}

