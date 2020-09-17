#include "bits/stdc++.h"
using namespace std; 
#define ll long long 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int main(){
    IOS;    
    ll t;cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        ll mx=max(x,y),mn=min(x,y);
        if(mx&1){
            if(mx==y) cout<<mx*mx-(mn-1);
            else cout<<(mx*mx)-(mx-1)-(mx-mn);
        }
        else{
            if(mx==x) cout<<mx*mx-(mn-1);
            else cout<<(mx*mx)-(mx-1)-(mx-mn);
        }
        cout<<"\n";
    }
}   
