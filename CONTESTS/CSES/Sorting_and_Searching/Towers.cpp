#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n;
    cin>> n;
    multiset<pair<ll,ll>>m;
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        auto it=m.upper_bound(make_pair(x,LLONG_MAX));
        if(it==m.end()) m.insert({x,ans++});
        else{
            ll val=it->second;
            m.erase(it);
            m.insert(make_pair(x,val));
        }
    }

    cout <<ans<<"\n";
}
