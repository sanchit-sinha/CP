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
                ll n,k;
                cin>>n>>k;
                ll x[n],y[n];
                vector<ll> v;
                for(ll i=0;i<n;i++)
                        cin>>x[i],v.push_back(x[i]);
                for(ll i=0;i<n;i++)
                        cin>>y[i];
                sort(v.begin() , v.end());
                vector< vector<ll > > dp(n , vector<ll>(2,0));
                // dp[i][1]-> mx number of points saved with i as the last element placed on the road;
                dp[0][0]=0;
                dp[0][1]=1;
                for(ll i=1;i<n;i++){
                        ll index1=i;
                        ll val=v[i];
                        ll index2;
                        auto it=lower_bound(v.begin() , v.end() , val-k);
                        if(it == v.end()) index2=index1;
                        else index2=(it)-v.begin();
                        dp[i][1]=index1-index2+1;
                        dp[i][0]=max(dp[i-1][0] , dp[i-1][1]);
                }

                ll ans=0;
                for(ll i=0;i<n;i++){
                        ll saved=0;
                        saved+=dp[i][1];
                        ll index=i-saved;
                        if(index>=0){
                                saved+=max(dp[index][1] , dp[index][0]);
                        }
                        ans=max(ans,saved);
                }
                cout<<ans<<"\n";
        }    
}