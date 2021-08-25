#include "bits/stdc++.h"
using namespace std;
#define f                   first
#define s                   second
#define pb                  push_back
#define ll                  long long
#define ld                  long double
#define lb                  lower_bound
#define ub                  upper_bound
#define mp                  make_pair
#define mt                  make_tuple
#define pll                 pair<ll , ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (int)(c.size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

inline ll gcd(ll a,ll b) {if(b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a,ll b) {return((a > b) ? a : b);}
inline ll min(ll a,ll b) {return((a > b) ? b : a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 2500+11;
ll n , m;
vpll v[N];
ll dis[N] , parent[N];
vll cycle;
// finding (shortest path from a source + negative cycle reachable from source) in a directed graph ~O(nm)
void bellman_ford(ll node){
    FOR(i , 0 , n) dis[i] = 0;
    dis[node] = 0;
    ll cycle_node = -1;
    FOR(i , 1 , n){
        cycle_node = -1;
        FOR(j , 0 , n){
            ll from = j;
            for(auto child : v[from]){
                ll to = child.f;
                ll len = child.s;

                if(dis[from] < inf){
                    if(dis[from] + len < dis[to]){
                        dis[to] = max(-inf , dis[from] + len);
                        parent[to] = from;
                        cycle_node = to;
                    }
                }
            }
        }
    }

    if(cycle_node != -1){
        rep(i , n) cycle_node = parent[cycle_node];
        for(ll i = cycle_node ; ; i = parent[i]){
            cycle.pb(i);
            if(i == cycle_node && sz(cycle) > 1) break;
        }
        reverse(all(cycle));
    }
}
void solve(){
    cin >> n >> m;
    rep(i , m){
        ll x , y , w;
        cin >> x >> y >> w;
        v[x].pb({y , w});
    }

    // convert the disconnected graph into connected one, by adding a new zero weighted edge connecting all the nodes
    FOR(i , 1 , n) v[0].pb({i , 0});
    bellman_ford(0);

    if(sz(cycle)){
        cout << "YES\n";
        rep(i , sz(cycle)) cout << cycle[i] << " ";
        cout << "\n";
    }
    else cout << "NO\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
   
    ll NTC=1;
    // cin>>NTC;

    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        factorial();
    #endif 
    #ifdef PREPROCESS
        preprocess();
    #endif
    
    ll PTC=0;
    while((PTC++)<NTC){
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
