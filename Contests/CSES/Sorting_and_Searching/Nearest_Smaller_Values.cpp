#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n;cin>>n;
    vector<pair<ll,ll>> maintain_inc_order;
    
    for(ll i=1;i<=n;i++){
        ll x;
        cin>>x;

        while((int)(maintain_inc_order.size())){
            pair<ll,ll> last=maintain_inc_order.back();
            ll element=last.first;
            
            if(element>=x) maintain_inc_order.pop_back();
            else break;
        }

        if((int)(maintain_inc_order.size())) cout<<(maintain_inc_order.rbegin())->second<<" ";
        else cout<<0<<" ";

        maintain_inc_order.push_back(make_pair(x,i));
    }
        
}
