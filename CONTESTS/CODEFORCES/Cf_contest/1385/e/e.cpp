#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define mp make_pair
#define mt make_tuple
#define get(x,c) get<x>(c)
#define trav(a,x) for(auto a=x.begin();a!=x.end();a++)
#define rep(i,n) for(int i=0;i<n;i++)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define f first
#define s second

inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 2e5 + 11;
set<ll> v[N],edges[N];
bool vis[N];
ll tym,dep[N],id[N],n,m;
vll topo,drct[N];
void dfs1(ll node){
    vis[node]=1;
    for(auto child: drct[node]){
        if(!vis[child]) dfs1(child);
    }
    topo.pb(node);
}
void dfs2(ll node){
    vis[node] = 1;
    for(auto child : edges[node]){
        if(!vis[child]) dfs2(child);
    }
    dep[node] = tym++;
}
bool isdag(){
    for(ll i=1;i<=n;i++){
        ll t1=dep[i];
        for(auto child:edges[i]){
            ll t2=dep[child];
            if(t2>t1) return false;
        }
    }
    return true;
}

void solve(){
    rep(i,n+1) vis[i]=id[i]=dep[i]=0,v[i].clear(),drct[i].clear(),edges[i].clear();
    tym=0;n=0;m=0;
    topo.clear();

    cin>>n>>m;
    rep(i,m){
        ll type,x,y;
        cin>>type>>x>>y;
        if(type){
            v[x].insert(y);
            drct[x].pb(y);
            edges[x].insert(y);
        }
        else{
            v[x].insert(y);
            v[y].insert(x);
        }
    }
    for(ll i=1;i<=n;i++){
        if(!vis[i]) dfs1(i);
    }
    reverse(all(topo));
    rep(i,n) id[i+1]=-1,vis[i+1]=0;
    rep(i,sz(topo)) id[topo[i]]=i;

    for(ll i=1;i<=n;i++){
        ll p=i;
        for(auto child:v[p]){
            auto it1=v[child].find(p);
            auto it2=v[p].find(child);
            if(it1!=v[child].end() && it2!=v[p].end()){
                if(id[p]>id[child]){
                    edges[child].insert(p);
                }
                else{
                    edges[p].insert(child);
                }
            }
        }
    }
    for(ll i=1;i<=n;i++) if(!vis[i]) dfs2(i);

    if(isdag()){
        cout<<"YES\n";
        for(ll i=1;i<=n;i++){
            trav(it,edges[i]) cout<<i<<" "<<*it<<"\n";
        }
        nl;
    }
    else cout<<"NO\n";
}
int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    ll NTC=1;
    cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        cout<<"\n";
    }
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}
