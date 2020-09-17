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
               for(ll i=0;i<n;i++) cin>>a[i];
               ll ans=0;
               for(ll i=0;i<n-1;i++) ans+=max(a[i]-a[i+1],0ll);
               cout<<ans<<"\n";
       }    
}