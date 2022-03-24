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
const ll mod = 998244353;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 2e5 + 11;
#define SIEVE
const ll mx = N;
ll spf[mx + 3];
void sieve() { // O(mx)
    vector<int> pr;

    for (int i = 2; i <= mx; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= spf[i] && i * pr[j] <= mx; ++j) {
            spf[i * pr[j]] = pr[j];
        }
    }
}

map<ll, ll> fact(ll x) {
    map<ll, ll> f;
    while (x > 1) {
        ll div = spf[x], cnt = 0ll;
        while (x % div == 0) x /= div, cnt++;
        f[div] = cnt;
    }
    return f;
}

ll n, a[N];
map<ll, ll> m, mn;
vector<pair<ll, pll>> v[N];
bool vis[N];
// 60 16 

ll upd(ll node, ll den, ll num) {
    ll p = a[node] * num; p %= mod;
    p *= powermod(den, mod - 2, mod); p %= mod;
    return p;
}

void dfs(ll node) {
    vis[node] = 1;
    for (auto p : v[node]) {
        ll child = p.f;
        ll wf = p.s.f, ws = p.s.s;

        if (!vis[child]) {
            map<ll, ll> m1 = fact(ws), m2 = fact(wf);
            debug(wf, ws);
            for (auto& x : m1) m[x.f] += x.s;
            for (auto& x : m2) m[x.f] -= x.s;

            for (auto& x : m1) mn[x.f] = min(mn[x.f], m[x.f]);
            for (auto& x : m2) mn[x.f] = min(mn[x.f], m[x.f]);

            a[child] = upd(node, wf, ws);

            dfs(child);

            for (auto& x : m1) m[x.f] -= x.s;
            for (auto& x : m2) m[x.f] += x.s;
        }
    }
}
void solve() {
    // clear
    rep(i, n + 1) {
        v[i].clear();
        a[i] = 0;
        vis[i] = 0;
    }
    m.clear();
    mn.clear();

    cin >> n;
    rep(i, n - 1) {
        ll x, y, wf, ws;
        cin >> x >> y >> wf >> ws;

        ll g = gcd(wf, ws);
        wf /= g, ws /= g;

        v[x].pb({ y,{wf,ws} });
        v[y].pb({ x,{ws,wf} });
    }

    a[1] = 1ll;
    dfs(1);

    debug(mn);
    ll o = 0ll, ans = 1ll;
    FOR(i, 1, n) o += a[i], o %= mod;
    for (auto& x : mn) {
        ans *= powermod(x.f, -x.s, mod);
        ans %= mod;
    }
    debug(o, ans);

    ans *= o; ans %= mod;
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

