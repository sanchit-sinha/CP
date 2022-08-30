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

#define int long long

void solve() {
    int n;
    cin >> n;

    vll a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    map<ll, ll> ma, mb;
    rep(i, n) ma[a[i]] = i;
    rep(i, n) mb[b[i]] = i;

    vpll d;
    function < void(int, vll&, vll&, int)> place = [&](int bt, vll& x, vll& y, int type) {
        debug(bt, x, y, type);
        if (sz(x) == 0 || sz(y) == 0) return;

        if (type == 0 && sz(x) == 1) {
            d.pb({ x[0], y[0] });
            return;
        }
        if (type == 1 && sz(x) == 1) {
            d.pb({ y[0], x[0] });
            return;
        }
        if (bt == -1) return;

        vll x0, x1, y0, y1;
        for (auto& xx : x) {
            if ((1ll << bt) & xx) x1.pb(xx);
            else x0.pb(xx);
        }

        for (auto& xx : y) {
            if ((1ll << bt) & xx) y1.pb(xx);
            else y0.pb(xx);
        }

        if (bt <= 1) {
            debug(x0, y1);
            debug(y0, x1);
        }

        if (sz(x1) < sz(y0) || sz(y1) < sz(x0)) {
            place(bt - 1, x, y, type);
        }
        else {
            if (sz(x0)) place(bt - 1, x0, y1, type);
            if (sz(y0)) place(bt - 1, y0, x1, type ^ 1);
        }

        return;
    };
    place(31, a, b, 0);
    debug(d);


    multiset<ll> sa, sb;
    rep(i, n) sa.insert(a[i]);
    rep(i, n) sb.insert(b[i]);

    vll xr;
    for (auto& x : d) {
        auto ita = sa.find(x.f);
        if (ita != sa.end()) sa.erase(ita);

        auto itb = sb.find(x.s);
        if (itb != sb.end()) sb.erase(itb);

        debug(x);
        xr.pb(x.f ^ x.s);
    }

    while (sz(sa) && sz(sb)) {
        auto ita = sa.begin(), itb = sb.begin();
        sa.erase(ita);
        sb.erase(itb);

        debug(*ita, *itb);
        xr.pb((*ita) ^ (*itb));
    }

    debug(xr);
    if (sz(xr) == 0) cout << 0 << "\n";
    else {
        int ans = xr[0];
        FOR(i, 1, sz(xr) - 1) ans = (ans & xr[i]);
        cout << ans << "\n";
    }
}
#undef int

int main() {
#ifdef ERROR
    freopen("../error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);

    int NTC = 1;
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

