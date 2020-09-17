#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll T;
    cin>>T;
    while(T--){
        ll n,k,z;
        cin>>n>>k>>z;
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        ll ans=0;
        for(ll i=0;i<=z;i++){
            ll j=k-2*i,sum=0,mx=0;
            for(ll l=0;l<=j;l++){
                sum+=a[l];
                mx=max(mx,a[l]+a[l+1]);
            }
            ans=max(ans,sum+mx*i);
        }
        cout<<ans<<"\n";
    }    
}