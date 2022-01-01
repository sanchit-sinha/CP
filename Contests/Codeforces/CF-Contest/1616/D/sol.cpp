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


vll LOL(vll &v) {
    ll n = sz(v);

    stack<pll> stk;
    vll index(n, -1);

    stk.push({v[0], 0});
    FOR(i, 2, n - 1) {
        ll x = v[i];

        vpll temp;
        while (!stk.empty() && stk.top().f <= x) temp.pb(stk.top()), stk.pop();

        if (stk.empty()) index[i] = -1;
        else {
            index[i] = stk.top().second;
        }

        FORR(k, sz(temp) - 1, 0) stk.push(temp[k]);

        // add v[i - 1]
        x = v[i - 1];
        while (!stk.empty() && stk.top().f <= x) temp.pb(stk.top()), stk.pop();
        stk.push({v[i - 1], i - 1});
    }

    return index;
}

void solve() {
    ll n;
    cin >> n;

    vll a(n + 1);
    rep(i, n) cin >> a[i + 1];

    ll x;
    cin >> x;

    vll pfx(n + 1, 0);
    rep(i, n) {
        pfx[i + 1] = pfx[i] + a[i + 1];
    }

    debug(pfx);
    if (DEBUG) {
        FOR(i, 1, n) {
            FOR(j, i + 1, n) {
                ll xx = pfx[j] - pfx[i - 1];

                if (xx < x * (j - i + 1)) {
                    cerr << i << " " << j << ": " << pfx[j] << " " << pfx[i - 1] << "\n";
                }
            }
        }
    }

    rep(i, n + 1) pfx[i] -= x * (i);

    debug(pfx);
    vll index = LOL(pfx);
    debug(index);

    vpll seg;
    rep(i, n + 1) {
        if (index[i] != -1) {
            debug(index[i] + 1, i);
            seg.pb({i, index[i] + 1});
        }
    }

    sort(all(seg));
    debug(seg);

    ll len = sz(seg);
    if (len == 0) {
        cout << n << "\n";
        return;
    }

    // max non overlapping segments
    ll ans = 1ll;
    pll prev = {seg[0].s, seg[0].f};
    FOR(i, 1, len - 1) {
        ll l = seg[i].s, r = seg[i].f;
        // cur l > prevr
        if (l > prev.s) {
            ans++;
            prev = {l, r};
        }
    }

    debug("non overlapping", ans);

    cout << n - ans << "\n";
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
