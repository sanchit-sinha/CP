#include "bits/stdc++.h"
using namespace std; 
#define ll long long 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int main(){
    IOS;
    ll n;
    cin>>n;
    ll prev=0,mov=0;
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        if(i==0) prev=x;
        else{
            if(x<prev){
                mov+=abs(prev-x);
            }
            else prev=x;
        } 
    }
    cout<<mov<<"\n";
}
