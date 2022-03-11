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
ll n, m, s, t;
vll v[N];

void solve() {
    // clear
    rep(i, n + 1) v[i].clear();

    cin >> n >> m;
    cin >> s >> t;

    rep(i, m) {
        ll x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    vll dist(n + 1, inf);
    vvll dp(n + 1, vll(2, 0ll));
    set<pll> q;

    q.insert({ 0,s });
    dist[s] = 0;
    dp[s][0] = 1, dp[s][1] = 0;

    vector<vector<bool>> vis(n + 1, vector<bool>(2, 0));
    vis[s][0] = 1;

    while (!q.empty()) {
        auto p = *q.begin();
        ll node = p.s, d = p.f;
        q.erase(q.begin());
        debug(node);

        for (auto& child : v[node]) {
            debug(child);
            if (!vis[child][0]) {
                q.insert({ d + 1,child });
                vis[child][0] = 1;
            }

            if (dist[child] > dist[node] + 1) {
                dp[child][0] = dp[node][0];
                dp[child][1] = dp[node][1];
                dist[child] = dist[node] + 1;
            }
            else if (dist[child] == dist[node] + 1) {
                if (!vis[node][1]) dp[child][0] += dp[node][0];
                if (vis[node][1]) dp[child][1] += dp[node][1];
            }

            dp[child][0] %= mod;
            dp[child][1] %= mod;
        }

        if (!vis[node][1]) {
            for (auto& child : v[node]) {
                if (dist[child] == dist[node]) {
                    dp[node][1] += dp[child][0];
                    dp[node][1] %= mod;

                    q.insert({ dist[node],node });
                }
            }
            vis[node][1] = 1;
        }
        debug(node, dp);
    }

    ll ans = dp[t][0] + dp[t][1];
    ans %= mod;

    if (DEBUGG) {
        FOR(i, 1, n) {
            cerr << i << ": " << dist[i] << " ( " << dp[i][0] << " " << dp[i][1] << ") \n";
        }
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

