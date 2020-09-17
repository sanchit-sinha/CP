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

        sort(a,a+n);

        bool ok=1;
        if(n==1) cout<<"YES\n";
        else{
            for(ll i=1;i<n;i++){
                if(a[i]-a[i-1]>1) ok=0;
            }

            if(ok) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}