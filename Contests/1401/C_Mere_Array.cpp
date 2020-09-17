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
               ll a[n],b[n];
               for(ll i=0;i<n;i++) cin>>a[i],b[i]=a[i];
               sort(b,b+n);
               ll mn=b[0];
                bool ok=1;
                // 2 8 4
                for(ll i=0;i<n;i++){
                        if(a[i]!=b[i] && a[i]%mn) ok=0;
                }
                if(ok) cout<<"YES\n";
                else cout<<"NO\n";
       }    
}