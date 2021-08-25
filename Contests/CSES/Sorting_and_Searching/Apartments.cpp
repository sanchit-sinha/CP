#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n,m,k;
    cin>>n>>m>>k;
    multiset<ll> apartment;
    vector<ll> size;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        apartment.insert(x);
    }
    for(ll i=0;i<m;i++){
        ll x;
        cin>>x;
        size.push_back(x);
    }
    sort(size.begin(),size.end());
    ll ans=0;
    for(ll i=0;i<(int)(size.size());++i){
        if((int)apartment.size()){
            auto it=apartment.lower_bound(size[i]-k);
            if(it!=apartment.end() && *it <= size[i]+k){
                ans++;
                apartment.erase(it);
            }
        }
    }
    cout<<ans<<"\n";
}
