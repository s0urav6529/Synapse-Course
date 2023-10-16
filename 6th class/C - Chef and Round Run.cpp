#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
const int limit=1e6+5;

vector<int>a[limit];
vector<int>t[limit];
bool vis[limit];
int testy[limit];

vector<int>scc,order;

void dfs(int node){

    vis[node]=1;
    for(int cc:a[node]){

        if(vis[cc]==0)
            dfs(cc);
    }
    order.push_back(node);
}

void scc_dfs(int node){

    vis[node]=1;
    for(int cc:t[node]){

        if(vis[cc]==0)
            scc_dfs(cc);
    }
    scc.push_back(node);
}
void run_case(){

    int n,ans=0;
    cin>>n;

    order.clear();
    for(int i=0;i<n;i++){

        a[i].clear();
        t[i].clear();
        vis[i]=0;
        cin>>testy[i];
    }

    for(int i=0;i<n;i++){

        int u=i;
        int v=(i+testy[i]+1)%n;

        if(u==v) {
            ans++;
            continue;
        }

        a[u].push_back(v);
        t[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(vis[i]==0)
            dfs(i);
    }
    for(int i=0;i<n;i++) vis[i]=0;

    reverse(order.begin(),order.end());

    for(int i:order){

        if(vis[i]==0) {

            scc.clear();

            scc_dfs(i);

            if(scc.size()>1) ans+=scc.size();
        }
    }
    cout<<ans<<endl;
    return;
}
int main(){
    fast;
    int tc=1;
    cin>>tc;
    while(tc--) run_case();
    return 0;
}






