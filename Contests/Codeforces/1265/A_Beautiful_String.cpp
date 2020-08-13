#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
string s;
int main(){
    IOS;
    ll T;
    cin>>T;
    while(T--){
        s.clear();
        cin>>s;
        ll n=(int)s.size();
        if(s[0]=='?'){
            if(s[1]=='c'||s[1]=='b') s[0]='a';
            else s[0]='b';
        }
        for(ll i=1;i<n-1;i++){
            if(s[i]=='?'){
                char prev,next;
                prev=s[i-1];
                next=s[i+1];
                if('a'!=prev && 'a'!=next) s[i]='a';
                if('b'!=prev && 'b'!=next) s[i]='b';
                if('c'!=prev && 'c'!=next) s[i]='c';
            }
        }
        if(s[n-1]=='?'){
            if(s[n-2]=='b'||s[n-2]=='c') s[n-1]='a';
            else s[n-1]='b';
        }
        bool ok=1;
        for(ll i=1;i<n-1;i++){
            char pres=s[i],prev=s[i-1],next=s[i+1];
            if(pres==next || pres==prev) ok=0;
         }
         if(ok) cout<<s<<"\n";
         else cout<<"-1\n";
    }    
}