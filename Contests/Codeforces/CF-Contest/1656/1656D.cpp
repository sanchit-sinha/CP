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
const ll mod = 2e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll range(ll l, ll r) {
    ll n = uniform_int_distribution<int>(l, r)(rng);
    return n;
}

void solve() {
    ll n;
    cin >> n;

    auto check = [&](ll k) {
        if (k <= 1 || k > mod) return false;
        ll y = (k * (k - 1)) / 2;

        ll rem = n - y;
        if ((rem >= 0) && (rem % k == 0)) return true;
        return false;
    };

    if (n & 1) {
        cout << 2 << "\n";
        return;
    }

    FOR(i, 1, 31) {
        ll x = (1ll << i);
        FOR(j, x - 5, x + 5) {
            if (check(j)) {
                cout << j << "\n";
                return;
            }
        }
    }

    ll rem = n;
    set<ll> vv;
    while (rem % 2 == 0) {
        ll x = rem;
        vv.insert(x);
        FOR(j, x - 5, x + 5) {
            if (check(j)) {
                cout << j << "\n";
                return;
            }
        }
        rem /= 2;
    }
    ll x = rem;
    vv.insert(x);
    FOR(j, x - 5, x + 5) {
        if (check(j)) {
            cout << j << "\n";
            return;
        }
    }

    vll v;
    for (auto& xx : vv) v.pb(xx);
    // v    
    rep(l, sz(v)) {
        FOR(i, 1, 31) {
            ll x = (1ll << i) * v[l];
            FOR(j, x - 0, x + 0) {
                if (check(j)) {
                    cout << j << "\n";
                    return;
                }
            }
        }
    }

    //
    FOR(i, 2, 500) {
        if (check(i)) {
            cout << i << "\n";
            return;
        }
    }

    FOR(i, 2, 500) {
        ll j = range(501, mod);
        if (check(j)) {
            cout << j << "\n";
            return;
        }
    }

    cout << "-1\n";
    return;
    // [x.f, x.s]:  54272 {53}
    // [x.f, x.s]:  60416 {59}
    // [x.f, x.s]:  62464 {61}
    // [x.f, x.s]:  72704 {71}
    // [x.f, x.s]:  92416 {19, 361}
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

