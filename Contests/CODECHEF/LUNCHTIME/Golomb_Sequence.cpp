#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
const ll mod = 1e9+7;
const ll N = 2e6 + 11;
ll g[N],pfx[N],pfxx[N];
ll solve(ll x){
    ll lo=1,hi=N,mid=0,ans=0;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        if(pfx[mid]<=x) lo=mid+1,ans=mid;
        else hi=mid-1;
    }
    ll rem=x-pfx[ans];
    ll a=pfxx[ans];
    a%=mod;
    a+=(((rem*(ans+1))%mod)*(ans+1))%mod;
    return (a%mod);
}
int main(){
    IOS;
    ll t;cin>>t;
    g[1]=1;
    for(ll i=2;i<N;i++) g[i]=1+g[i-g[g[i-1]]];
    for(ll i=1;i<N;i++){
        pfx[i]=pfx[i-1]+g[i];

        pfxx[i]=pfxx[i-1]+(((g[i]%mod)*(i%mod))%mod*i)%mod;
        pfxx[i]%=mod;
    }
    while(t--){
        ll l,r;
        cin>>l>>r;
        cout<<(solve(r)-solve(l-1)+mod)%mod<<"\n";
    }
}
