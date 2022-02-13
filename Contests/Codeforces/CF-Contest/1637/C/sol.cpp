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
    ll n;
    cin >> n;

    vll a(n);
    rep(i, n) cin >> a[i];

    set<pll> ones;
    set<pll> odd;
    set<pll> even;

    FOR(i, 1, n - 2) {
        if (a[i] == 1) ones.insert({a[i], i});
        else if (a[i] & 1) odd.insert({a[i], i});
        else even.insert({a[i], i});
    }
    debug(ones);
    debug(odd);
    debug(even);

    ll ans = 0ll;
    while (sz(odd) && sz(ones)) { // ones using odds
        auto pone = *ones.begin();
        ones.erase(ones.begin());

        if (sz(odd)) {
            auto podd = *odd.rbegin();
            odd.erase(odd.find(podd));

            ans += 1ll;
            podd.f -= 1;
            pone.f += 1;

            even.insert({pone.f, pone.s});
            if (podd.f > 0) {
                even.insert({podd.f, podd.s});
            }
        }
    }

    while (sz(even) && (sz(ones) > 1)) { // ones using evens take 2 2
        auto pone1 = *ones.begin();
        ones.erase(ones.begin());

        auto pone2 = *ones.begin();
        ones.erase(ones.begin());

        if (sz(even)) {
            auto peven = *even.rbegin();
            even.erase(even.find(peven));

            ans += 1ll;
            peven.f -= 2;
            pone1.f += 1;
            pone2.f += 1;

            even.insert({pone1.f, pone1.s});
            even.insert({pone2.f, pone2.s});
            if (peven.f > 0) {
                even.insert({peven.f, peven.s});
            }
        }
    }

    while ((sz(odd) > 1)) { // odds using odds
        auto podd1 = *odd.begin();
        odd.erase(odd.find(podd1));

        auto podd2 = *odd.begin();
        odd.erase(odd.find(podd2));

        podd1.f -= 1;
        podd2.f += 1;
        ans++;

        if (podd1.f > 0) {
            even.insert({podd1.f, podd1.s});
        }

        if (podd2.f > 0) {
            even.insert({podd2.f, podd2.s});
        }
    }


    if (sz(ones) == 1) {// odd is over
        if (!sz(even)) {
            cout << -1 << "\n";
            return;
        }
        auto pone1 = *ones.begin();
        ones.erase(ones.begin());

        auto peven = *even.rbegin();
        even.erase(even.find(peven));

        ans += 1ll;
        peven.f -= 2;
        pone1.f += 1;

        even.insert({pone1.f, pone1.s});
        if (peven.f > 0) {
            even.insert({peven.f, peven.s});
        }
    }

    if (sz(odd) == 1) { // only 1 odd remains
        if (!sz(even)) {
            cout << -1 << "\n";
            return;
        }

        auto podd1 = *odd.begin();
        odd.erase(odd.begin());

        auto peven = *even.rbegin();
        even.erase(even.find(peven));

        ans += 1ll;
        peven.f -= 2;
        podd1.f += 1;

        even.insert({podd1.f, podd1.s});
        if (peven.f > 0) {
            even.insert({peven.f, peven.s});
        }
    }

    if (sz(ones) != 0) {
        cout << -1 << "\n";
        return;
    }

    if (sz(odd) != 0) {
        cout << -1 << "\n";
        return;
    }

    for (auto &x : even) ans += (x.f) / 2;
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
