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

const ll N = 2e5 + 11;
set<ll> v[N];
ll dis[N], prnt[N], n;

void dfs(ll node, ll parent = 0, ll d = 0) {
    prnt[node] = parent;
    dis[node] = d;
    for (auto child : v[node]) {
        if (child != parent) {
            dfs(child, node, d + 1);
        }
    }
}
void solve() {
    cin >> n;
    rep(i, n - 1) {
        ll x, y;
        cin >> x >> y;
        v[x].insert(y);
        v[y].insert(x);
    }

    dfs(1);

    ll mxnode = -1, mx = 0ll;
    FOR(i, 1, n) {
        if (dis[i] >= mx) {
            mx = dis[i], mxnode = i;
        }
    }

    ll a = mxnode;
    FOR(i, 1, n) prnt[i] = dis[i] = 0;
    dfs(a);

    mx = 0ll, mxnode = -1;
    FOR(i, 1, n) {
        if (i == a) continue;
        if (dis[i] >= mx) {
            mx = dis[i], mxnode = i;
        }
    }
    ll b = mxnode;

    ll node = b;
    vll path;
    while (node) {
        ll x = node, pr = prnt[x];
        if (pr) {
            auto it1 = v[x].find(pr);
            if (it1 != v[x].end()) v[x].erase(it1);

            auto it2 = v[pr].find(x);
            if (it1 != v[pr].end()) v[pr].erase(it2);

        }
        path.pb(node);
        node = prnt[node];
    }
    debug(path);

    FOR(i, 1, n) prnt[i] = dis[i] = 0;
    rep(i, sz(path)) {
        if (dis[path[i]] == 0) {
            dfs(path[i]);
        }
    }

    ll c = -1, mx2 = 0ll;
    FOR(i, 1, n) {
        if (i == a || i == b) continue;
        if (dis[i] >= mx2) {
            mx2 = dis[i];
            c = i;
        }
    }

    cout << mx + mx2 << "\n";
    cout << a << " " << b << " " << c << "\n";
}

int main() {
#ifdef ERROR
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

ll power(ll x, ll y) { if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex, ll md) { ll ans = 1ll; while (ex > 0) { if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md; } return ans; }

