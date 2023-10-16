


///UNDONE


#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=2e5+5;


int n,m;
vector<vector<int>> adj, transpose;
vector<int> con_group, out ,val;
vector<bool> vis;
vector<bool> assign_sign;

void dfs_out(int node){

    vis[node]=true;

    for(int ch:adj[node]){

        if(! vis[ch])
            dfs_out(ch);
    }
    out.push_back(node);
}

void dfs(int node, int id){

    vis[node]=true;
    con_group[node]=id;

    for(int ch:transpose[node]){

        if(! vis[ch])
            dfs(ch,id);
    }
}


bool solve_2SAT(){

    vis.assign(2*n, false);

    for(int i=0;i<2*n;i++){

        if(! vis[i]){
            dfs_out(i);
        }
    }

    vis.assign(2*n, false);

    con_group.assign(2*n, -1);

    for(int i=2*n-1,cc=0;i>=0;i--){

        if(! vis[out[i]]){
            dfs(out[i],cc++);

        }
    }

    assign_sign.resize(n);

    for(int i=0;i<n;i++){

        if(con_group[2*i] == con_group[2*i+1]){
            return false;
        }
        assign_sign[i] = con_group[2*i] > con_group[2*i+1];

    }

    return true;
}

void add_disjunction(int a, bool na, int b, bool nb){

    /// na & nb sign of a & b respectively


    a = 2 * a + na;
    b = 2 * b + nb;

    /// neg_a & neg_b negative of a & b respectively

    int neg_a = a ^ 1;
    int neg_b = b ^ 1;

    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);

    transpose[b].push_back(neg_a);
    transpose[a].push_back(neg_b);

}

int main(){
    fast;

    cin >> n >> m;

    adj.resize(2*n);
    transpose.resize(2*n);
    val.resize(n);

    for(int i=0; i<n ;i++) cin >> val[i];

    map<pair<int,int>,bool>mp;
    while(m--){

        int p,bef; cin >> p >> bef;

        bef--;

        for(int i=2; i<=p; i++){

            int cur,temp; cin >> cur;

            cur--;

            temp= cur;

            if(bef > cur) swap(bef , cur);

            if(mp.find({bef, cur})==mp.end()){


                cout<<bef << " " << cur <<endl;

                char sign_bef='+',sign_cur='+';

                if(val[bef]== 1) sign_bef= '-';
                if(val[cur]== 1) sign_cur= '-';

                add_disjunction(bef, sign_bef=='-', cur, sign_cur=='-');

                mp[{bef,cur}]=true;
            }

            bef=temp;

        }
    }

    bool possible=solve_2SAT();

    if(possible==false){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{

        for(int i=0;i<n;i++){
            cout<<(assign_sign[i]?'+':'-')<<" ";
        }
        cout<<endl;
    }

    return 0;
}



