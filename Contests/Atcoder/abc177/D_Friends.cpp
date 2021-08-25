#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll N=2e5+1;
ll n,m;
vector<ll> v[N];
bool vis[N];
ll ct=0;
void dfs(ll node){
        vis[node]=1;
        ct++;
        for(auto child:v[node]){
                if(!vis[child]) dfs(child);
        }
}

int main(){
        IOS;
        cin>>n>>m;
        for(ll i=0;i<m;i++){
                ll x,y;
                cin>>x>>y;
                v[x].push_back(y);
                v[y].push_back(x);
        }        
        ll ans=LLONG_MIN;
        for(ll i=1;i<=n;i++){
                if(!vis[i]){
                        ct=0;
                        dfs(i);
                        ans=max(ans,ct);
                }
        }
        cout<<ans<<"\n";
}
