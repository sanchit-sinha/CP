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

void solve() {
    ll n;
    cin >> n;

    vll a(n);
    rep(i, n) cin >> a[i];

    // avg;
    auto avg = [&](ld x) {
        vector<ld> b;
        rep(i, n) b.pb((ld)a[i] - x);

        // checking if max sum satisying all the conditions is 0 or not
        vector<ld> dp(n + 1, 0.0); // dp[i] : max sum ending at i and choosing i
        rep(i, n) {
            if (i == 0) {
                dp[i] = b[i];
            }
            else if (i == 1) {
                dp[i] = max(b[1] + b[0], b[1]);
            }
            else {
                dp[i] = max(dp[i - 1] + b[i], dp[i - 2] + b[i]);
            }
        }

        if (max(dp[n - 1], dp[n - 2]) > 0.0) return 1;
        return 0;
    };

    ld k = 0.0;
    ld l = 0.0, r = 1e9, avg_ans = 0.0;
    FOR(i, 1, 60) {
        ld mid = (l + (r - l) / (2.0));
        if (avg(mid)) avg_ans = mid, l = mid; // >= avg is possible
        else r = mid;
    }
    cout << avg_ans << "\n";

    auto checkmedian = [&](ll x) {
        vll b;
        rep(i, n) {
            // making median >= x
            if (a[i] >= x) b.pb(1);
            else b.pb(-1);
        }

        // making sum > 0 as <= x should be more than > x
        vll dp(n, 0ll); // dp[i] : max sum ending at i and choosing i
        FOR(i, 0, n - 1) {
            if (i == 0) dp[i] = b[i];
            else if (i == 1) {
                dp[i] = max(b[i], b[i] + b[i - 1]);
            }
            else {
                dp[i] = max(dp[i - 1] + b[i], dp[i - 2] + b[i]);
            }
        }

        return (max(dp[n - 1], dp[n - 2]) > 0ll);
    };

    ll lm = 0, rm = 1e9, ansm = 0ll;
    while (lm <= rm) {
        ll lmid = lm + (rm - lm) / 2;
        // >= lmid is possible or not
        if (checkmedian(lmid)) ansm = lmid, lm = lmid + 1;
        else rm = lmid - 1;
    }

    cout << ansm << "\n";
}

int main() {
#ifdef LOCAL
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

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
