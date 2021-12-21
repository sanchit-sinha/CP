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
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;


void solve() {
    ll n;
    cin >> n;

    vll a(n);
    rep(i, n) cin >> a[i];

    vll cnt(n + 5, 0);
    rep(i, n) cnt[a[i]]++;

    set<ll> s;
    FOR(i, 0, n) {
        if (cnt[i] > 1) s.insert(i);
    }

    vll dp(n + 5, 0);//dp[i] : no. operations involving indices < i for 0,1,2...i-1 elements
    FOR(i, 0, n) {
        if (i == 0) {
            if (cnt[i] == 0) dp[i] = 0;
        }
        else {
            if (dp[i - 1] == -1) dp[i] = -1;
            else {
                // 0 ... i - 2 is poss
                // check for i - 1

                dp[i] = dp[i - 1];
                bool got = 0;

                if (cnt[i - 1]) got = 1;
                else {
                    if (sz(s)) {
                        cerr << "2 @";
                        auto it = s.ub(i - 1);
                        if (it != s.begin()) {
                            it--;

                            ll p = *it;
                            cnt[i - 1] = 1;
                            cnt[p]--;

                            dp[i] += (i - 1 - p);
                            got = 1;

                            if (cnt[p] <= 1) s.erase(it);
                        }
                    }
                }

                if (!got) dp[i] = -1;
                debug(i, got, dp[i]);
            }
        }

        if (dp[i] == -1) cout << -1 << " ";
        else cout << dp[i] + cnt[i] << " ";
    }
    cout << "\n";
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
