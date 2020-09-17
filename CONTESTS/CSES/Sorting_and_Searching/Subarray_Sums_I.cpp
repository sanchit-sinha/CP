#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n,s;cin>>n>>s;
    ll a[n+1];
    for(ll i=0;i<n;i++) 
        cin>>a[i+1];

    vector<ll> pfx(n+1,0);
    for(ll i=1;i<=n;i++) pfx[i]=pfx[i-1]+a[i];

    ll ct=0;
    for(ll i=1;i<=n;++i){
        ll l=i,r=n,mid=0,ans=-1;
        while(l<=r){
            mid=l+(r-l)/2ll;
            if(pfx[mid]-pfx[i-1]>=s)r=mid-1,ans=mid;
            else l=mid+1;
        }
        if(ans!=-1 && pfx[ans]-pfx[i-1]==s) ct++;
    }
    cout<<ct<<"\n";
}
