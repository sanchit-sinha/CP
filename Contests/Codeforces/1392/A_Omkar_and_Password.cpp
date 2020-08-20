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
               cin >> n;
               set<ll> s;
               for(ll i=0;i<n;i++){
                       ll x;
                       cin>>x;
                       s.insert(x);
               }
               ll len=(int)s.size();
               if(len==1) cout<<n<<"\n";
               else cout<<"1\n";
       }    
}