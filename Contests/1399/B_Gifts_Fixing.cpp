#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        ll a[n];
        ll b[n];
        
        ll mn1=LLONG_MAX,mn2=LLONG_MAX;
        for(ll i=0;i<n;i++) cin>>a[i],mn1=min(mn1,a[i]);
        for(ll i=0;i<n;i++) cin>>b[i],mn2=min(mn2,b[i]);
    
        ll ans=0;
        for(ll i=0;i<n;i++){
            ll x,y;
            x=a[i]-mn1,y=b[i]-mn2;

            ans += max(x,y);
        }

        cout << ans<<"\n";

    }    
}