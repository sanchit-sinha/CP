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
    ll n, q;
    cin >> n >> q;

    vector<vpll> adj(n + 2);
    vvll ans(n + 1, vll(34, -1));
    rep(i, q) {
        ll x, y, w;
        cin >> x >> y >> w;

        if (x == y) {
            rep(j, 32) {
                if ((1ll << j) & w) ans[x][j] = 1;
                else ans[x][j] = 0;
            }
            debug(ans[x]);
        }
        else {
            adj[x].pb({ y, w });
            adj[y].pb({ x, w });
        }
    }

    debug(adj);

    FOR(i, 1, n) {
        for (auto& x : adj[i]) {
            ll j = x.f, w = x.s;
            rep(k, 32) {
                if ((1ll << k) & w);
                else ans[i][k] = 0;
            }
        }
    }

    FOR(i, 1, n) {
        rep(k, 32) {
            if (ans[i][k] == 0 || ans[i][k] == 1) continue;
            bool zero = 1;
            for (auto& x : adj[i]) {
                ll j = x.f, w = x.s;
                if ((1ll << k) & w) {
                    if (ans[j][k] == 0) zero = 0;
                }
            }

            if (zero) ans[i][k] = 0;
            else ans[i][k] = 1;
        }
    }

    FOR(i, 1, n) {
        ll x = 0ll;
        rep(j, 32) if (ans[i][j] == 1) x += (1ll << j);
        cout << x << " ";
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

