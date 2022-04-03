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

#define opll tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define oll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

/*  order_of_key(k) : number of elements strictly lesser than k
    find_by_order(k) : counting from zero it returns the k-th largest or smallest element in the set - returns iterator  */



void solve() {
    ll n;
    cin >> n;

    vll c(n + 1, 0ll);
    FOR(i, 1, n) cin >> c[i];

    ll o = 0, cnt = 0ll;
    FOR(i, 1, n) {
        if (c[i] == 1) o = i, cnt++;
    }

    if (cnt != 1) {
        cout << "NO\n";
        return;
    }

    vll per;
    FOR(i, o, n) per.pb(c[i]);
    FOR(i, 1, o - 1) per.pb(c[i]);

    reverse(all(per));
    debug(c, per);

    oll s;
    FOR(i, 1, n) s.insert(i);

    vll ans;
    rep(i, sz(per)) {
        if (sz(s) == 0) {
            cout << "No\n";
            return;
        }
        ll x = per[i];
        ll l = sz(s) - x;
        if (l < 0 || l >= sz(s)) {
            cout << "NO\n";
            return;
        }
        ll ele = *s.find_by_order(l);

        if (ele < 1 || ele > n) {
            cout << "NO\n";
            return;
        }

        ans.pb(ele);
        s.erase(s.find(ele));
    }
    debug(ans);
    cout << "YES\n";
    return;

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

