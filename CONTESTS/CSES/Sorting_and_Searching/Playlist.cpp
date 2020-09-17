#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
    ll ans=0;
    map<ll,ll>m;
    ll prev=0;
    for(ll i=0;i<n;i++){
        auto it=m.find(a[i]); 
        if(it==m.end()) m[a[i]]=i;
        else{
            ans=max(ans,i-prev);
            prev=max(prev,m[a[i]]+1);
            m[a[i]]=i;
        }
    }
    cout<<max(ans,n-prev)<<"\n";
}
