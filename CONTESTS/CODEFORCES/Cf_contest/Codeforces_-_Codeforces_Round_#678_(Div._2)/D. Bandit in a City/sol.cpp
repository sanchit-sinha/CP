/**
 *    Author:  Sanchit Sinha
 *    Created: 24.10.2020 21:42:27       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll N =2e5+11;
vector<ll> v[N];
ll a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    for(ll i=2;i<=n;i++){
        ll x;
        cin>>x;
        v[x].push_back(i);
    }
    for(ll i=1;i<=n;i++) cin>>a[i];
    
    return 0;
}
