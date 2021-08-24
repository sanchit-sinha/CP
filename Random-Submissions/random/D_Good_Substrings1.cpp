#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
const int ALPHABET_SIZE = 26; 
string s,t;
ll bad,ans;
bool good[ALPHABET_SIZE];
struct trienode{
        struct trienode* children[ALPHABET_SIZE];
        bool isEndofword;
};
struct trienode* initialize_void(){
        struct trienode* pNode=new trienode;
        pNode->isEndofword=false;
        for(ll i=0;i<26;i++){
                pNode->children[i]=NULL;
        }
        return pNode;
}
void insert(struct trienode* root,string key){
        struct trienode* pNode=root;
        ll len=(int)key.size();
        for(ll i=0;i<len;i++){
                ll index=key[i]-'a';
                if(!pNode->children[index]) pNode->children[index]=initialize_void();
                pNode=pNode->children[index];
        }
        pNode->isEndofword=true;
}
void solve(struct trienode* root,ll ct){
        for(ll i=0;i<ALPHABET_SIZE;i++){
                if(root->children[i]){
                        if(!good[i]){
                                if(ct+1<=bad){
                                        ans++;
                                        solve(root->children[i],ct+1);
                                }
                        }       
                        else{
                                ans++;
                                solve(root->children[i],ct);
                        }
                }
        }
}

int main(){
        IOS;
        cin>>s>>t>>bad;
        for(ll i=0;i<26;i++) good[i]=t[i]-'0';
        struct trienode* root=initialize_void();
        ll n=(int)s.size();
        for(ll i=0;i<n;i++){
                ll len=n-i+1;
                string check=s.substr(i,len+1);
                insert(root,check);
        }
        solve(root,0);
        cout<<ans<<"\n";
}       
