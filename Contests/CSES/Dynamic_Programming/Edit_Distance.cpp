#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll N=5e3+11;
ll dp[N][N];
string s,t;
int main(){
        IOS;
        cin>>s>>t;

        ll n=(int)s.size() , m=(int)t.size();
        // base
        for(ll i=1;i<=n;i++) dp[i][0]=i;
        for(ll j=1;j<=m;j++) dp[0][j]=j;
        for(ll i=1;i<=n;i++){
                for(ll j=1;j<=m;j++){
                        dp[i][j]=LLONG_MAX;
                        if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
                        else{
                                dp[i][j]=min({dp[i][j] , dp[i-1][j]+1 , dp[i][j-1]+1 , dp[i-1][j-1]+1});
                        }
                }
        }
        cout<<dp[n][m]<<"\n";
}
