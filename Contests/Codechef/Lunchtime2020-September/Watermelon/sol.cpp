/**
 *    author:  Sanchit Sinha
 *    created: 27.09.2020 09:23:13       
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
                ll n;cin>>n;
                ll a[n];
                ll sum=0;
                for(ll i=0;i<n;i++) cin>>a[i],sum+=a[i];
                if(sum<0) cout<<"NO\n";
                else cout<<"YES\n";
        }    
        return 0;
}