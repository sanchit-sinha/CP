#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll mod=1e9+7;

ll calc(ll n){
        if(n==1) return 2;
        vector< vector< vector<ll> > > dp(n , vector< vector<ll> >(2,vector<ll>(2,0)));
        // 0-w , 1-b
         // dp[i][1][0] -> i-1 && i-1->0
         dp[1][0][0]=1;
         dp[1][1][0]=1;
         dp[1][0][1]=1;
         dp[1][1][1]=1;
        for(ll i=2;i<n;i++){
                /*
                0 0 ->  1
                1 1 -> 0
                0 1 -> 0,1
                1 0 -> 1,0
                        */
                //
                dp[i][1][0] += dp[i-1][0][0];
                dp[i][1][0]%=mod;
               
               //
                dp[i][1][1] += dp[i-1][1][0];
                dp[i][1][1]%=mod;
               
                //
                dp[i][1][0] += dp[i-1][0][1]; 
                dp[i][1][0]%=mod;

               //
                dp[i][0][1]+=dp[i-1][1][1];
                dp[i][0][1]%=mod;
               
               //
                dp[i][0][1]+=dp[i-1][1][0];
                dp[i][0][1]%=mod;
               
               //
                dp[i][0][0]+=dp[i-1][0][1];
                dp[i][0][0]%=mod;
        }
        ll ans=0;
        ans+=dp[n-1][0][0];
        ans%=mod;

        ans+=dp[n-1][0][1];
        ans%=mod;

        ans+=dp[n-1][1][0];
        ans%=mod;

        ans+=dp[n-1][1][1];
        ans%=mod;
        
        return ans;
}
int main(){
        IOS;
        ll n,m;
        cin>>n>>m;
        ll a1=calc(n);
        ll b1=calc(m);
        
        ll ans=0;
        ans+=(a1+b1)%mod;
        ans=(ans-2+mod)%mod;
        cout<<ans<<"\n";
}
