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
    ll n, m;
    cin >> n >> m;

    vvll a(n, vll(m, 0));
    rep(i, n) rep(j, m) cin >> a[i][j];

    unordered_map<ll, vll> ci, cj;
    rep(i, n) {
        rep(j, m) {
            ci[a[i][j]].pb(i);
            cj[a[i][j]].pb(j);
        }
    }

    if (DEBUG) {
        for (auto &x : ci) debug(x.f, x.s);
        for (auto &x : cj) debug(x.f, x.s);
    }

    ll ans = 0ll;
    auto res = [&](vll & v) {
        sort(all(v));
        reverse(all(v));

        ll len = sz(v);
        vll sfx(len + 1, 0ll);

        FORR(i, len - 1, 0) {
            if (i == len - 1) sfx[i] = v[i];
            else sfx[i] = sfx[i + 1] + v[i];
        }

        ll val = 0ll;
        rep(i, len - 1) {
            ll osum = sfx[i + 1];
            ll vi = v[i], rem = (len - 1 - (i + 1) + 1);

            val += (vi * rem - osum);
        }

        debug(v, sfx, val);
        return val;
    };

    for (auto &x : ci) {
        ans += res(x.s);
    }

    for (auto &x : cj) {
        ans += res(x.s);
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
    // cin >> NTC;

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
