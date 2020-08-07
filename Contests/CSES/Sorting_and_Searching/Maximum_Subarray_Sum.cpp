#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n;
    cin>>n;
    ll a[n];
    ll mxsum=LLONG_MIN,cursum=0;
    for(ll i=0;i<n;i++)
        cin>>a[i];

    for(ll i=0;i<n;i++){
        cursum+=a[i];
        if(cursum<=a[i]) cursum=a[i];
        mxsum=max(mxsum,cursum);
    }   
    cout<<mxsum<<"\n"; 
}
