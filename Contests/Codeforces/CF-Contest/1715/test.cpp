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


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll range(ll l, ll r) {
    ll n = uniform_int_distribution<int>(l, r)(rng);
    return n;
}

void solve() {
    while (1) {
        ll n, q;
        n = range(1, n), q = range(1, )

        vvll ans(n + 11, vll(33, -1));
        map<ll, vpll> mp;
        while (q--) {
            ll i, j, x;
            cin >> i >> j >> x;
            rep(k, 31) {
                if ((1ll << k) & x);
                else ans[i][k] = ans[j][k] = 0; // unset 
            }

            if (i == j) {
                rep(k, 31) if ((1ll << k) & x) ans[i][k] = 1;
            }
            else if (i > j) {
                mp[j].pb({ i, x });
            }
            else {
                mp[i].pb({ j, x });
            }
        }

        for (auto& x : mp) {
            ll i = x.f;
            rep(k, 31) {
                bool cur = 0; // 1 at i or not 
                for (auto& y : x.s) {
                    if ((1ll << k) & (y.s)) {
                        if (ans[y.f][k] == 0) cur = 1;
                    }
                }

                if (cur) ans[i][k] = 1;
                else {
                    for (auto& y : x.s) {
                        if ((1ll << k) & (y.s)) {
                            ans[y.f][k] = 1;
                        }
                    }
                }
            }
        }


        FOR(i, 1, n) {
            ll x = 0ll;
            rep(j, 31) if (ans[i][j] == 1) x += (1ll << j);
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main() {
#ifdef ERROR
    freopen("../error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);

    ll NTC = 1;
    // cin >> NTC;

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
