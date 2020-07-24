#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
ll n,m;
string s[1011];
ll row[1011],col[1011];
int main(){
    IOS;    
    cin>>n>>m;
    for(ll i=0;i<n;i++) cin>>s[i];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++) if(s[i][j]=='*') row[i]++,col[j]++;
    }
    
    ll ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++) if(s[i][j]=='*') ans+=(row[i]-1)*(col[j]-1);
    }
    cout<<ans<<"\n";
}
