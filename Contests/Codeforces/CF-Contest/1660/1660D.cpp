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
    rep(i, n) cin >> a[i + 1];

    vvll pfx(n + 1, vll(5, 0));
    rep(i, n) {
        pfx[i + 1][a[i + 1] + 2] = 1;
    }

    FOR(i, 1, n) {
        rep(j, 5) pfx[i][j] += pfx[i - 1][j];
    }


    vll zr, neg;
    zr.pb(0);
    FOR(i, 1, n) if (a[i] == 0) zr.pb(i);
    FOR(i, 1, n) if (a[i] < 0) neg.pb(i);
    zr.pb(n + 1);

    debug(zr);

    auto getval = [&](ll l, ll r) {
        vll v;
        rep(j, 5) {
            ll cnt = pfx[r][j] - pfx[l - 1][j];
            v.pb(cnt);
        }

        return v;
    };

    vpll regions;
    FOR(i, 1, sz(zr) - 1) {
        ll r = zr[i] - 1, l = zr[i - 1] + 1;
        if (l <= r) {
            regions.pb({ l,r });
        }
    }

    vpll pos_regions;
    for (auto& p : regions) {
        ll l = p.f, r = p.s;
        vll x = getval(l, r);
        ll cntn = x[0] + x[1];
        assert(x[2] == 0);

        if (cntn % 2 == 0) pos_regions.pb({ l, r });
        else {
            auto itl = lb(all(neg), l); // >= l
            if (itl != neg.end()) {
                ll index = *(itl)+1;
                if (index <= r) pos_regions.pb({ index, r });
            }

            auto itr = ub(all(neg), r);
            if (itr != neg.begin()) {
                ll index = *(--itr) - 1;
                if (index >= l) pos_regions.pb({ l, index });
            }
        }
    }

    ll mx = 0ll;
    pll p = { -1, -1 };

    if (sz(pos_regions) == 0) cout << n << " " << 0 << "\n";
    else {
        for (auto& x : pos_regions) {
            ll l = x.f, r = x.s;
            vll v = getval(l, r);

            ll curmx = v[0] + v[4];
            if (curmx >= mx) {
                mx = curmx;
                p = { l, r };
            }
        }

        ll rl = p.f - 1;
        ll rr = p.s + 1;
        cout << (rl) << " " << (n - rr + 1) << "\n";
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

