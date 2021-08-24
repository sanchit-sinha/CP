#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}


int main(){
        IOS;
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>>a(m,vector<ll>(n,0));
        vector<vector<ll>>index(m,vector<ll>(n,0));
        vector<ll>dp(n,1);
        for(ll i=0;i<m;i++){
                for(ll j=0;j<n;j++){
                        cin>>a[i][j];
                        a[i][j]--;
                        index[i][a[i][j]]=j;
                }
        }        

        ll ans=1;
        for(ll i=1;i<n;i++){
                ll x=a[0][i];
                for(ll j=0;j<i;j++){
                        ll y=a[0][j];
                        bool ok=1;
                        for(ll k=1;k<m;k++){
                                if(index[k][y] < index[k][x]) continue;
                                else ok=0;
                        }
                        if(ok) dp[i]=max(dp[i],dp[j]+1);
                }
                ans=max(ans,dp[i]);
        }
        cout<<ans<<"\n";
}
