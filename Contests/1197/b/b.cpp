#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n;
    cin>>n;
    ll a[n];
    vector<pair<ll,ll>> v;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        v.push_back({a[i],i});
    }
    sort(v.begin(),v.end());
    ll index=v[n-1].second;
    bool ok=1;
    for(ll i=index-1;i>=0;--i){
        if(a[i]>a[i+1]) ok=0;
    }
    for(ll i=index+1;i<n;i++) if(a[i] > a[i-1]) ok=0;
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
}
