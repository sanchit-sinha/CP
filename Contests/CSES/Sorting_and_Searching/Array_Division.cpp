#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

const ll N=2e5+11;
ll n,k,a[N];

bool check(ll mid){
    ll partition=0;
    ll sum=0;
    for(ll i=0;i<n;i++){
        if(a[i]>mid) return false;
        sum+=a[i];
        if(sum>mid){
            sum=a[i];
            partition++;
        }
    }

    partition++;

    if(partition<=k) return true;
    else return false;
}
int main(){
    IOS;
    cin>>n>>k;  
    for(ll i=0;i<n;i++)
        cin>>a[i];

    ll l=0,r=0,mid=0,ans=0;
    for(ll i=0;i<n;i++) r+=a[i];

    while(l<=r){
        mid=l+(r-l)/2;
        // <=k
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }

    cout << ans<<"\n";
}
