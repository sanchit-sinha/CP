#include "bits/stdc++.h"
using namespace std;

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll                  long long
#define pll                 pair<ll, ll>

#define o_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>


#define f                   first
#define s                   second
#define pb                  push_back
#define ld                  long double
#define lb                  lower_bound
#define ub                  upper_bound
#define mp                  make_pair
#define mt                  make_tuple
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

    map<ll, ll> m;

    set<ll> todo;
    rep(i, n) todo.insert(i + 1);

    rep(i, n) {
        ll x;
        cin >> x;
        m[x]++;
    }


    debug(m);
    ll index = 0;
    vll v;
    trav(it, m) {
        ll x = it->f;

        ll len = m[x];
        if (x <= n) {
            auto it = todo.find(x);
            if (it != todo.end()) {
                todo.erase(it);
            }

            len--;
        }

        rep(j, len) {
            v.pb(x);
        }

    }


    debug(todo);
    debug(v);
    sort(all(v));

    ll ans = 0ll;
    rep(i, sz(v)) {
        ll x = v[i];
        ll y = (x + 1) / 2;

        auto it = todo.lb(y);
        if (it != todo.begin()) {
            cerr << "in " << y << "\n";
            ll rem = *todo.begin();
            ll div = x - rem;

            todo.erase(todo.begin());
            ans++;
        }
        else {
            cout << -1 << "\n";
            return;
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