/**
 *    Author:  Sanchit Sinha
 *    Created: 26.10.2020 02:28:45       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll N=2e5+11;
ll n,m,dep[N],tym;
vector<ll> v[N],nodes;
bool vis[N];
void dfs(ll node){
    vis[node]=1;
    nodes.push_back(node);
    for(auto child:v[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
    dep[node]=tym++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            ll ct=0;
            ll len=(int)(nodes.size());
            for(ll j=0;j<len;j++) cout<<nodes[j]<<" ";
            cout<<"\n";
            for(ll j=0;j<len;j++){
                ll root=nodes[j];
                for(auto child:v[root]){
                    if(dep[child]>dep[root]) ct++;
                }
            }
            if(ct==1){
                cout<<" this is it\n";
                ans++;
            }
            nodes.clear();
        }
    }
    cout<<ans<<"\n";
    return 0;
}
