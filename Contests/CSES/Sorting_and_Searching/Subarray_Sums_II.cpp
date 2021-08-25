#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n,x;
    cin>>n>>x;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];

    map<ll,vector<ll> > m;
    ll pfx[n];

    m[0].push_back(-1);
    for(ll i=0;i<n;i++){
        if(i==0) pfx[i]=a[i];
        else pfx[i]=pfx[i-1]+a[i];

        m[pfx[i]].push_back(i);
    }

    ll ans=0;
    for(ll i=0;i<n;i++){
        ll target=pfx[i]-x;
        auto it=m.find(target);
        if(it != m.end()){
            auto it1=lower_bound(m[target].begin(),m[target].end(),i);
            if(it1!=m[target].begin()) ans+=((--it1)-m[target].begin() + 1);
        }
    }
    cout << ans<<"\n";
}
