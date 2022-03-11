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
    ll n, d;
    cin >> n >> d;
    vll a(n);
    rep(i, n) cin >> a[i];

    map<ll, ll> mp;
    FOR(i, 0, n - 1) {
        ll r = a[i], l = 0;
        if (i) l = a[i - 1];
        mp[r - l - 1]++;
    }

    auto mn = [&](ll blk) {
        vll b; b.pb(0);
        rep(i, n) if (a[i] != blk) b.pb(a[i]);
        ll len = sz(b);

        vll blks;
        FOR(i, 1, len - 1) {
            blks.pb(b[i] - b[i - 1] - 1);
        }

        ll mn = inf;
        for (auto& x : blks) mn = min(mn, x);

        debug(blk, b, blks);

        // take last 
        ll take = (d - b.back() - 1);
        ll ans = min(mn, take);
        debug(take, ans);

        for (auto& x : blks) {
            if (x == 0) continue;

            ll res = 0ll;
            if (x != mn) {
                res = min(mn, (x - 1) / 2);
            }
            else {
                res = (mn - 1) / 2;
            }

            debug(x, res, ans);
            ans = max(ans, res);
        }

        return max(0ll, ans);
    };

    debug(a);
    debug(mp);

    ll curmn = mp.begin()->f;
    curmn = max(curmn, mn(a[0]));
    curmn = max(curmn, mn(a[1]));

    if (mp.begin()->s > 3) cout << curmn << "\n";
    else {
        ll curmn = mp.begin()->f;
        vll v;
        FOR(i, 0, n - 1) {
            ll r = a[i], l = 0;
            if (i) l = a[i - 1];

            if (r - l - 1 == curmn) {
                v.pb(l);
                v.pb(r);
            }
        }

        debug(a);
        for (auto& x : v) {
            debug(x);
            curmn = max(curmn, mn(x));
        }

        cout << curmn << "\n";
    }
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

