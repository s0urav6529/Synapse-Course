#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
namespace __gnu_pbds{
          typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;
typedef long long int ll;
const int limit=2e5+5;

void Insert(ordered_set &s,int x){
     s.insert(x);
}

bool Exist(ordered_set &s,int x){
     if((s.upper_bound(x))==s.end()){
        return 0;
     }
     return ((*s.upper_bound(x))==x);
}

void Erase(ordered_set &s,int x){
     if(Exist(s,x)){
        s.erase(s.upper_bound(x));
     }
}

int Size(ordered_set &s){
     return (int)(s.size());
}

int FirstIdx(ordered_set &s,int x){
    if(!Exist(s,x)){
        return -1;
    }
    return (s.order_of_key(x));
}
void Clear(ordered_set &s){
     s.clear();
}

int main(){
    fast;
    ordered_set s;

    int tc,n;
    cin>>tc;
    while(tc--){
        Clear(s);
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
            Insert(s,a[i]);
        }
        ll ans=0;
        for(int i=0;i<n;i++){

            int idx=FirstIdx(s,a[i]);
            ans+=idx;
            Erase(s,a[i]);
        }
        cout<<ans<<endl;
    }


    return 0;


}


