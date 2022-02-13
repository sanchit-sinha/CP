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

//////////////// :(
void solve() {
    ll n;
    cin >> n;

    vll a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    ll mx = 1e4 + 2;

    ll ans = 0ll;
    FOR(i, 0, n - 1) {
        FOR(j, i + 1, n - 1) {
            ans += (a[i] * a[i] + a[j] * a[j] + b[i] * b[i] + b[j] * b[j]);
        }
    }

    vll tot(n + 1, 0ll);
    FORR(i, n - 1, 0) {
        if (i == n - 1) tot[i] = a[i] + b[i];
        else tot[i] = tot[i + 1] + a[i] + b[i];
    }

    vvll dp(n + 1, vll(mx + 2, inf)); // dp[i][j] : min val with arr [i,n-1] and a{sum[i,n-1]} = j
    FORR(i, n - 1, 0) {
        FOR(j, 0, mx - 1) {
            if (i == n - 1) {
                if (j == a[i] || j == b[i]) dp[i][j] = 0ll;
            }
            else {
                // no swap
                ll x = inf;
                ll sfx = j - a[i];
                if (sfx >= 0 && j >= a[i] && dp[i + 1][j - a[i]] < inf) {
                    x = a[i] * sfx + b[i] * (tot[i + 1] - sfx) + dp[i + 1][j - a[i]];
                }

                ll y = inf;
                sfx = j - b[i];
                if (sfx >= 0 && j >= b[i] && dp[i + 1][j - b[i]] < inf) {
                    x = b[i] * sfx + a[i] * (tot[i + 1] - sfx) + dp[i + 1][j - b[i]];
                }

                dp[i][j] = min(x, y);
            }
        }
    }

    ll add = inf;
    FOR(i, 0, mx - 1) add = min(add, 2 * dp[0][i]);
    debug(ans, add / 2);
    cout << ans + add << "\n";
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
