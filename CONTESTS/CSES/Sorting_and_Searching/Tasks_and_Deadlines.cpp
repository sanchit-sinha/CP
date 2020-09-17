#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

const ll N=2e5+11;
ll n,deadline[N],duration[N],pfx[N];

int main(){
    IOS;
    
    cin>>n;
    ll sum_deadline=0;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        sum_deadline+=b;
        duration[i]=a;
    }

    sort(duration,duration+n);
    
    pfx[0]=duration[0];
    for(ll i=1;i<n;i++) 
        pfx[i]=pfx[i-1]+duration[i];

    ll sum_pfx=0;
    for(ll i=0;i<n;i++)
        sum_pfx+=pfx[i];

    ll ans=sum_deadline-sum_pfx;
    cout<<ans<<"\n";
}
