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

const ll N = 1e6 + 1;
ll arr[N], par[N], vis[N];
ll n, d;

ll calc(vll &v) {
    ll n = sz(v);
    vll dp(n, 0);

    rep(i, n) {
        if (v[i] == 1) dp[i] = 1;
        if (i) {
            if (v[i - 1] == 1) dp[i] += dp[i - 1];
        }
    }

    if (dp[n - 1] == n) return inf;


    ll ans = 0ll;
    rep(i, n) ans = max(ans, dp[i]);

    ll zr = 0;
    rep(i, n) {
        if (v[i] == 0) {
            zr = i;
            break;
        }
    }

    if (zr && v[n - 1] == 1) {
        ll ones = zr + dp[n - 1];
        ans = max(ans, ones);
    }

    return ans;
}
void solve() {
    // clear
    rep(i, n + 1) {
        par[i] = vis[i] = arr[i] = 0;
    }

    cin >> n >> d;
    rep(i, n) cin >> arr[i];

    rep(i, n) {
        ll to_replace = (i + n - d) % n;
        par[i] = to_replace;
        debug(i, to_replace);
    }

    vvll graph;
    if (DEBUG) {
        rep(i, n) cerr << par[i] << " ";
        cerr << "\n";
    }

    rep(i, n) {
        if (!vis[i]) {
            ll node = i;
            ll start = i;

            vll path;
            path.pb(arr[node]);
            vis[node] = 1;
            node = par[node];

            while (!vis[node] && node != start) {
                path.pb(arr[node]);
                vis[node] = 1;
                node = par[node];
            }
            graph.pb(path);
        }
    }
    ll ans = 0ll;
    rep(i, sz(graph)) {
        debug(graph[i]);
        ll x = calc(graph[i]);
        debug(x);
        ans = max(ans, x);
    }

    if (ans == inf) ans = -1;
    cout << ans << "\n";

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
