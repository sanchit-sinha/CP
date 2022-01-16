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
#define pll                 pair<ll, ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (ll)((c).size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin(); a != x.end(); a++)
#define rep(i, n)           for(ll i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(ll i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(ll i = (b); i >= (a); i--)

#ifdef LOCAL
bool DEBUG = 1;
#include "debug.cpp"
#else
bool DEBUG = 0;
#define debug(...) 42
#define cerr if(false) cerr
#endif

inline ll gcd(ll a, ll b) {if (b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a, ll b) {return ((a > b) ? a : b);}
inline ll min(ll a, ll b) {return ((a > b) ? b : a);}
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 4e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5 + 11;
vll v[N];
ll n, indeg[N];
bool vis[N];
ll dis[N];
pll e[N];

void solve() {
// clear
    rep(i, n + 1) {
        v[i].clear();
        vis[i] = 0;
        dis[i] = indeg[i] = 0;
        e[i] = {0, 0};
    }

    cin >> n;
    map<pll , ll> m;
    rep(i, n - 1) {
        ll x, y;
        cin >> x >> y;

        e[i] = {x, y};
        m[ {x, y}] = i;
        m[ {y, x}] = i;

        v[x].pb(y);
        v[y].pb(x);

        indeg[x]++, indeg[y]++;
        debug(x, y);
    }

    vll o;
    bool ok = 1;
    FOR(i, 1, n) {
        if (indeg[i] == 1) o.pb(i);
        else if (indeg[i] == 2) ;
        else {
            cout << -1 << "\n";
            return;
        }
    }

    debug(o);

    if (sz(o) != 2) {
        cout << -1 << "\n";
        return;
    }

    vll ee;
    function < ll(ll, ll)> dfs = [&](ll node, ll pr) {
        vis[node] = 1;
        ll d = 0ll;
        for (auto &child : v[node]) {
            if (!vis[child]) {
                debug(node, child);
                ee.pb(m[ {node, child}]);

                ll x = dfs(child, node);
                d = max(d, x + 1);
            }
        }

        return dis[node] = d;
    };

    ll root = o[0];
    dis[root] = dfs(root, 0);


    vll ans(n - 1, 0);
    rep(i, n - 1) {
        if (i & 1) ans[ee[i]] = 2;
        else ans[ee[i]] = 3;
    }

    rep(i, n - 1) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
#ifdef LOCAL
    freopen("../error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);

    ll NTC = 1;
    cin >> NTC;

#ifdef PREPROCESS
    preprocess();
#endif
#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    factorial();
#endif

    ll PTC = 0;
    while ((PTC++) < NTC) {
        cerr << "Testcase # " << PTC << "\n";
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
