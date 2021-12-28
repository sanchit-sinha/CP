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
    ll n, k;
    cin >> n >> k;

    ll sum = 0ll;

    vll a(n);
    rep(i, n) cin >> a[i], sum += a[i];

    if (sum <= k) cout << "0\n";
    else {
        if (n == 1) {
            cout << a[0] - k << "\n";
            return;
        }

        sort(all(a));

        vll pfx(n, 0);
        rep(i, n) {
            (i == 0) ? pfx[i] = a[i] : pfx[i] = pfx[i - 1] + a[i];
        }

        ll ans = inf;
        auto getMn = [&](ll eq, ll len) {
            if (eq > a[0]) eq = a[0];

            ll sum = pfx[len] - pfx[0];
            ll rem = (n - len);

            if (sum + rem * eq <= k) {
                // a0 >= eq
                ll steps = (a[0] - eq) + (rem - 1);
                debug(eq, len, steps);
                ans = min(ans, steps);
            }
            return;
        };

        FOR(i, 0, n - 1) {
            ll sum = pfx[i] - pfx[0];
            ll rem = n - (i);

            ll eq = (k - sum) / rem;
            debug(i, rem, sum, eq);
            FOR(k, -2, 2) {
                getMn(eq + k, i);
            }
        }

        FORR(i, n - 1, 1) {
            ll sum = pfx[i - 1];
            ll rem = (n - 1 - i + 1); // make sfx eq to a0

            if (sum + rem * a[0] <= k) ans = min(ans, rem);
        }

        cout << ans << "\n";
    }
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
