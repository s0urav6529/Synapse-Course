#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e5+5;

void kmp(string s,string p){

    string ss = p + "$" + s;
    int n=ss.size();
    vector<int> pi(n);

    for(int i=1;i<n;i++){

        int j=pi[i-1];

        if(ss[i]=='?') {

            int ans = 0;
            char C;

            for(char c='a';c<='z';c++){

                int temp = j;

                while(temp>0 && c!=ss[temp])
                    temp = pi[temp-1];

                if (c == ss[temp])
                    temp++;

                if(temp > ans) C=c,ans=temp;
            }

            ss[i] = C;
            pi[i] = ans;
        }
        else{

            while(j>0 && ss[i]!=ss[j])
                j = pi[j-1];

            if (ss[i]==ss[j])
                j++;

            pi[i] = j;
        }


    }

    int cnt=0;

    for(int i=p.size();i<n;i++){

        if(pi[i]==p.size()) cnt++;
    }
    cout<<ss<<endl;
    cout<<cnt<<endl;
}

int main(){
    fast;

    string s, p;
    cin >>  s >> p;

    kmp(s,p);


    return 0;
}



