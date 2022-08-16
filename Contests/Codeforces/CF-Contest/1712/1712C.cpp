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

ll res(ll pos, vll& v) {
    set<ll> s;
    rep(i, pos + 1) s.insert(v[i]);
    return sz(s);
}
void solve() {
    ll n;
    cin >> n;

    vll v(n);
    rep(i, n) cin >> v[i];

    if (is_sorted(all(v))) cout << 0 << "\n";
    else {
        auto check = [&](ll mid) {
            vector<bool> vis(n + 1, 0);
            // [0, mid] => 0
            rep(i, mid + 1) vis[v[i]] = 1;

            vll temp = v;
            rep(i, n) {
                if (vis[temp[i]]) temp[i] = 0;
            }

            debug(mid, temp);
            // FOR(i, mid + 1, n - 1) if (temp[i] == 0) return false;
            return is_sorted(all(temp));
        };


        ll l = 0, r = n - 1, pos = n - 1;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (check(mid)) r = mid - 1, pos = mid;
            else l = mid + 1;
        }

        ll ans = res(pos, v);

        map<ll, ll> mp;
        rep(i, n) mp[v[i]] = i;

        ll mxx = 0;
        FORR(i, n - 1, 1) {
            // 5 4 
            if (v[i - 1] > v[i]) {
                mxx = max(mxx, mp[v[i - 1]]);
            }
        }

        vector<bool> vis(n + 1, 0);
        rep(i, mxx + 1) vis[v[i]] = 1;

        vll temp = v;
        rep(i, n) {
            if (vis[v[i]]) v[i] = 0;
        }

        mp.clear();
        rep(i, n) mp[v[i]] = i;

        ll mx2 = 0;
        FORR(i, n - 1, 1) {
            // 5 4 
            if (v[i - 1] > v[i]) {
                mx2 = max(mx2, mp[v[i - 1]]);
            }
        }

        ll mx = max(mx2, mxx);
        ans = min(ans, res(mx, temp));

        cout << ans << "\n";
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

