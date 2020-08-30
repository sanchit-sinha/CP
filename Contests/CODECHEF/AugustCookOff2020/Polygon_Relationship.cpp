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
               ll x[n],y[n];
               for(ll i=0;i<n;i++) cin>>x[i]>>y[i];
               ll ans=n;
               while(n>=3){
                       n/=2;
                        if(n>=3) ans+=n;
               }
               cout<<ans<<"\n";
       }    
}