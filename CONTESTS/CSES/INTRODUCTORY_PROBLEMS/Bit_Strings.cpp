#include "bits/stdc++.h"
using namespace std; 
#define ll long long 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
ll mod=1e9+7;
ll powermod(ll base,ll ex,ll mod){
    ll ans=1,prev=base;
    bool f=0;
    while(ex>0){
        ll bit=ex%2;
        if(f)prev*=prev;
        prev%=mod;
        if(bit) ans*=prev;
        ans%=mod;ex/=2;
        f=1;
    }
    return ans;
}
int main(){
    IOS;
    ll n;
    cin>>n;
    cout<<powermod(2,n,mod)<<endl;
}
