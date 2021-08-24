#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll N=1e5+11;
ll n,m;
bool vis[N];
vector<ll> v[N],path;
// person can move at visited edge more than once
void bfs(ll node){
        priority_queue< ll ,vector<ll> ,greater<ll> > d;
        d.push(node);
        while(!d.empty()){
                ll cur= d.top();
                d.pop();
                path.push_back(cur);
                vis[cur]=1;
                for(auto child:v[cur]){
                        if(!vis[child]) {
                                vis[child]=1;
                                d.push(child);
                        }
                }
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
        bfs(1);
        for(ll i=0;i<(int)path.size();i++) cout<<path[i]<<" ";
        cout<<"\n";
}
