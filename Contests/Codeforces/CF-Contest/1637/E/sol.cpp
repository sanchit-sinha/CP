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

    vll a(n);
    rep(i, n) cin >> a[i];

    set<pll> banned;
    vpll v;
    rep(i, m) {
        ll x, y;
        cin >> x >> y;

        v.pb({x, y});
        banned.insert({x, y});
        banned.insert({y, x});
    }

    map<ll, ll> mp;
    rep(i, n) mp[a[i]]++;

    ll ans = 0ll;
    auto ban = [&](ll x, ll y) {
        if (x == y) return true;
        return (banned.find({x, y}) != banned.end());
    };

    auto add = [&](ll x, ll y) {
        ll cntx = mp[x], cnty = mp[y];
        ll val = (cntx + cnty) * (x + y);
        return val;
    };

    if (sz(mp) <= 600) {
        for (auto &x : mp) {
            for (auto &y : mp) {
                if (x.f == y.f) continue;
                if (!ban(x.f, y.f)) {
                    ans = max(ans, add(x.f, y.f));
                }
            }
        }
    }
    else {
        map<ll, vll> cnt;
        for (auto &x : mp) {
            cnt[x.s].pb(x.f);
        }


        if (DEBUG) {
            for (auto &x : cnt) debug(x.f, x.s);
        }

        for (auto &x : cnt) {
            for (auto &y : cnt) {
                if (x.f == y.f) {
                    if (sz(cnt[x.f]) > 1) {
                        ll len = sz(cnt[x.f]);
                        ll mxx = cnt[x.f][len - 1], mxy = cnt[x.f][len - 2];
                        if (!ban(mxx, mxy)) ans = max(ans, add(mxx, mxy));
                    }
                }
                else {
                    ll mxx = (x.s).back(), mxy = (y.s).back();
                    if (!ban(mxx, mxy)) ans = max(ans, add(mxx, mxy));
                }
            }
        }

        rep(i, m) {
            ll x = v[i].f, y = v[i].s;
            ll cntx = mp[x], cnty = mp[y];

            auto it1 = lb(all(cnt[cntx]), (x));
            if (it1 != cnt[cntx].begin()) {
                --it1;
                if (!ban(*it1, y)) {
                    ans = max(ans, add(*it1, y));
                }
            }

            auto it2 = lb(all(cnt[cnty]), (y));
            if (it2 != cnt[cnty].begin()) {
                --it2;
                if (!ban(*it2, x)) {
                    ans = max(ans, add(x, *it2));
                }
            }
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
