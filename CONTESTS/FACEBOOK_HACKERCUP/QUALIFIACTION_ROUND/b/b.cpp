#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll int

int main(){
    IOS;
    ll t;cin>>t;
    for(ll ii=1;ii<=t;ii++){
        cout<<"Case #"<<ii<<": ";
        ll n;
        string s;
        cin>>n>>s;
        ll a=0,b=0;
        for(ll i=0;i<n;i++){
            a += (s[i]=='A');
            b += (s[i]=='B');
        }
        if(a==b+1 || a==b-1) cout<<"Y\n";
        else cout<<"N\n";
    }
}
