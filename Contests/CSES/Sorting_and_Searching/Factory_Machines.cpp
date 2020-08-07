#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll unsigned long long 

bool check(ll mid,ll a[],ll n,ll k){
    ll num=0;
    for(ll i=0;i<n;i++) num+=(mid/a[i]); 

    if(num>=k) return true;
    else return false;
}
int main(){
    IOS;
    ll n,k;
    cin>>n>>k;ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];    

    ll l=1,r=1e19,mid=0,ans=0;
    while(l<=r){
        mid=(l+(r-l)/2);
        if(check(mid,a,n,k)) r=mid-1,ans=mid;
        else l=mid+1;
    }

    cout<<ans<<"\n";
}
