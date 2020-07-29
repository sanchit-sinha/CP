#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll int
ll n,a[111];
int main(){
   IOS;
   ll t;cin>>t;
   while(t--){
      for(ll i=0;i<n+1;i++) a[i]=0;

      string s;
      cin>>n;
      for(ll i=0;i<n;i++) cin>>a[i];
      for(ll i=0;i<50;i++) s.push_back('a');

      cout<<s<<"\n";
      for(ll i=0;i<n;i++){
         if(s[a[i]]=='a') s[a[i]]='b';
         else s[a[i]]='a';
         cout<<s<<"\n";
      }
   }
}
