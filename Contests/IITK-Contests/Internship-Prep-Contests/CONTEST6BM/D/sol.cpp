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

string to_string(string s) {return '"' + s + '"';}string to_string(const char* s) {return to_string((string) s);}string to_string(bool b) {return (b ? "true" : "false");}template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A>string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}void debug_out() { cerr << "\n"; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n";debug_out(T...);} 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

inline ll gcd(ll a,ll b) {if(b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a,ll b) {return((a > b) ? a : b);}
inline ll min(ll a,ll b) {return((a > b) ? b : a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;
const ll N = 2e5 + 11;

ll n;
ll a[N];
vll v[N];
ll dis[N];
vll ct[30];
ll subtree[N];
ll prnt[N];
set<ll> prr;

void dfs(ll node , ll pr){
    for(auto child : v[node]){
        if(child != pr){
            dis[child] = dis[node] + 1;
            ll val = a[child];

            if(sz(ct[val])){
                ll closest = ct[val].back();
                prnt[child] = closest;
            }
            else prr.insert(child) , prnt[child] = child;

            ct[val].pb(child);
            dfs(child , node);
            ct[val].pop_back();
        }
    }
}

bool vis[N] ;
void calc(ll node){
    vis[node] = 1;
    for(auto child : v[node]){
        if(!vis[child]){
            calc(child);
            subtree[node] += subtree[child];
        }
    }
}
void solve(){
    // clear
    rep(i , n + 1){
        v[i].clear();
        subtree[i] = 0;
        prnt[i] = 0;
        a[i] = 0;
        vis[i] = 0;
        dis[i] = 0;
    }
    prr.clear();
    rep(j , 27) ct[j].clear();

    n = 0;


    // main 
    cin >> n;
    rep(i , n){
        char c;
        cin >> c;

        ll x = c - 'a' + 1;
        ll node = i + 1;

        a[node] = x;
        prnt[node] = node;
    }

    rep(i , n - 1){
        ll x , y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }


    ct[a[1]].pb(1);
    prr.insert(1);
    dfs(1 , 0);


    rep(i , n + 1) v[i].clear();
    FOR(i , 1 , n){
        if(i != prnt[i]) v[prnt[i]].pb(i);
    }


    FOR(i , 1 , n) subtree[i] = 1;
    trav(it , prr){
        if(!vis[*it]) calc(*it);
    }

    rep(i , n) cout << subtree[i + 1] << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
   
    ll NTC=1;
    cin>>NTC;

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
