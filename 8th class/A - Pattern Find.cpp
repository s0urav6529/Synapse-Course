#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e2+5;

void kmp(string s,string p){

    string ss = p + "?" + s;
    int n=ss.size();
    vector<int> pi(n);

    for(int i=1;i<n;i++){

        int j=pi[i-1];

        while(j>0 && ss[i]!=ss[j])
            j = pi[j-1];

        if (ss[i]==ss[j])
            j++;

        pi[i] = j;
    }

    vector<int>ans;
    int x=p.size();
    for(int i=p.size();i<n;i++){

        if(pi[i]==p.size()) {
            ans.push_back(i-x-pi[i]+1);
        }
    }

    if(ans.size()) {
        cout<< ans.size() <<endl;
        for(auto i:ans) cout<<i<<" ";
        cout<<endl;
    }
    else cout<<"Not Found"<<endl;
    return;
}


int main(){
    fast;
    int tc=1;
    cin >> tc;

    for(int t=1;t<=tc;t++) {
        string s,p; cin >> s >> p;
        kmp(s,p);
        cout<<endl;
    }

    return 0;
}



