/**
 *    Author:  Sanchit Sinha
 *    Created: 24.10.2020 13:56:49       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll T;
    cin>>T;
    while(T--){
        ll a,b;
        cin>>a>>b;
        ll x=0;
        for(ll i=0;i<=30;i++){
            ll xx=(1ll<<i)&a;
            ll yy=(1ll<<i)&b;
            if((xx && !yy) || (!xx && yy)) x+=(1ll<<i);
        }
        cout<<x<<"\n";
    }    
    return 0;
}