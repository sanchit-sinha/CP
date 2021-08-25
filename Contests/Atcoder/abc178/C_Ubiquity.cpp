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
        if(n==1) cout<<0<<"\n";
        else{
                ll ans=0;
                ans=powermod(10, n  ,mod);
                ans%=mod;

                ans-=powermod(9, n  ,mod);
                // ans-=powermod(n , 9,mod);
                ans=(ans+mod)%mod;

                ans-=powermod(9, n  ,mod);
                // ans-=powermod(n , 9,mod);
                ans=(ans+mod)%mod;

                ans+=powermod(8, n  ,mod);
                // ans+=powermod(n , 8,mod);
                ans=(ans+mod)%mod;

                cout<<ans<<'\n';
        }
}
