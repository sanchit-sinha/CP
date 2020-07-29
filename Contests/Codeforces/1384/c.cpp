#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        string s,t;
        cin>>n>>s>>t;
        set<ll> m[20];
        bool ok=1;
        for(ll i=0;i<n;i++){
            if(s[i]-'a' != t[i]-'a') m[s[i]-'a'].insert(t[i]-'a');
            if(s[i] > t[i]) ok=0;
        }
        ll mov=0;
        if(ok){
            for(ll i=0;i<20;i++){
                ll len=(int)(m[i].size());  
                if(len){
                    mov++;
                    ll to=*m[i].begin();
                    for(auto it=m[i].begin() ; it !=m[i].end() ;it++){
                        if(*it != to) m[to].insert(*it);
                    }
                }
            }
            cout<<mov<<"\n";
        }
        else cout<<"-1\n";
    }
}
