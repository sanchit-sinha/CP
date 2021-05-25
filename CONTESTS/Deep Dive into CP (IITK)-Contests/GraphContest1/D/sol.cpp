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

const ll N = 1e5+11;
ll n , k;
ll sz[N];
ll parent[N];
void make_set(ll node){
    parent[node] = node;
    sz[node] = 1;
}
ll find_set(ll a){
    if(a == parent[a]) return a;
    return parent[a] = find_set(parent[a]);
}
void union_set(ll a , ll b){
    ll p1 = find_set(a);
    ll p2 = find_set(b);
    if(p1 != p2){
        if(sz[p2] > sz[p1]) swap(p1 , p2);
        parent[p2] = p1;
        sz[p1] += sz[p2];
    }
}

void solve(){
    cin >> n >> k;

    FOR(i , 1 , n) make_set(i);
    rep(i , n - 1){
        ll u , v , c;
        cin >> u >> v >> c;
        if(c == 0) union_set(u, v);
    }     

    ll ans = (powermod(n, k, mod) - n + mod)%mod;
    set<ll> p;
    FOR(i , 1 , n) p.insert(find_set(i));

    trav(it , p){
        ll pr = *it;
        ll len = sz[pr];

        ll val = (powermod(len, k , mod) - len + mod)%mod;

        ans -= val;
        ans += mod;
        ans %= mod;
    }

    cout << ans << "\n";
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
