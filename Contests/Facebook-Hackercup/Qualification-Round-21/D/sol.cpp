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
#define pll                 pair<ll , ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (ll)((c).size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(ll i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(ll i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(ll i = (b); i >= (a); i--)

#ifdef LOCAL
#include "debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#define cerr if(false) cerr
#endif


inline ll gcd(ll a, ll b) {if (b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a, ll b) {return ((a > b) ? a : b);}
inline ll min(ll a, ll b) {return ((a > b) ? b : a);}
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 53;
ll pathvalue[N];
ll c[N];
vll v[N];
bool vis[N];
vector<set<ll>> paths;
set<ll> s;
ll n;
ll val = 0ll;
ll indexx = 0ll;

void dfs(ll node) {
    vis[node] = 1;

    bool enter = 0;
    for (auto child : v[node]) {
        if (!vis[child]) {
            s.insert(child);
            val += c[child];
            enter = 1;

            dfs(child);

            s.erase(s.find(child));
            val -= c[child];
        }
    }

    if (!enter) {
        paths.pb(s);
        pathvalue[indexx] = val;
        indexx++;
    }

}
void solve() {
    // clear
    rep(i, n + 1) {
        pathvalue[i] = 0;
        c[i] = 0;
        v[i].clear();
        vis[i] = 0;
    }
    paths.clear();
    s.clear();
    n = val = 0ll;
    indexx = 0;

    cin >> n;
    rep(i, n) cin >> c[i + 1];

    rep(i, n - 1) {
        ll x, y;
        cin >> x >> y;

        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1);
    debug(paths);

    ll ans = 0ll;
    debug(indexx);
    // return;

    rep(i, indexx) {
        ll x = pathvalue[i] + c[1];
        debug(i, x);
        ans = max(ans, x);

        rep(j, indexx) {
            bool ok  = 1;
            if (i == j) ok = 0;
            if (i != j) {
                trav(it, paths[j]) {
                    ll node = *it;
                    auto itf = paths[i].find(node);
                    if (itf != paths[i].end()) ok = 0;
                }
            }

            if (ok) {
                ll y = pathvalue[j];
                debug(i, j, x + y);
                ans = max(ans, x + y);
            }
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
        cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
