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
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

void brute(vll& v) {
    ll n = sz(v);
    vvll ans;

    rep(i, n) {
        vll t;
        rep(j, i + 1) t.pb(v[j]);
        sort(all(t));
        FOR(j, i + 1, n - 1) t.pb(v[j]);

        ans.pb(t);
    }

    vll sum(n, 0ll);
    rep(i, sz(ans)) {
        cout << i + 1 << ": ";
        rep(j, sz(ans[i])) sum[j] += ans[i][j], cout << ans[i][j] << " ";
        cout << "\n";
    }

    cout << " sum :: \n";
    rep(i, n) cout << sum[i] << " ";
    cout << "\n";
}
void solve() {
    ll n;
    cin >> n;
    vll c(n);
    rep(i, n) cin >> c[i];
    // brute(c);

    vll a(n + 1, 0ll);
    FOR(i, 1, n) a[i] = c[i - 1];

    vll ans(n + 1, 0ll);
    ll p = 1ll;
    bool ok = 0;
    FOR(i, 1, n) {
        ll x = a[i];
        if (ok == 0 && c[i]) {
            ok = 1;
            FOR(j, i, x) ans[j] = 1;
            p = x;
        }
        else {
            debug(i, a[i]);
            if (a[i] == p + 1) p++;
            else if (a[i] > a[i - 1]) {
                ll notp = p + 2;
                debug(i, a[i], notp, p, x);
                FOR(j, notp, x) ans[j] = 1;
                p = x;
            }
        }
    }

    FOR(i, 1, n) cout << ans[i] << " ";
    cout << "\n";
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

