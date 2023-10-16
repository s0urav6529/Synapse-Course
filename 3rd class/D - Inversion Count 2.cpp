#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=2e5+5;

int ftree[limit];
int a[limit];

void update(int idx,int N){

    while(idx<=N){

        ftree[idx]++;
        idx+=(idx & -idx);
    }
}

int sum(int idx){

    int cnt=0;
    while(idx>0){

        cnt+=ftree[idx];

        idx-=(idx & -idx);

    }
    return cnt;


}

int main(){
    fast;
    int tc;
    cin>>tc;
    while(tc--){
        int n,N=2e5,num=1;
        memset(ftree,0,sizeof ftree);
        cin>>n;
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            mp[a[i]];
        }

        for(auto &i:mp){
            i.second=num++;
        }

        ll ans=0;
        for(int i=1;i<=n;i++){
            a[i]=mp[a[i]];
            ans+=(sum(N)-sum(a[i]));
            update(a[i],N);
        }
        cout<<ans<<endl;
    }
    return 0;


}



