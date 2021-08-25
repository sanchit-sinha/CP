#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n;
    cin>>n;
    ll s=0;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i],s+=a[i];
    s/=n;
    ll ans=LLONG_MAX;
    sort(a,a+n);
    ll cost1=0,cost2=0;    
    for(ll i=0;i<n;i++){
        cost1+=abs(a[i]-a[n/2]);
        cost2+=abs(a[i]-a[n/2 + 1]);
    }
    ans=min(cost1,cost2);
    cout<<ans<<"\n";
}
