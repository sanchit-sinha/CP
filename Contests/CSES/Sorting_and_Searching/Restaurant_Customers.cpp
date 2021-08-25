#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n;cin>>n;
    vector<pair<ll,ll>>v;
    for(ll i=0;i<n;++i){
        ll a,b;
        cin>>a>>b;
        v.push_back(make_pair(b,a));
    }
    sort(v.begin(),v.end());

    map<ll,ll> m;
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(i==0) m[v[i].first]=ans++;
        else{
            ll l=v[i].second;
            ll r=v[i].first;
            auto it=m.upper_bound(l);
            if(it != m.begin()){
                it--;
                m[r]=it->second;
                m.erase(it);
            }
            else{
                m[r]=ans++;
            }
        }
    }
    cout<<ans<<"\n";
}
