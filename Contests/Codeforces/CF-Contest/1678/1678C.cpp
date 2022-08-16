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


struct FenwickTree {
    vector<long long> bit;  // binary 1-indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0ll);
    }

    FenwickTree(vector<long long> a) : FenwickTree(a.size()) { // a : 1 - indexed
        for (size_t i = 1; i < a.size(); i++)
            update(i, a[i]);
    }

    void update(int x, ll increment) {
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
    ll n;
    cin >> n;

    vll p(n);
    rep(i, n) cin >> p[i];

    ll ans = 0ll;

    // oll pfx;
    FenwickTree pfx(n + 1);
    rep(b, n) {
        // oll sfx;
        FenwickTree sfx(n + 1);
        FOR(i, b + 1, n - 1) sfx.update(p[i], 1);
        FOR(c, b + 1, n - 1) {
            sfx.update(p[c], -1);
            // sfx.erase(sfx.find(p[c]));
                // // in sfx elements are with index > c
                // ll sfxcnt = sfx.order_of_key(p[b]);
                // ll pfxcnt = pfx.order_of_key(p[c]);

            ll sfxcnt = sfx.query(p[b]);
            ll pfxcnt = pfx.query(p[c]);
            // debug(b, c, pfx, sfx, pfxcnt, sfxcnt);

            ans += (pfxcnt * sfxcnt);
        }
        // pfx.insert(p[b]);
        pfx.update(p[b], 1);
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

