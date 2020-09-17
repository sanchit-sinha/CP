#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll mod=1e9+7;
int main(){
        IOS;
        ll n;
        cin>>n;
        ll a[n];
        ll pfx[n+1]={0};
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) pfx[i+1]=pfx[i]+a[i],pfx[i+1]%=mod;
        ll ans=0;
        for(ll i=1;i<=n;i++){
                ll sum=pfx[n]-pfx[i];
                sum=(sum+mod)%mod;
                sum*=a[i-1];
                sum%=mod;
                ans+=sum;
                ans%=mod;
        }
        cout<<ans<<"\n";
}
