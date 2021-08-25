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
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
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

const ll N = 1e5 + 2;
ll n = 2;
ll m;
ll dp[2][N + 11];
ll pfx[2][N];
ll a[2][N + 11];

void solve() {
    // clear
    rep(i, 2) {
        rep(j, m + 1) dp[i][j] = a[i][j] = 0;
        rep(j, m + 1) pfx[i][j] = 0;
    }

    cin >> m;
    rep(i, n) {
        rep(j, m) cin >> a[i][j];
    }


    rep(i, n) {
        rep(j, m) {
            (j == 0) ? (pfx[i][j] = a[i][j]) : (pfx[i][j] = pfx[i][j - 1] + a[i][j]);
        }
    }

    ll ans = inf;
    if (m == 1) {
        cout << 0 << "\n";
        return;
    }

    ans = min(ans, pfx[1][m - 1] - a[1][m - 1]);
    ans = min(ans, pfx[0][m - 1] - a[0][0]);

    FOR(j, 1, m - 2) {
        ll val = -inf;
        val = pfx[1][j - 1];
        val = max(val, pfx[0][m - 1] - pfx[0][j]);

        ans = min(ans, val);
    }

    FOR(j, 1, m - 2) {
        ll val = -inf;
        val = pfx[0][j - 1];
        val = max(val, pfx[1][m - 1] - pfx[1][j]);

        ans = min(ans, val);
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
