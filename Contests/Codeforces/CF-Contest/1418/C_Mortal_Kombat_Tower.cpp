#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}


int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                ll n;
                cin>>n;
                ll a[n+11];
                for(ll i=0;i<n;i++) cin>>a[i];
                vector<vector<ll>>dp(n+11 , vector<ll>(2,0));
                // dp[i][j] ans by beating beasts from 0 to i by jth person
             
                // base
                ll i=0;
                dp[i][0] = a[i];
                dp[i][1] = LLONG_MAX;

                i=1;
                dp[i][0] = a[i]+a[i-1];
                dp[i][1] = dp[i-1][0];
                
                i=2;
                //012
                dp[i][0]=dp[i-1][1]+a[i];
                dp[i][1]=min(dp[i-1][0] , dp[i-2][0]);    
             
                //transition
                for(ll i=3;i<n;i++){
                        dp[i][0] = min(dp[i-1][1] + a[i], dp[i-2][1] + a[i] + a[i-1]);
                        dp[i][1] = min(dp[i-1][0] , dp[i-2][0]);
                }
                cout<<min(dp[n-1][0] , dp[n-1][1])<<"\n";
        }    
}