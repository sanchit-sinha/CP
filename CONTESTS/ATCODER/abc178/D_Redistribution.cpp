#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

ll ans=0,mod=1e9+7;

int main(){
        IOS;
        ll n;
        cin>>n;
        vector<ll> dp(n+11,0);
        dp[0]=1;
        for(ll i=3;i<=n;i++){
                for(ll j=3;j<=i;j++){
                        dp[i]+=dp[i-j];
                }
                dp[i]%=mod;
        }
        cout<<dp[n]<<"\n";
}
