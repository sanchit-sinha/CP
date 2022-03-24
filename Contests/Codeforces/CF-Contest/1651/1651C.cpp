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

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;


void solve() {
    ll n;
    cin >> n;

    vll a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    multiset<ll> sa, sb;
    rep(i, n) sa.insert(a[i]);
    rep(i, n) sb.insert(b[i]);

    debug(a);
    debug(b);
    debug(sa);
    debug(sb);

    auto calc = [&](ll i) {
        ll x = abs(a[i] - b[i]);
        ll mn1 = inf, mn2 = inf;
        auto it1 = sa.find(a[i]);
        sa.erase(it1);

        auto it2 = sb.find(b[i]);
        sb.erase(it2);

        auto itc = sb.lb(a[i]);
        if (itc != sb.end()) mn1 = min(mn1, abs(*itc - a[i]));
        if (itc != sb.begin()) mn1 = min(mn1, abs(*(--itc) - a[i]));

        auto it2c = sa.lb(b[i]);
        if (it2c != sa.end()) mn2 = min(mn2, abs(*it2c - b[i]));
        if (it2c != sa.begin()) mn2 = min(mn2, abs(*(--it2c) - b[i]));


        x = min(x, mn1 + mn2);

        sa.insert(a[i]);
        sb.insert(b[i]);
        return x;
    };

    auto calc1 = [&](ll i, ll op) {
        ll x = inf;
        if (op == 0) {
            ll mn1 = x;
            auto itc = sb.lb(a[i]);
            if (itc != sb.end()) mn1 = min(mn1, abs(*itc - a[i]));
            if (itc != sb.begin()) mn1 = min(mn1, abs(*(--itc) - a[i]));
            return mn1;
        }
        else {
            ll mn2 = x;
            auto it2c = sa.lb(b[i]);
            if (it2c != sa.end()) mn2 = min(mn2, abs(*it2c - b[i]));
            if (it2c != sa.begin()) mn2 = min(mn2, abs(*(--it2c) - b[i]));
            return mn2;
        }
        return x;
    };

    ll ans = inf;
    ans = min(ans, calc(0) + calc(n - 1));
    debug(ans);
    ans = min(ans, abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1])); // 1
    debug(ans);
    ans = min(ans, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0])); // 2
    debug(ans);
    ans = min(ans, abs(a[0] - b[0]) + calc(n - 1)); // 3
    debug(ans);
    ans = min(ans, calc(0) + abs(a[n - 1] - b[n - 1])); // 4
    debug(ans);
    ans = min(ans, abs(a[0] - b[n - 1]) + calc1(0, 1) + calc1(n - 1, 0));
    debug(ans);
    ans = min(ans, calc1(0, 0) + calc1(n - 1, 1) + abs(a[n - 1] - b[0]));
    debug(ans);

    cout << ans << "\n";
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

