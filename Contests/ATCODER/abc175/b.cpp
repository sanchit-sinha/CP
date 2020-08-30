#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n,d;
    cin >>n>>d;
    // ll x[N],y[N];
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        if(a*a+b*b<=d*d) ans++;
    }
    cout << ans<<"\n";
}