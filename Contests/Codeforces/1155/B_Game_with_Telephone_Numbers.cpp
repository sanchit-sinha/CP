#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
        IOS;
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll moves=n-11;
        ll ct=0;
        for(ll i=0;i<moves;i++) if(s[i]=='8') ct++;
        if(ct> moves/2) cout<<"YES\n";
        else if(ct==moves/2){
                if(s[moves]=='8') cout<<"YES\n";
                else cout<<"NO\n";
        }
        else cout<<"NO\n";
}
