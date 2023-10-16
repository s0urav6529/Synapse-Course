#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e2+5;

vector<int>Z(limit);

void Z_function(string s , int n){


    for (int i=1, l=0, r=0; i<n ; i++) {

        if (i <= r){
            Z[i] = min (r-i+1, Z[i-l]);
        }

        while ( (i + Z[i]) < n && ( s[Z[i]] == s[i+Z[i]]) ){
            Z[i]++ ;
        }

        if ( ( i+Z[i]-1 ) > r){
            l = i;
            r = i + Z[i]-1;
        }
    }
    return;

}

int main(){
    fast;
    int tc=1;
    cin >> tc;
    for(int t=1; t<=tc ;t++){
        string s;
        int n;
        cin >> s;

        n=s.size();


        for(int i=0;i<=n;i++) Z[i]=0;

        Z_function(s,n);

        bool ok=true;

        for(int i=1;i<n;i++) {

            if(Z[i]+i == n && (n%i==0)){
                cout<< i <<endl;
                ok=false;
                break;
            }
        }

        if(ok) cout<<n<<endl;
        if(t < tc) cout<<endl;
    }
    return 0;
}



