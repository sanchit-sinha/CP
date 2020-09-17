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
    ll red=0;
    for(ll i=0;i<n;i++) red+=(s[i]=='R');

    ll rem=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='R' && i>=red) rem++;
    }

    ll ans=0;
    for(ll i=0;i<red;i++){
        if(s[i]=='W' && rem) rem--,s[i]='R',ans++;
    }

    for(ll i=0;i<red;i++){
        if(s[i] != 'R') s[i]='R',ans++;
    }

    if(red) cout<<ans<<"\n";
    else cout<<0<<"\n";

}
