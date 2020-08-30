#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

const ll N=5e5+11;
ll n,k,dp[N][2];
vector<pair<ll,ll>> v[N];
/* 
        dp[i][0 or 1]-> max value of k-colourings for subtree i if there is node between i and it's parent(1)
                                                         or if there is no such edge(0)
                                parent_node
                                    node                 --> need to calculate dp[node][0] and dp[node][1]
                        child1  child2  child3  child4   -->dp[child][0] , dp[child][1] ->is known

                                */
void dfs(ll node,ll parent){
        vector<ll> add;
        ll cur=0;
        for(auto &x:v[node]){
                ll child=x.first;
                ll wt=x.second;
                if(child != parent){
                        dfs(child,node);
                        cur+=dp[child][0];
                        add.push_back(dp[child][1] + wt - dp[child][0]);
                }
        }
        sort(add.begin() , add.end() , greater<ll>());
        ll len=(int)add.size();
        for(ll i=0;i<min(len,k);i++){
                if(add[i]>0) cur+=add[i];
        }
        dp[node][0]=dp[node][1]=cur;
        if(k-1<len && add[k-1]>0) dp[node][1]-=add[k-1];
}
int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                // clear
                for(ll i=0;i<n+1;i++) dp[i][0]=dp[i][1]=0 , v[i].clear();

                cin>>n>>k;
                for(ll i=0;i<n-1;i++){
                        ll x,y,w;
                        cin>>x>>y>>w;
                        v[x].push_back({y,w});
                        v[y].push_back({x,w});
                }           
                dfs(1,0);
                cout<<max(dp[1][1] , dp[1][0])<<"\n";     
        }    
}