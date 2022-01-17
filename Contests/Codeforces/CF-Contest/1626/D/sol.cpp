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

ll GEQ(ll leny) {
    ll l = 0ll, r = 19ll, y = 19ll;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if ((1ll << mid) >= leny) y = mid, r = mid - 1;
        else l = mid + 1;
    }
    return y;
}
void solve() {
    ll n;
    cin >> n;

    vll a(n, 0);
    rep(i, n) cin >> a[i];
    sort(all(a));

    multiset<ll> index;
    index.insert(-1);
    FOR(i, 0, n - 2) {
        if (a[i] != a[i + 1]) index.insert(i);
    }
    ll ans = inf;
    auto getv = [&](ll i, ll b1, ll pos) {
        ll yy = pos - (b1 + 1) + 1;
        ll zz = n - 1 - (pos + 1) + 1;

        ll yans = GEQ(yy);
        ll zans = GEQ(zz);
        ll xans = GEQ(i);

        ll val = (1ll << xans) + (1ll << yans) + (1ll << zans);
        val -= n;

        return val;
    };

    debug(a);
    debug(index);
    FOR(i, 0, n) {
        if (i && a[i - 1] == a[i]) continue;

        ll b1 = i - 1;
        FOR(py, 0, 18) {
            // for 2^py as ans
            ll mny = 0ll, mxy = (1ll << py);
            if (py) mny = mxy / 2 + 1;

            ll b2 = b1 + mny;
            ll b3 = b1 + mxy;

            auto it2 = index.ub(b3);
            if (it2 != index.begin()) {
                it2--;
                ll pos = *it2;
                ll val = getv(i, b1, pos);

                ans = min(ans, val);
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
