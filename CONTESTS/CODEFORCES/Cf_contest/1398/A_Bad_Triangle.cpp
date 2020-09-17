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
               for(ll i=0;i<n;i++){
                       cin >> a[i];
               }

               if(a[0]+a[1]>a[n-1]) cout<<-1<<"\n";
               else cout<<"1 2 "<<n<<"\n";
       }    
}