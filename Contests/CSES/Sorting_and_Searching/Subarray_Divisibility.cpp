#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;++i) cin>>a[i];

    ll pfx_remainder[n];
    map<ll,vector<ll>> m;

    m[0].push_back(-1);
    for(ll i=0;i<n;i++){
        if(i==0)pfx_remainder[i]=a[i]%n;
        else{
            pfx_remainder[i]=pfx_remainder[i-1]+a[i];
            pfx_remainder[i]%=n;
        }
        pfx_remainder[i]=(pfx_remainder[i]+n)%n;
        m[pfx_remainder[i]].push_back(i);
    }

    ll ans=0;
    for(ll i=0;i<n;i++){
        ll target=pfx_remainder[i];
        auto it=m.find(target);
        if(it != m.end()){
            auto it1=lower_bound(m[target].begin(),m[target].end(),i);
            if(it1!=m[target].begin()) ans+=((--it1)-m[target].begin() + 1);
        }
    }
    cout<<ans<<"\n";
}
