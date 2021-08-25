#include "bits/stdc++.h"
using namespace std; 
#define ll long long 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int main(){
    IOS;
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll a=i*i;
        cout<<((a)*(a-1))/2-(4*(i-1)*(i-2))<<"\n";
    }
}
