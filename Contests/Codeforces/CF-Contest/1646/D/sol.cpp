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

const ll N = 2e5 + 11;
ll n;
pll dp[N][2]; // 0: good and 1: bad
// {max number of good vertices, minimum sum of weights of subtree}
vll v[N];
bool isgood(ll node) {
    auto pgood = dp[node][0], pbad = dp[node][1];
    if (pgood.f > pbad.f) return 1;
    else if (pgood.f < pbad.f) return 0;
    else {
        if (pgood.s < pbad.s) return 1;
        else return 0;
    }
}

void dfs(ll node, ll p = 0) {
    for (auto &child : v[node]) {
        if (child != p) dfs(child, node);
    }

    // current is good: all child will be bad
    // weight used here is eq to its neighbours
    dp[node][0].f = 1;
    if (node > 1) dp[node][0].s = 1;
    for (auto &child : v[node]) {
        if (child != p) {
            dp[node][0].f += dp[child][1].f;
            dp[node][0].s += dp[child][1].s + 1;
        }
    }


    // current is bad: child can be either good or bad
    dp[node][1].s = 1;
    for (auto &child : v[node]) {
        if (child != p) {
            if (isgood(child)) {
                dp[node][1].f += dp[child][0].f;
                dp[node][1].s += dp[child][0].s;
            }
            else {
                dp[node][1].f += dp[child][1].f;
                dp[node][1].s += dp[child][1].s;
            }
        }
    }
}

ll col[N];
void dfs2(ll node, bool good, ll p = 0) {
    if (good) {
        for (auto &child : v[node]) {
            col[node] ++;
        }
        // child will be bad
        for (auto &child : v[node]) {
            if (child != p) {
                dfs2(child, 0, node);
            }
        }
    }
    else {
        col[node] = 1;
        // child can be good or bad
        for (auto &child : v[node]) {
            if (child != p) {
                if (isgood(child)) dfs2(child, 1, node);
                else dfs2(child, 0, node);
            }
        }
    }
}
void solve() {
    cin >> n;
    rep(i, n - 1) {
        ll x, y;
        cin >> x >> y;
        v[x].pb(y), v[y].pb(x);
    }

    if (n == 2) {
        cout << 2 << " " << 2 << "\n";
        cout << 1 << " " << 1 << "\n";
        return;
    }

    dfs(1);
    if (DEBUG) {
        FOR(i, 1, n) {
            debug(i, dp[i][0]);
            debug(i, dp[i][1]);
        }
    }

    if (isgood(1)) {
        cout << dp[1][0].f << " " << dp[1][0].s << "\n";
        dfs2(1, 1);
    }
    else {
        cout << dp[1][1].f << " " << dp[1][1].s << "\n";
        dfs2(1, 0);
    }
    FOR(i, 1, n) cout << col[i] << " ";
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
    // cin >> NTC;

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
