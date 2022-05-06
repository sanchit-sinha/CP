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

    vll p(n + 1);
    FOR(i, 1, n) cin >> p[i];

    if (n == 1) {
        cout << 1 << "\n";
        cout << 1 << "\n";
        cout << 1 << "\n";
        cout << "\n";
        return;
    }

    vvll v(n + 1);
    ll root = -1;
    FOR(i, 1, n) {
        if (i == p[i]) root = i;
        v[p[i]].pb(i);
        v[i].pb(p[i]);
    }

    if (DEBUGG) {
        FOR(i, 1, n) {
            for (auto& x : v[i]) cerr << i << " " << x << "\n";
        }
    }

    vll leaf;

    function < void(ll, ll)> dfs = [&](ll node, ll pr) {
        bool enter = 0;
        for (auto& child : v[node]) {
            if (child != pr) {
                enter = 1;
                dfs(child, node);
            }
        }
        if (!enter) leaf.pb(node);
    };

    dfs(root, root);
    debug(root, leaf);

    vector<bool> vis(n + 1, 0ll);

    cout << sz(leaf) << "\n";
    while (sz(leaf)) {
        ll cur = leaf.back();
        leaf.pop_back();

        vll ans;
        while (cur != root && !vis[cur]) {
            ans.pb(cur);
            vis[cur] = 1;
            cur = p[cur];

            if (cur == root && vis[root] == 0) {
                ans.pb(root);
                vis[root] = 1;
            }
        }
        reverse(all(ans));
        cout << sz(ans) << "\n";
        for (auto& x : ans) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";
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

