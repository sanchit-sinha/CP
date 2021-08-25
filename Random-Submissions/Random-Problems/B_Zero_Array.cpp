#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
        IOS;
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i=0;i<n;i++){
                cin>>v[i];
        }
        ll sum=accumulate(v.begin() , v.end() ,0ll);
        sort(v.begin() , v.end());
        if(!(sum&1) && v[n-1] <= sum-v[n-1]) cout<<"YES\n";
        else cout<<"NO\n";
}
