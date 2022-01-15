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
const ll mod = 998244353;
const ld PI = acos(-1);
const ld eps = 1e-9;


void solve() {
    string s;
    cin >> s;
    ll n = sz(s);

    vll cnt(30, 0);
    rep(i, n) cnt[s[i] - 'a' + 1]++;
    debug(cnt);

    // vector<vvll> dp(30, vvll(n + 3, vll(n + 3, 0)));
    vvll dp(n + 3, vll(n + 3, 0));
    vvll prev = dp;
    FOR(j, 1, cnt[1]) {
        // dp[1][j][j] = 1;
        prev[j][j] = 1;
    }

    vll invtable(n + 1, 0);
    FOR(i, 1, n) {
        invtable[i] = powermod(i, mod - 2, mod);
    }

    FOR(i, 2, 27) {
        FOR(j, 1, n) {
            FOR(k, 0, min(j, cnt[i])) {
                if (k == 0) {
                    FOR(l, 0, cnt[i - 1]) {
                        // dp[i][j][k] += dp[i - 1][j][l];
                        // dp[i][j][k] %= mod;

                        dp[j][k] += prev[j][l];
                        dp[j][k] %= mod;
                    }
                }
                else {
                    if (j == 1) {
                        // dp[i][j][k] = 1ll;
                        dp[j][k] = 1ll;
                    }
                    else {
                        // ll p = (dp[i][j - 1][k - 1]) * j;
                        ll p = (dp[j - 1][k - 1]) * j;
                        p %= mod;

                        p *= invtable[k];
                        p %= mod;

                        // dp[i][j][k] = p;
                        dp[j][k] = p;
                    }
                }
            }
        }

        FOR(j, 0, n) FOR(k, 0, min(j, cnt[i])) prev[j][k] = dp[j][k], dp[j][k] = 0ll;
    }

    ll ans = 0ll;
    FOR(i, 1, n) {
        ans += prev[i][0];
        ans %= mod;
    }

    cout << ans << "\n";
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