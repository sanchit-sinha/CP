#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
const ll N=1e5+11;
ll n,a[N],mx[40],mn[40];
ll count(ll x){
    ll ct=0;
    while(x>0)x/=2,ct++;
    return ct;
}
int main(){
    IOS;
    ll t;cin>>t;
    while(t--){
        for(ll i=0;i<n;i++) a[i]=0;
        for(ll i=0;i<32;i++) mx[i]=mn[i]=0;
        for(ll i=0;i<32;i++) mn[i]=LLONG_MAX;
        
        cin>>n;
        for(ll i=0;i<n;i++) cin>>a[i];

        for(ll i=0;i<n;i++){
            ll dig=count(a[i]);
            mx[dig]=max(mx[dig],a[i]);
            mn[dig]=min(mn[dig],a[i]);
        }

        ll ans=0;
        for(ll i=0;i<32;i++){
            for(ll j=0;j<32;j++){
                if(mx[i] && mn[j]!=LLONG_MAX){
                    ll x=mx[i],y=mn[j];
                    ll val=(x*(1ll<<j)+y) - (y*(1ll<<i)+x);
                    ans=max(ans,val);
                }
            }
        }

        cout<<ans<<"\n";
    }
}
