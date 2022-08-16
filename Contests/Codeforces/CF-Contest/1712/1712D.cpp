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

const ll inf = 1e9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

void solve() {
    ll n, k;
    cin >> n >> k;

    map<ll, vll> mx;
    set<pair<ll, pll>> edges;

    vll v(n);
    rep(i, n) cin >> v[i], mx[v[i]].pb(i);

    auto add = [&](ll x, ll y) {
        if (x < 0 || y < 0 || x >= n || y >= n) return;
        edges.insert({ min(v[x], v[y]), {x, y} });
        edges.insert({ min(v[x], v[y]), {y, x} });
    };

    auto del = [&](ll x, ll y) {
        if (x < 0 || y < 0 || x >= n || y >= n) return;
        pair<ll, pll> p1 = { min(v[x], v[y]), {x, y} };
        pair<ll, pll> p2 = { min(v[x], v[y]), {y, x} };

        auto it1 = edges.find(p1);
        if (it1 != edges.end()) {
            edges.erase(it1);
        }

        auto it2 = edges.find(p2);
        if (it2 != edges.end()) {
            edges.erase(it2);
        }
    };


    FOR(i, 1, n - 1) {
        add(i, i - 1);
    }

    if (n == 2) {
        if (k == 2) cout << inf << "\n";
        else cout << max(v[0], v[1]) << "\n";
        return;
    }

    // n >= 3
    ll ans = 0;
    while (k >= 0) {
        ll mn = mx.begin()->f;
        ll res = 2 * mn;
        res = min(res, inf);

        ll anss = 0;

        if (DEBUGG) {
            debug(mn, res, v);

            for (auto& x : mx) {
                debug(x.f, x.s);
            }
            cerr << "\n";

            for (auto& x : edges) {
                cerr << x.f << " " << x.s.f << " " << x.s.s << "\n";
            }
            cerr << "\n\n";
        }

        // 2mn is poss
        anss = min(res, (--edges.end())->f); // [mn, 2mn]

        if (anss < res) {
            if (k >= 2) ans = max(ans, res);
            else if (k >= 1) {
                ll mxx = mx.rbegin()->f;
                anss = min(res, mxx);
                // auto itmx = mx.ub(res);
                // if (itmx != mx.begin()) {
                //     --itmx;
                //     anss = max(anss, itmx->f);
                // }
            }
        }
        ans = max(ans, anss);
        if (ans == inf) break;

        if (k == 0) break;

        k--;
        ll index = (mx.begin()->s).back();
        (mx.begin()->s).pop_back();

        if (sz(mx.begin()->s) == 0) mx.erase(mx.begin());

        del(index, index - 1);
        del(index, index + 1);

        v[index] = inf;
        mx[inf].pb(index);

        add(index, index - 1);
        add(index, index + 1);
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

