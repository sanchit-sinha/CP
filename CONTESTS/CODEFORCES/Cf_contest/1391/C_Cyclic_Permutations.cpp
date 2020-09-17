#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long
const ll mod=1e9+7; 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

ll fact(ll x){
    ll p=1;
    for(ll i=1;i<=x;i++){
        p*=i;
        p%=mod;
    }

    return p;
}
int main(){
    IOS;
    ll n;
    cin>>n;
    ll ans=0;
    // if(n==3){
    //     cout<<0<<"\n";
    //     return 0;
    // }
    // ll rem=fact(n-3);
    // ll pos=n-2;
    
    // for(ll i=1;i<=n-2;i++){
    //     ll big=n-i;
        
    //     ll p=1;
        
    //     p*=pos;
    //     p%=mod;
        
    //     p*=rem;
    //     p%=mod;

    //     p*=(n-i);
    //     p%=mod;
    //     p*=(n-i-1);
    //     p%=mod;
        
    //     ans+=p;
    //     ans%=mod;
    // }

    ans = fact(n);
    ans%=mod;

    ll val=powermod(2,n-1,mod);

    ans=(ans-val+mod)%mod;
    cout<<ans<<"\n";
}
