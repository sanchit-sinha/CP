#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n;
    cin>>n;
    set<ll> s;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        s.insert(x);
    }
    cout<<(int)(s.size())<<"\n";
}
