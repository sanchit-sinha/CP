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

void brute(ll n, ll k) {
    debug(n, k);

    set<pair<ll, pll>> andd;
    FOR(i, 0, n - 1) {
        FOR(j, i + 1, n - 1) {
            andd.insert({(i & j), {i, j}});
        }
    }

    for (auto &p : andd) {
        cerr << p.f << ": ";
        cerr << p.s.f << " " << p.s.s << "\n";
    }
    cerr << "\n";

    vector<bool> vis(n, 0);
    set<ll> poss;
    vpll v;
    set<pair<ll, vpll>> xx;
    function < void()> calc = [&]() {
        int index = -1;
        for (int i = 0; i < n; i++) if (!vis[i]) index = i;

        if (index == -1) {
            ll ans = 0ll;
            for (auto &p : v) ans += (p.f & p.s);

            if (ans < n) {
                poss.insert(ans);

                xx.insert(make_pair(ans, v));
            }
            return;
        }

        vis[index] = 1;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                v.pb({index, i});

                calc();

                v.pop_back();
                vis[i] = 0;

            }
        }
        vis[index] = 0;

        return;
    };

    calc();

    debug(sz(poss));
    ll cnt = 1ll;
    for (auto &x : xx) {
        debug(cnt, x.f, x.s);
        cnt++;
    }
    cerr << "\n";
}
void solve() {
    ll n, k;
    cin >> n >> k;

    // brute(n, k);
    vll m(n, 0);
    rep(i, n) m[i] = n - i - 1;

    if (k < n - 1) {
        ll andd = 0ll, index = 0;
        while (k) {
            if (k & 1) andd += (1ll << index);
            k /= 2, ++index;
        }
        debug(k, n - 1, andd);

        ll temp = m[andd];
        m[n - 1] = andd, m[andd] = n - 1;
        m[0] = temp, m[temp] = 0;
    }
    else {
        if (n == 4) {
            cout << -1 << "\n";
            return;
        }
        else {
            ll temp3 = m[3];
            m[n - 1] = n - 2, m[n - 2] = n - 1;
            m[1] = 3, m[3] = 1;

            m[temp3] = 0, m[0] = temp3;
        }
    }

    set<pll> s;
    rep(i, n) {
        auto it = s.find({m[i], i});
        if (it == s.end()) s.insert({i, m[i]});
    }

    for (auto &x : s) cout << x.f << " " << x.s << "\n";
    cout << "\n";
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
