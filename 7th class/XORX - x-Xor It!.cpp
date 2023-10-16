#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct Trie{

    int val;
    Trie* child[2];

};

Trie* create(){

    Trie* temp=new Trie;
    temp->val=0;
    temp->child[0]=temp->child[1]=NULL;
    return temp;
}

void Insert(Trie* root,int num){

    Trie* cur=root;

    for(int i=29;i>=0;i--){

        bool b=(num&(1<<i));

        if(cur->child[b]==NULL)
            cur->child[b]=create();

        cur=cur->child[b];
    }
    cur->val=num;
}


int MaxSubarray(Trie* root,int num){

    Trie* cur=root;

    for(int i=29;i>=0;i--){

        bool b=(num&(1<<i));

        if(cur->child[1-b]!=NULL)
            cur=cur->child[1-b];

        else if(cur->child[b]!=NULL)
            cur=cur->child[b];
    }
    return num^(cur->val);
}

int answer(Trie* root,int num){

    ///
    return 0;
}


void run_case(){
    Trie* root; root=create();  Insert(root,0);
    int n,ans=0;
    int x;
    cin>> n >> x;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int Xor=0;
    for(int i=0;i<n;i++){
        Xor^=a[i];
        Insert(root,Xor);
    }
    Xor=0;
    for(int i=0;i<n;i++){
        Xor^=a[i];
        ans=max(ans,MaxSubarray(root,Xor));
    }
    cout<<ans<<" "<<answer(root,x)<<endl;

    return;
}

int main(){
    fast;
    int tc=1;
    cin>>tc;
    while(tc--) run_case();
    return 0;
}



