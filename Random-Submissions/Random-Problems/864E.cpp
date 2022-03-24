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


void solve() {
    ll n;cin >> n;
    vector<array<ll, 4>> v;

    v.pb({ 0,0,0,0 });
    rep(i, n) {
        ll t, d, p;
        cin >> t >> d >> p;
        v.pb({ d,t,p,i + 1 });
    }
    sort(all(v));
    debug(v);

    ll mx = 2e3 + 1;
    vvll dp(n + 4, vll(mx + 4, 0ll)); // max value upto i items and atmost time j
    vector<vpll> save(n + 4, vpll(mx + 4, { -1,-1 }));

    FOR(i, 1, n) {
        FOR(j, 0, mx) {
            dp[i][j] = dp[i - 1][j]; // dont take 
            if (j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            ll t = v[i][1], d = v[i][0], p = v[i][2];
            if (j < d && j >= t) { // take 
                dp[i][j] = max(dp[i][j], dp[i - 1][j - t] + p);
                if (dp[i][j] == dp[i - 1][j - t] + p) {
                    save[i][j] = { i - 1, j - t };
                }
            }

            if (save[i][j].f == -1 || save[i][j].s == -1) {
                if (dp[i][j] == dp[i - 1][j]) save[i][j] = { i - 1,j };
                else if (j && dp[i][j] == dp[i][j - 1]) save[i][j] = { i,j - 1 };
            }
        }
    }

    pll val = { -1,-1 };
    ll mxx = 0ll;
    FOR(i, 1, n) {
        FOR(j, 0, mx) {
            if (dp[i][j] > mxx) {
                mxx = dp[i][j];
                val = { i,j };
            }
        }
    }

    if (DEBUGG) {
        FOR(i, 1, n) {
            cerr << i << ": ";
            FOR(j, 1, 20) {
                cerr << dp[i][j] << " ";
            }
            cerr << "\n";
        }
    }

    vll ans;
    while (val.f > 0 && val.s != -1) {
        ll i = val.f, j = val.s;
        val = save[i][j];
        if (val.s != j) {
            debug(val);
            ans.pb(v[i][3]);
        }
    }
    reverse(all(ans));

    cout << mxx << "\n";
    cout << sz(ans) << "\n";
    for (auto& x : ans) cout << x << " ";
    cout << "\n";
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

