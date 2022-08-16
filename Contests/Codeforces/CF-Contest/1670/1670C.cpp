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


void solve() {
    ll n;
    cin >> n;

    vll a(n + 1, 0ll);
    vll b(n + 1, 0ll);
    vll p(n + 1, 0ll);

    unordered_map<ll, ll> posa, posb;

    FOR(i, 1, n) cin >> a[i], posa[a[i]] = i;
    FOR(i, 1, n) cin >> b[i], posb[b[i]] = i;
    FOR(i, 1, n) cin >> p[i];

    vector<bool> vis(n + 1, 0ll);

    vvll ele(n + 1, vll(2, 0ll));
    vvll pos(n + 1, vll(2, 0ll));
    FOR(i, 1, n) ele[i][0] = a[i], ele[i][1] = b[i];
    for (auto& x : posa) pos[x.f][0] = x.s;
    for (auto& x : posb) pos[x.f][1] = x.s;

    // FOR(i, 1, n) if (a[i] == b[i]) p[i] = a[i], vis[i] = 1;

    debug(p);
    ll ans = 1ll;
    FOR(i, 1, n) {
        if (!vis[i]) {
            ll index = i, start = p[i], cur = 0ll;
            if (b[i] == p[i]) cur = 1;

            vll cycle;
            bool ok = 1;
            while (!vis[index]) {
                debug(index, p[index]);
                if (p[index]) ok = 0;
                p[index] = ele[index][cur];
                vis[index] = 1;
                cycle.pb(index);

                index = pos[ele[index][cur]][cur ^ 1];
                // p[index] = ele[index][cur];
            }
            if (ok) {
                if (sz(cycle) > 1) {
                    ans *= 2;
                    ans %= mod;
                }
            }
            debug(cycle);
        }
    }

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

