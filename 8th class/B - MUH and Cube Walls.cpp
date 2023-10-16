#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const ll limit=1e10+5;

void kmp(vector<ll> & s , int p){


    int  N = s.size();

    vector<ll> pi(N);

    for(int i=1;i<N;i++){

        int j=pi[i-1];

        while(j>0 && s[i]!=s[j])
            j = pi[j-1];

        if (s[i]==s[j])
            j++;

        pi[i] = j;
    }

    int cnt=0;

    for(int i=p;i<N;i++){

        if(pi[i]==p) cnt++;
    }

    cout<< cnt << endl;

}


int main(){
    fast;
    int n , m;
    cin >> n >> m;

    vector<ll>a(n),b(m);

    for(int i=0;i<n;i++)  cin >> a[i];

    for(int i=0;i<m;i++)  cin >> b[i];

    if(m==1){
        cout<< n <<endl;
        return 0;
    }

    vector<ll>difa,difb;

    for(int i=1;i<n;i++) difa.push_back(a[i]-a[i-1]);

    for(int i=1;i<m;i++) difb.push_back(b[i]-b[i-1]);

    vector<ll> s = difb;

    s.push_back(limit);   /// ? sign

    s.insert(s.end(),difa.begin(),difa.end());

    kmp(s,m-1);  /// m-1 pattern size



    return 0;
}



