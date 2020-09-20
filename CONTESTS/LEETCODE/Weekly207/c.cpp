#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

class Solution {
public:
        int maxProductPath(vector<vector<int>>&a) {
                ll mod=1e9+7;
                
                ll n=(int)a.size();
                ll m=(int)a[0].size();
                
                vector< vector< vector<ll> > > dp(n+1 , vector<vector<ll> >(m+1 , vector<ll>(2 , 0)));
                
                // 0 move right , 1 move down
                //base 
                ll i=0,j=0;
                for(ll j=0;j<m;j++){
                        if(j==0) dp[i][j][0]=a[i][j];
                        else dp[i][j][0] = dp[i][j-1][0] * a[i][j];
                }

                i=0,j=0;
                for(ll i=0;i<n;j++){
                        if(i==0) dp[i][j][1]=a[i][j];
                        else dp[i][j][1] = dp[i-1][j][1] * a[i][j];
                }
                
                
                for(ll i=1;i<n;i++){
                        for(ll j=1;j<m;j++){
                                dp[i][j][0] = a[i][j] * d
                        }
                }

                ll ans=dp[n-1][m-1];
                if(ans<0) return -1;
                else return (ans%mod + mod)%mod;
        }
};