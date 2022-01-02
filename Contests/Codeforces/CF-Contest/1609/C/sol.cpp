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

const ll N = 1e6 + 5;
#define SIEVE
const ll mX = N;
bool prime[mX + 11];
void sieve() {
    memset(prime, true, sizeof(prime));
    for (ll p = 2 ; p * p <= mX ; p++) {
        if (prime[p] == true) {
            for (ll i = p * p ; i <= mX; i += p) prime[i] = false;
        }
    }
}
// note that the complexity is sqrt(n)*log(n)
// can't store all prime numbers directly(need to iterate all numbers : nlog(n))

void solve() {
    ll n, e;
    cin >> n >> e;

    vll a(n + 1, 0);
    rep(i, n) cin >> a[i + 1];

    vll dpfr(n + 3, 0), dpbk(n + 3, 0); // no of 1s ending at i and starting at i

    FOR(i, 1, e) dpfr[i] = (a[i] == 1);
    FOR(i, e + 1, n) {
        if (a[i] == 1) dpfr[i] = dpfr[i - e] + 1;
    }

    FORR(i, n, n - e + 1) dpbk[i] = (a[i] == 1);
    FORR(i, n - e, 1) {
        if (a[i] == 1) dpbk[i] = dpbk[i + e] + 1;
    }

    debug(dpfr);
    debug(dpbk);

    ll ans = 0ll;
    FOR(i, 1, n) {
        ll x = i - e, y = i + e;
        if (prime[a[i]] && a[i] > 1) {
            ll l = 0, r = 0;
            if (x >= 1) l = dpfr[x];
            if (y <= n) r = dpbk[y];

            debug(i, a[i], l, r);
            ans += (l * r) + l + r;
        }

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
