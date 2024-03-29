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

// nice problem
void solve() {
    ll n;
    cin >> n;

    vll ele(n);
    rep(i, n) cin >> ele[i];


    // dp[i]: no of subsequences ending at i with mex ele[i]+1 0011223(=> j=1) or mex = ele[i] - 1 00113(313 or 331)(=> j=0)
    vvll dp(n + 5, vll(2, 0));
    vvll sdp(n + 5, vll(2, 0)); // sdp[i][j] = sigma dp[k][j], where ele[k] = i;

    // count seq starting at i and of type : 424424, 442242 or 24442, 224
    // dpalt[i][j] : no of sequences starting at i and of the form 424424, 442242(j=0) or  24442, 224(j=1)
    vvll dpalt(n + 5, vll(2, 1));
    vvll sdpalt(n + 5, vll(2, 0)); // sdalt[i][j] = sigma dpalt[k][j], where ele[k] = i

    FORR(i, n - 1, 0) {
        // 42424 , 442
        dpalt[i][0] += sdpalt[ele[i]][0], dpalt[i][0] %= mod;
        if (ele[i] - 2 >= 0) dpalt[i][0] += sdpalt[ele[i] - 2][1], dpalt[i][0] %= mod;
        sdpalt[ele[i]][0] += dpalt[i][0], sdpalt[ele[i]][0] %= mod;

        // 2424 224
        dpalt[i][1] += sdpalt[ele[i] + 2][0], dpalt[i][1] %= mod;
        dpalt[i][1] += sdpalt[ele[i]][1], dpalt[i][1] %= mod;
        sdpalt[ele[i]][1] += dpalt[i][1], sdpalt[ele[i]][1] %= mod;
    }

    // calculate dp
    ll cnt0 = 0, cnt1 = 0;
    rep(i, n) {
        // d[][1] : MEX is ele[i] + 1
        if (ele[i] == 0) {
            cnt0++;
            dp[i][1] = powermod(2, cnt0 - 1, mod);
        }
        else {
            dp[i][1] += sdp[ele[i]][1], dp[i][1] %= mod;
            dp[i][1] += sdp[ele[i] - 1][1], dp[i][1] %= mod;
            // dp[i][1] += sdp[ele[i] + 2][0], dp[i][1] %= mod;
        }
        sdp[ele[i]][1] += dp[i][1], sdp[ele[i]][1] %= mod;

        // MEX is ele[i] - 1
        if (ele[i] == 0) continue;
        if (ele[i] == 1) {
            cnt1++;
            dp[i][0] = powermod(2, cnt1 - 1, mod);
        }
        else {
            ll p = 1ll, q = 1ll;// 0122 ___, where ___ = 4242 or 442
            if (ele[i] - 2 >= 0) p *= sdp[ele[i] - 2][1], p %= mod;
            q *= dpalt[i][0], q %= mod;

            dp[i][0] = p * q, dp[i][0] %= mod;
        }

    }


    ll ans = 0;
    rep(i, n) ans += (dp[i][0] + dp[i][1]) % mod, ans %= mod;
    cout << ans << "\n";
}

int main() {
#ifdef LOCAL
    freopen("../../error.txt", "w", stderr);
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