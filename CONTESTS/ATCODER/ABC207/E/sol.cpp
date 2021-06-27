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
#define pll                 pair<ll , ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (int)((c).size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

#ifdef LOCAL
#include "debug.cpp"
bool DEBUG = true;
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
bool DEBUG = false;
#define debug(...) 42
#define cerr if(false) cerr
#endif

inline ll gcd(ll a, ll b) {if (b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a, ll b) {return ((a > b) ? a : b);}
inline ll min(ll a, ll b) {return ((a > b) ? b : a);}
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;


void solve() {
    ll n;
    cin >> n;

    vll a(n + 1, 0);
    rep(i , n) cin >> a[i + 1];
    debug(a);

    vll pfx(n + 1, 0);
    FOR(i, 1, n) pfx[i] = pfx[i - 1] + a[i];

    vvll dp(n + 1, vll(n + 1, 0)); // dp[i][j] : dividing a[1..i] into j parts
    vvll val(n + 1, vll(n + 1, 0)); // sum of dp[k][j - 1] having rem as pfx[i]%j

    val[0][1] = 1;
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            debug(i, j, pfx[i] % j, val[pfx[i] % j][i - 1]);
            dp[i][j] += val[pfx[i] % j][j];
            dp[i][j] %= mod;
        }

        FOR(j, 1, n) {
            val[pfx[i] % j][j] += dp[i][j - 1];
            val[pfx[i] % j][j] %= mod;
        }
    }

    if (DEBUG) {
        FOR(i, 1, n) {
            cerr << i << ": ";
            FOR(j , 1 , n) cerr << dp[i][j] << " ";
            cerr << "\n";
        }
    }

    ll ans = 0ll;
    FOR(j, 1, n) {
        ans += dp[n][j];
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

#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    factorial();
#endif
#ifdef PREPROCESS
    preprocess();
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
