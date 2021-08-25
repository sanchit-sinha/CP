/**
 *    Author:  Sanchit Sinha
 *    Created: 20.10.2020 21:27:19       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll unsigned long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll n;
        cin>>n;
        // ncn/2 * (n-1)! * (n-1)! / 2
        ll ans=1;
        for(ll i=n;i>n/2;i--){
                ans*=i;
        }
        ll p=1;
        for(ll i=1;i<n/2;i++) p*=i;

        ans=ans/(p*(n/2)) ;
        ans*=p;
        ans*=p;
        ans/=2;
        cout<<ans<<"\n";
        return 0;
}
