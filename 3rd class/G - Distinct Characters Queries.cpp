#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=1e5+5;

string s;
struct info{
    int cnt[27];
}st[4*limit];

int ans[27];

void marge(int node){

    for(int i=0;i<26;i++){
        st[node].cnt[i]=st[node*2].cnt[i]+st[node*2+1].cnt[i];
    }

}

void built_tree(int node,int b,int e){

    if(b==e){
        st[node].cnt[s[b-1]-'a']=1;
        return;
    }

    int mid=(b+e)/2;

    built_tree(node*2,b,mid);
    built_tree(node*2+1,mid+1,e);
    marge(node);
}

void update(int node,int b,int e,int pos,char c){

    if(b==e){
        st[node].cnt[s[b-1]-'a']--;
        s[b-1]=c;
        st[node].cnt[s[b-1]-'a']++;
        return;
    }
    int mid=(b+e)/2;
    if(pos<=mid) update(node*2,b,mid,pos,c);
    else update(node*2+1,mid+1,e,pos,c);
    marge(node);
}
void answer(int node,int b,int e,int l,int r){

    if(e<l || b>r) return;

    if(b>=l && e<=r){
        for(int i=0;i<26;i++){
            if(st[node].cnt[i]>0) {
                ans[i]=1;
            }
        }
        return;
    }

    int mid=(b+e)/2;

    answer(node*2,b,mid,l,r);
    answer(node*2+1,mid+1,e,l,r);
}


int main(){
    fast;
    int n,q;
    cin>>s>>q;
    n=s.size();
    built_tree(1,1,n);
    while(q--){

        int type,l,r,pos;
        char c;
        cin>>type;
        if(type==1){
            cin>>pos>>c;
            update(1,1,n,pos,c);
        }
        else{

            cin>>l>>r;

            for(int i=0;i<26;i++)
                ans[i]=0;

            answer(1,1,n,l,r);
            int cc=0;
            for(int i=0;i<26;i++) {
                if(ans[i]) cc++;
            }
            cout<<cc<<endl;
        }

    }
    return 0;
}



