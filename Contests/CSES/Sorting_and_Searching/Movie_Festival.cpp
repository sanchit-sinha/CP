#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n;
    cin>>n;
    vector<pair<ll,ll>>v;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    ll ans=0;
    ll prev_l,prev_r,l,r;
    for(ll i=0;i<n;i++){
        l=v[i].second,r=v[i].first;
        if(i==0){
            prev_l=v[i].second;
            prev_r=v[i].first;
            ans++;
        }
        else{
            if(l>=prev_r){
                ans++;
                prev_r=r,prev_l=l;
            }
        }
    }
    cout<<ans<<"\n";
}
