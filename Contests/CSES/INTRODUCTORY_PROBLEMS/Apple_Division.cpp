#include "bits/stdc++.h"
using namespace std; 
#define ll long long 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
const ll N=20;
ll n,a[N];
ll check(ll x){
    ll bit[n]={0};
    ll index=0;
    while(x>0){
        bit[index++]=x%2;
        x/=2;
    }
    ll sum1=0,sum2=0;
    for(ll i=0;i<n;i++){
        if(bit[i]) sum1+=a[i];
        else sum2+=a[i];
    }
    return abs(sum1-sum2);
}
int main(){
    IOS;
    cin>>n;
    ll ans=LLONG_MAX;
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<(1ll<<n);++i){
        ans=min(ans,check(i));
    }
    cout<<ans<<"\n";
}
