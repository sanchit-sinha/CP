#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include "bits/stdc++.h"
using namespace __gnu_pbds;
using namespace std;

#define f                   first
#define s                   second
#define pb                  push_back
#define ll                  int
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

const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

struct FenwickTree {
    vector<ll> bit;  // binary 1-indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0ll) ;
    }

    FenwickTree(vector<ll> a) : FenwickTree(a.size()) { // a : 1 - indexed
        for (size_t i = 1; i < a.size(); i++)
            update(i, a[i]);
    }

    void update(int x , ll increment) {
        while (x <= n) {
            bit[x] += increment; // update operation
            x += (x & -x);
        }
    }

    ll query(int x) { // 1 .. x
        ll val = 0ll; // operation (inf , -inf , 0 ...)
        while (x > 0) {
            val += bit[x]; // operation
            x -= (x & -x);
        }
        return val;
    }

    ll query(int l, int r) { // l .. r
        return query(r) - query(l - 1);
    }
};
void solve() {
    ll n, c;
    cin >> n >> c;

    // FenwickTree fT(c + c + 1);
    vector<bool> pres(c + 3, 0);
    vll pfx(c + c + 3, 0);

    rep(i, n) {
        ll x; cin >> x;
        pres[x] = 1;
        pfx[x] += 1;
        // fT.update(a[i], 1);
    }

    vll b;
    rep(i, c + 1) if (pres[i]) b.pb(i);

    FOR(i, 1, c + c + 1) {
        pfx[i] += pfx[i - 1];
    }

    if (DEBUG) {
        debug(b);
        FOR(i, 1, min(c + c, 10)) cerr << pfx[i] << " ";
        cerr << "\n";
    }

    rep(i, sz(b)) {
        ll y = b[i]; // y is in array
        for (ll ky = y; ky <= c; ky += y) {
            ll k = ky / y;
            if (!pres[k]) { // k is not in array
                if (pfx[ky + y - 1] - pfx[ky - 1] > 0) { // x should not be in array
                    // fT.query(ky, ky + y - 1) > 0) {
                    debug(y, k, ky, ky + k - 1);
                    cout << "No\n";
                    return;
                }
            }
        }
    }
    cout << "Yes\n";
    return;
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
