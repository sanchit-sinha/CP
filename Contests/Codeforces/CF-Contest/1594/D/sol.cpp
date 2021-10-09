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

// considering graph to be `undirected` simplified the issue for positions having fixed colour
const ll N = 2e5 + 11;
ll n, m, col[N], vis[N];
vpll v[N];

ll predict(ll oldC, ll wt) {
    if (wt == 0) return oldC ^ 1;
    else return oldC;
}

bool dfs(ll node, ll pr, ll c, vll &ct) {
    ct[c]++, col[node] = c, vis[node] = 1;
    for (auto &x : v[node]) {
        ll child = x.first, wt = x.second, predictCol = predict(col[node], wt);
        if (!vis[child]) {
            if (dfs(child, node, predictCol, ct)) return 1;
        }
        else {
            if (col[child] != predictCol) return 1;
        }
    }

    return 0;
}
void solve() {
    // clear
    rep(i, n + 1) {
        vis[i] = col[i] = 0;
        v[i].clear();
    }

    cin >> n >> m;
    rep(i, m) {
        ll x, y; string s;
        cin >> x >> y >> s;
        ll w = (s == "imposter") ? 0 : 1;
        v[x].pb({y, w}), v[y].pb({x, w});
    }

    ll ans = 0ll;
    FOR(i, 1, n) {
        if (!vis[i]) {
            vll ct(2, 0); bool ok = dfs(i, i, 0, ct);
            debug(i, ct);
            if (ok) {
                cout << -1 << "\n"; return;
            }
            else ans += max(ct[0], ct[1]);
        }
    }

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
