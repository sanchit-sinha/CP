#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n, m;
    cin>>n>>m;
    multiset<ll> s;
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        s.insert(x);
    }
    for(ll i=0;i<m;i++){
        ll x;
        cin>>x;
        ll ans=-1;
        auto it=s.upper_bound(x);
        if(it != s.begin()){
            it--;
            ans=*it;
            s.erase(it);
        }
        cout<<ans<<"\n";
    }
}
