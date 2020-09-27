/**
 *    author:  Sanchit Sinha
 *    created: 26.09.2020 21:45:56       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
const ll N=1e5+11;
ll sz[N] , parent[N];
void make_set(ll node){
        parent[node] = node;
        sz[node] = 1;
}
ll find_set(ll a){
        if(a==parent[a]) return a;
        return parent[a]=find_set(parent[a]);
}
void union_set(ll a , ll b){
        ll p1=find_set(a);
        ll p2=find_set(b);
        if(p1!=p2){
                if(sz[p2]>sz[p1]) swap(p1,p2);
                parent[p2]=p1;
                sz[p1]+=sz[p2];
                sz[p2]=0;
        }
}
ll n,m;
int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin>>n>>m;
        for(ll i=1;i<=n;i++) make_set(i);
        for(ll i=0;i<m;i++){
                ll x,y;
                cin>>x>>y;
                union_set(x,y);
        }
        set<ll> p;
        for(ll i=1;i<=n;i++) {
                p.insert(find_set(i));
        }
        cout << (int)p.size() - 1<<"\n";
        return 0;
}
