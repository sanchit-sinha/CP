#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%k)cout<<0;
            else cout<<1;
        }
        cout<<"\n";
    }    
}
