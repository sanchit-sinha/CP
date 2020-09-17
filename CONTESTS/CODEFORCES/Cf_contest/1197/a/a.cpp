#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        if(n<=2) cout<<0<<"\n";
        else{
            sort(a,a+n);
            cout<<min(a[n-2]-1,n-2)<<"\n";
        }
    }
}
