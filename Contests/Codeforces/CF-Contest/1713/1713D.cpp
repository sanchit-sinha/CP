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

// vll wins = { 1,0,0,2,0,1,3,0 };
// vll wins = { 1,0,3,0,1,0,2,0,2,0,1,0,4,0,1,0 };
ll cnt = 0;
ll ask(ll x, ll y, map<pll, ll>& m) {
    debug(x, y);
    if (m.count({ x, y })) return m[{x, y}];
    cout << "? " << x << " " << y << endl;
    ll ans = 0;

    cnt++;
    // if (wins[x - 1] == wins[y - 1]) return 0;
    // if (wins[x - 1] > wins[y - 1]) return 1;
    // if (wins[x - 1] < wins[y - 1]) return 2;
    cin >> ans;
    return m[{x, y}] = ans;
}
void solve() {
    cnt = 0;

    ll n;
    cin >> n;

    vll ans;
    FOR(i, 1, (1ll << n)) ans.pb(i);
    debug(ans);

    map<pll, ll> m;
    while (sz(ans)) {
        debug(ans);
        if (sz(ans) == 1) {
            cout << "! " << ans[0] << endl;
            return;
        }
        if (sz(ans) == 2) {
            ll a = ans[0], b = ans[1];
            if (ask(a, b, m) == 1) {
                cout << "! " << a << endl;
                return;
            }
            else {
                cout << "! " << b << endl;
                return;
            }
        }

        vll temp;
        for (int i = 0; i < sz(ans); i += 4) {
            ll a = ans[i], b = ans[i + 1], c = ans[i + 2], d = ans[i + 3];
            if (ask(a, c, m) == 0) {
                temp.pb(b);
                temp.pb(d);
                // if (ask(b, d, m) == 1) temp.pb(b);
                // else temp.pb(d);
            }
            else if (ask(a, c, m) == 1) {
                temp.pb(a);
                temp.pb(d);
                // if (ask(a, d, m) == 1) temp.pb(a);
                // else temp.pb(d);
            }
            else if (ask(a, c, m) == 2) {
                temp.pb(b);
                temp.pb(c);
                // if (ask(b, c, m) == 1) temp.pb(b);
                // else temp.pb(c);
            }
        }
        ans = temp;
    }

    ll xx = (1ll << (n + 1));
    debug(cnt, (xx + 2) / 3);
    assert(cnt <= (xx + 2) / 3);
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

