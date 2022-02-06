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

const ll N = 1011, M = 1e4 + 3;

void solve() {
    ll n, mx;
    cin >> n >> mx;
    // rep(i, n) cin >> w[i + 1] >> v[i + 1];

    vll b(n + 1, 0ll), a(n + 1, 0ll);
    FOR(i, 1, n) cin >> b[i];

    ll mxb = 0ll;
    FOR(i, 1, n) mxb = max(mxb, b[i]);
    vll dpp(mxb + 3, inf);

    dpp[1] = 0;
    FOR(i, 1, mxb - 1) {
        FOR(j, 1, mxb) {
            ll z = i + (i / j);
            if (z <= mxb) {
                dpp[z] = min(dpp[z], dpp[i] + 1);
            }
        }
    }

    vll w(n + 1, 0ll);
    FOR(i, 1, n) {
        w[i] = dpp[b[i]];
    }
    debug(w);

    vll v(n + 1, 0ll);
    FOR(i, 1, n) cin >> v[i];
    debug(v);

    ll mxx = 0ll;
    FOR(i, 1, n) mxx += w[i];

    if (mx >= mxx) {
        ll sum = 0ll;
        FOR(i, 1, n) sum += v[i];
        cout << sum << "\n";
        return;
    }

    vvll dp(n + 11, vll(mx + 11, 0ll));
    FOR(i, 1, n) {
        rep(j, mx + 1) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]); // not use
            if (j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);

            //  take ith
            if (j - w[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    if (DEBUG) {
        FOR(i, 1, n) {
            FOR(j, 0, mx) {
                cerr << dp[i][j] << " ";
            }
            cerr << "\n";
        }
        cerr << "\n";
    }
    cout << dp[n][mx] << "\n";
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