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
const ll mod = 998244353;
const ld PI = acos(-1);
const ld eps = 1e-9;

bool check(vll& a) {
    ll n = sz(a);
    ll g = 0ll;

    rep(i, n) {
        g = gcd(g, (i + 1) * a[i]);
    }

    return (g > 1);
}
const ll N = 1e3 + 11;

#define NCR
const ll mX = N;
ll fact[mX + 11], invfact[mX + 11];
void factorial() {
    fact[0] = invfact[0] = 1;
    for (ll i = 1; i < mX; i++) {
        fact[i] = i * fact[i - 1];
        fact[i] %= mod;
    }
    invfact[mX - 1] = powermod(fact[mX - 1], mod - 2, mod); // if mod is prime
    for (ll i = mX - 2; i > 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1);
        invfact[i] %= mod;
    }
}
ll ncr(ll n, ll r) {
    if (r > n || n < 0 || r < 0)return 0;
    ll p = (fact[n] * invfact[r]) % mod;
    p *= invfact[n - r];
    return p % mod;
}

void solve() {
    ll n;
    cin >> n;

    if (n & 1) cout << 0 << "\n";
    else {
        ll h = n / 2;
        ll ans = fact[h] * fact[h];
        ans %= mod;

        cout << ans << "\n";
    }
}

int main() {
#ifdef ERROR
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

ll power(ll x, ll y) { if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex, ll md) { ll ans = 1ll; while (ex > 0) { if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md; } return ans; }

