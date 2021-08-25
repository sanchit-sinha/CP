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
ll n, m;
vll v[N];
ll cycle_start, cycle_end;
ll colour[N], parent[N];
vll cycle;
bool dfs(ll node,ll par){
    colour[node] = 1;
    for(auto child :v[node]){
        if(child == par) continue;
        else{
            if(colour[child] == 0){
                parent[child] = node;
                if(dfs(child, parent[child])) return true;
            }
            else if(colour[child] == 1){
                cycle_end = node;
                cycle_start = child;
                return true;                
            }
        }
    }
    colour[node] = 2;
    return false;
}
bool find_cycle(){
    memset(parent, -1, sizeof(parent));
    memset(colour, 0, sizeof(colour));
    cycle_start = -1;
    // n : number of vertices ( 1 - indexed)
    for(ll i = 1; i <= n; i++){
        if(colour[i] == 0){
            if(dfs(i, parent[i])) break;
        }
    }

    if(cycle_start == -1){
        // not found any cycle
        return false;
    }
    else{
        // found cycle
        cycle.pb(cycle_start);
        for(ll i = cycle_end ; i != cycle_start ; i = parent[i]){
            cycle.pb(i);
        }
        cycle.pb(cycle_start);
        reverse(all(cycle));

        return true;
    }
}
void solve(){
    cin >> n >> m;
    rep(i , m){
        ll x , y;
        cin >> x >> y;

        v[x].pb(y);
        v[y].pb(x);
    }

    find_cycle();
    vll ans = cycle;
    if(sz(ans)){
        cout << sz(ans) << "\n";
        rep(i , sz(ans)) cout << ans[i] << " ";
        cout << "\n";
    }
    else cout << "IMPOSSIBLE\n";
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
