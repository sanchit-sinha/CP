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

const ll N = 2e5 + 11;
ll n;
vll v[N], topo;
ll dis[N], indegree[N];

void dfs() {
    rep(i, n) {
        ll node = i + 1;
        debug(v[node]);
        for (auto child : v[node]) {
            indegree[child]++;
        }
    }

    rep(i, n) {
        if (!indegree[i + 1]) topo.pb(i + 1);
    }

    ll cur = 0ll;
    while (cur < sz(topo)) {
        ll node = topo[cur++];
        for (auto child : v[node]) {
            if (--indegree[child] == 0) topo.pb(child);
        }
    }
}
void solve() {
    // clear
    rep(i, n + 1) {
        v[i].clear();
        dis[i] = indegree[i] = 0;
    }
    topo.clear();

    cin >> n;
    rep(i, n) {
        ll len;
        cin >> len;

        rep(j, len) {
            ll x;
            cin >> x;
            v[x].pb(i + 1);
        }
    }

    dfs();
    if (sz(topo) != n) {
        cout << -1 << "\n";
        return;
    }

    debug(topo);
    rep(i, n) {
        ll node = topo[i];
        for (auto child : v[node]) {
            if (node > child) dis[child] = max(dis[child], dis[node] + 1);
            else dis[child] = max(dis[child], dis[node]);
        }
    }

    ll ans = 0ll;
    rep(i, n) ans = max(ans, dis[i + 1]);
    cout << ans + 1 << "\n";
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
