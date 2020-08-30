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
               string s;
               cin>>s;
               char c=s[n-1];
               for(ll i=0;i<n;i++) cout<<c;
               cout<<"\n";
       }    
}