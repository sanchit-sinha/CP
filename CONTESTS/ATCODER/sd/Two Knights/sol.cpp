/**
 *    Author:  Sanchit Sinha
 *    Created: 17.10.2020 00:10:17       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll n;
        cin>>n;
        for(ll i=1;i<=n;i++){
                ll sq=i*i;
                cout<<max((sq*(sq-1))/2 - 4*(i-2)*(i-1) , 0)<<"\n";
        }

        return 0;
}
