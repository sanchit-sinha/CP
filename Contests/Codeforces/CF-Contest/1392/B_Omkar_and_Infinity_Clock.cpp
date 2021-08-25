#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
       IOS;
       ll T;
       cin>>T;
       while(T--){
               ll n,k;
               cin >> n>>k;
               ll a[n];
               ll mx=LLONG_MIN;
               for(ll i=0;i<n;i++){
                       cin>>a[i];
                        mx=max(mx,a[i]);       
               }
               ll b[n];
                ll mx2=LLONG_MIN;
                for(ll i=0;i<n;i++) b[i]=mx-a[i],mx2=max(mx2,b[i]);
               if(k&1){
                       for(ll i=0;i<n;i++) cout<<b[i] <<" ";
                       cout<<"\n";
               }
               else{
                       for(ll i=0;i<n;i++) cout<<mx2-b[i] <<" ";
                       cout<<"\n"; 
               }
       }    
}       