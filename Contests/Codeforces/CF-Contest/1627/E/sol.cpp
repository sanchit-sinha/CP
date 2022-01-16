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

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5 + 11;
ll n, m, k;
map < pll, vector<pair<pll, ll>>> v;
ll x[N];
set <ll> states[N];
set<ll> ls[N], le[N];

void solve() {
    // clear
    v.clear();
    rep(i, n + 1) {
        x[i] = 0;
        states[i].clear();
        ls[i].clear();
        le[i].clear();
    }

    cin >> n >> m >> k;
    FOR(i, 1, n) cin >> x[i];

    rep(i, k) {
        ll a, b, c, d, h;
        cin >> a >> b >> c >> d >> h;

        states[a].insert(b); // start
        ls[a].insert(b);

        states[c].insert(d); // end
        le[c].insert(d);

        v[ {c, d}].pb({{a, b}, h}); // going down
    }

    auto isstart = [&](ll i, ll x) {
        auto it = ls[i].find(x);
        return (it != ls[i].end());
    };

    auto isend = [&](ll i, ll x) {
        auto it = le[i].find(x);
        return (it != le[i].end());
    };


    le[1].insert(1);
    states[1].insert(1);

    states[n].insert(m);
    ls[n].insert(m);

    map<pair<pll, ll>, ll> dp;
    dp[ {{n, m}, 0}] = 0;
    FORR(i, n, 1) {
        // use ls to get ans of le
        multiset<ll> lp, rm;
        for (auto &p : ls[i]) {
            if (dp.count({{i, p}, 0})) rm.insert(dp[ {{i, p}, 0}] - p * x[i]);
        }

        for (auto &p : states[i]) {
            if (isstart(i, p)) {
                // use starting point
                if (dp.count( {{i, p}, 0})) {
                    lp.insert(dp[ {{i, p}, 0}] + p * x[i]);

                    auto it = rm.find(dp[ {{i, p}, 0}] - p * x[i]);
                    if (it != rm.end()) rm.erase(it);
                }
            }

            if (isend(i, p)) {
                ll mxl = -inf;
                if (sz(lp)) mxl = *lp.rbegin();

                ll mxr = -inf;
                if (sz(rm)) mxr = *rm.rbegin();

                ll mxx = -inf;
                if (mxl != -inf) mxx = max(mxx, mxl - p * x[i]);
                if (mxr != -inf) mxx = max(mxx, mxr + p * x[i]);

                // le
                if (dp.count({{i, p}, 1})) dp[ {{i, p}, 1}] = max(dp[ {{i, p}, 1}], mxx);
                else {
                    if (mxx != -inf) dp[ {{i, p}, 1}] = mxx;
                }
            }

        }

        if (i > 1) {
            // use cur le to update ls of row beneath
            for (auto &p : le[i]) {
                for (auto &child : v[ {i, p}]) {
                    ll x = child.f.f, y = child.f.s, cost = child.s;
                    if (dp.count({{i, p}, 1})) {
                        ll mx = dp[ {{i, p}, 1}] + cost;

                        // ls
                        if (dp.count({{x, y}, 0})) dp[ {{x, y}, 0}] = max(dp[ {{x, y}, 0}], mx);
                        else {
                            if (mx != -inf) dp[ {{x, y}, 0}] = mx;
                        }
                    }
                }
            }
        }

    }

    ll ans = -inf;
    if (dp.count({{1, 1}, 1})) ans = dp[ {{1, 1}, 1}];

    ans = -1ll * (ans);
    if (ans == inf) cout << "NO ESCAPE\n";
    else cout << ans << "\n";

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
