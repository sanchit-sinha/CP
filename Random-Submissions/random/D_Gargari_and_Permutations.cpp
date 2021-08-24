#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll N=1e3+11;
vector<ll> v[N];
bool vis[N];
ll ans=1,dis[N];
void dfs(ll node){
        vis[node]=1;
        ll len=(int)v[node].size();
        if(len){
                for(auto child:v[node]){
                        if(!vis[child]){
                                dfs(child);
                        }
                        dis[node]=max(dis[node], dis[child]+1);
                }
        }
        dis[node]=max(dis[node] , 1);
}
int main(){
        IOS;
        ll n,m;
        cin>>n>>m;
        vector< vector<ll> > a(m , vector<ll>(n,0));
        vector< vector<ll> > index(m , vector<ll>(n,0));
        for(ll i=0;i<m;i++){
                for(ll j=0;j<n;j++){
                        cin>>a[i][j];
                        a[i][j]--;
                        index[i][a[i][j]]=j;
                }
        }
        for(ll i=0;i<n;i++){
                for(ll j=i+1;j<n;j++){
                        ll x=a[0][i],y=a[0][j];
                        bool ok=1;
                        for(ll k=0;k<m;k++){
                                if(index[k][y] > index[k][x]) continue;
                                else ok=0;
                        }
                        if(ok) v[x].push_back(y);
                }
        }
        for(ll i=0;i<n;i++){
                if(!vis[i]) dfs(i);
        }
        for(ll i=0;i<n;i++) ans=max(ans,dis[i]);
        cout<<ans<<"\n";
}
