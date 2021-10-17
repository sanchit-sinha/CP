#include "bits/stdc++.h"
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
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin(); a != x.end(); a++)
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

ll dist(ll x, ll y, ll i, ll j) {
    return abs(x - i) + abs(y - j);
}
ll calc(vll &x1, vll &y1, vll &x2, vll &y2, ll x, ll y) {
    ll n = sz(x1);
    ll ans = 0;
    rep(i, n) {
        ll xx1 = x1[i], yy1 = y1[i], xx2 = x2[i], yy2 = y2[i];

        ll val = inf;
        if (x <= xx2 && x >= xx1) {
            if (y <= yy2 && y >= yy1) val = 0;
            else {
                val = min(val, abs(yy1 - y));
                val = min(val, abs(yy2 - y));
            }
        }
        else if (y <= yy2 && y >= yy1) {
            if (x <= xx2 && x >= xx1) val = 0;
            else {
                val = min(val, abs(xx1 - x));
                val = min(val, abs(xx2 - x));
            }
        }
        else {
            val = min(val, dist(xx1, yy1, x, y));
            val = min(val, dist(xx2, yy1, x, y));
            val = min(val, dist(xx1, yy2, x, y));
            val = min(val, dist(xx2, yy2, x, y));
        }

        ans += val;

    }

    return ans;
}
void solve() {
    ll k;
    cin >> k;

    vll x1(k), y1(k);
    vll x2(k), y2(k);
    rep(i, k) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

    pll ans = { -1, -1}; ll mn = inf;
    FOR(i, -100, 100) {
        FOR(j, -100, 100) {
            ll steps = calc(x1, y1, x2, y2, i, j);
            if (steps < mn) mn = steps, ans = {i, j};
        }
    }
    cout << ans.f << " " << ans.s << "\n";
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
        cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
