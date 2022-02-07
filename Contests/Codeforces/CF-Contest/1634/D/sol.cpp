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

ll qry = 0;
// vll a = {1, 2, 0, 3};
ll ask(map<vll, ll> &m, ll i, ll j, ll k) {
    if (i == j || j == k || k == i) return -inf;
    vll v;
    v = {i, j, k};
    sort(all(v));

    if (m.count(v)) return m[v];
    cout << "? " << v[0] + 1 << " " << v[1] + 1 << " " << v[2] + 1 << endl;

    debug(v);

    ll ans;
    cin >> ans;
    // ll len = sz(a);
    // ll mx = max({a[v[0]], a[v[1]], a[v[2]]});
    // ll mn = min({a[v[0]], a[v[1]], a[v[2]]});
    // ans = mx - mn;

    m[v] = ans;

    qry++;
    return ans;
}
void solve() {
    qry = 0;
    ll n;
    cin >> n;

    map<vll, ll> m;
    ll  mx1i = -1, mx2i = -1;
    ll mx1 = -inf, mx2 = -inf;
    FOR(i, 2, n - 1) {
        ll res = ask(m, 0, 1, i);
        debug(i, res);
        if (mx1 <= res) {
            mx1 = res, mx1i = i;
        }
    }

    FOR(i, 2, n - 1) {
        ll res = ask(m, 0, mx1i, i);
        if (mx2 < res) {
            mx2 = res, mx2i = i;
        }
    }

    // ans is among 0,1,mx1,mx2
    vll poss = {0, 1, mx1i, mx2i};
    debug(poss);
    map<array<int, 3>, int> q;

    ll mxx = -inf;
    FOR(i, 0, 3) {
        FOR(j, i + 1, 3) {
            FOR(k, j + 1, 3) {
                array<int, 3> xx = {poss[i], poss[j], poss[k]};
                q[xx] = ask(m, poss[i], poss[j], poss[k]);
                debug(poss[i], poss[j], poss[k], q[xx]);

                mxx = max(mxx, q[xx]);
            }
        }
    }

    array<int, 3> q1 = { -1, -1, -1};
    array<int, 3> q2 = q1;;
    for (auto &x : q) {
        if (x.s == mxx) {
            if (q1[0] == -1) q1 = x.f;
            else q2 = x.f;
        }
    }

    pll ans = { -1, -1};
    FOR(a, 0, 2) {
        FOR(b, 0, 2) {
            FOR(c, 0, 2) {
                FOR(d, 0, 2) {
                    if (a == b || c == d) continue;
                    if (q1[a] == q2[c] && q1[b] == q2[d]) {
                        ans = {q1[a], q1[b]};
                    }
                }
            }
        }
    }
    debug(ans, qry, 2 * (n - 1));
    cout << "! " << ans.f + 1 << " " << ans.s + 1 << endl;
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
