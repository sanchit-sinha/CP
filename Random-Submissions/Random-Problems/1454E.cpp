#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include "bits/stdc++.h"
using namespace __gnu_pbds;
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
#define getT(x,c)           get<x>(c)
#define trav(a,x)           for(auto a = (x).begin(); a != (x).end(); a++)
#define rep(i, n)           for(ll i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(ll i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(ll i = (b); i >= (a); i--)

#ifdef LOCAL
bool DEBUGG = 1;
#include "debug.cpp"
#else
bool DEBUGG = 0;
#define debug(...) 42
#define cerr if(false) cerr
#endif

inline ll gcd(ll a, ll b) { if (b == 0) return a; a %= b; return gcd(b, a); }
inline ll max(ll a, ll b) { return ((a > b) ? a : b); }
inline ll min(ll a, ll b) { return ((a > b) ? b : a); }
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 4e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;


void solve() {
    ll n;
    cin >> n;

    vvll v(n + 1);
    vector<bool> vis(n + 1);
    vll pr(n + 1, 0ll);
    ll cs = -1, ce = -1;

    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    ll cnt = 0ll;
    function < void(ll, ll)> dfs = [&](ll node, ll p) {
        cnt++;
        pr[node] = p; vis[node] = 1;
        for (auto& child : v[node]) {
            if (child != p) {
                if (!vis[child]) {
                    dfs(child, node);
                }
                else {
                    // child -> p 
                    cs = child, ce = node;
                }
            }
        }
    };
    dfs(1ll, 0ll);
    rep(i, n) vis[i + 1] = 0;

    vll cycl;
    while (cs != ce) {
        cycl.pb(cs);
        cs = pr[cs];
    }
    cycl.pb(ce);

    debug(cycl);
    for (auto& x : cycl) vis[x] = 1;

    ll ans = (n * (n - 1));
    // simple path: no vertex is repeated
    for (auto& x : cycl) {
        ll node = x;
        ll tot = 0ll;
        for (auto& child : v[node]) {
            if (!vis[child]) {
                cnt = 0ll;
                dfs(child, 0);
                debug(child, cnt);
                tot += cnt;
            }
        }
        tot += 1ll;
        ans -= (tot * (tot - 1)) / 2;
    }

    cout << ans << "\n";
}

int main() {
#ifdef ERROR
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

ll power(ll x, ll y) { if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex, ll md) { ll ans = 1ll; while (ex > 0) { if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md; } return ans; }

