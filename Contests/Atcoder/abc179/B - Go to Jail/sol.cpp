/**
 *    Author:  Sanchit Sinha
 *    Created: 24.10.2020 17:26:13       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<vector<ll>> d(n,vector<ll>(2,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<2;j++) cin>>d[i][j];
    }
    bool ok=0;
    for(ll i=0;i<n-2;i++){
        ll ct=0;
        for(ll j=0;j<=2;j++){
            if(d[i+j][0]==d[i+j][1]) ct++;
        }
        if(ct==3) ok=1;
    }
    if(ok) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
