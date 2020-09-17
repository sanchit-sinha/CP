#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll T;
    cin>>T;
    while(T--){
        ll n,m;
        cin>>n>>m;
        string s[n];

        for(ll i=0;i<n;i++) cin>>s[i];

        ll ans=0;

        for(ll j=0;j<m;j++) if(s[n-1][j]!='R') ans++;

        for(ll i=0;i<n;i++) if(s[i][m-1] != 'D') ans++;

        cout<<ans-2<<"\n";
    }    
}