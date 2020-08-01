#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
    ll sum=0;
    vector<ll> v;
    for(ll i=1;i<n;i++) v.push_back(a[i]-a[i-1]);
    sort(v.rbegin(),v.rend());

    for(ll i=0;i<k-1;i++) sum+=v[i];
    cout<<a[n-1]-a[0]-sum<<"\n";
}
