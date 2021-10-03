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
#define pll                 pair<ll , ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (ll)((c).size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(ll i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(ll i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(ll i = (b); i >= (a); i--)

#ifdef LOCAL
#include "debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#define cerr if(false) cerr
#endif


inline ll gcd(ll a, ll b) {if (b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a, ll b) {return ((a > b) ? a : b);}
inline ll min(ll a, ll b) {return ((a > b) ? b : a);}
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 21;
ll n;
ll x[N], y[N];
ll xb, yb;

ll online(ll x1, ll y1, ll x2, ll y2, ll x, ll y) {
    ll val1 = (y2 - y1) * (x2 - x);
    ll val2 = (y2 - y) * (x2 - x1);
    return (val1 == val2);
}

ld dis(ll x1, ll y1, ll x2, ll y2) {
    ll x = (x1 - x2) * (x1 - x2);
    ll y = (y1 - y2) * (y1 - y2);

    return sqrt(x + y);
}
pair<bool, ld> check3(vll &index) {
    ld res = 0.0;

    ll xs = x[index[0]], ys = y[index[0]];
    FOR(i, 1, 2) {
        ll xx = x[index[i]], yy = y[index[i]];
        ll xp = x[index[i - 1]], yp = y[index[i - 1]];

        if (!online(xp, yp, xx, yy, xb, yb)) {
            res += dis(xp, yp, xx, yy);
        }
        else return {0, res};
    }

    return {1, res};
}
void solve() {
    rep(i, n + 1) {
        x[i] = y[i] = 0;
    }
    xb = 0, yb = 0;

    cin >> n;
    rep(i, n) cin >> x[i] >> y[i];

    if (n <= 2) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vll index;
    rep(i, n) index.pb(i);

    ld ans = inf;
    do {
        auto p = check3(index);
        if (p.f) {
            ans = max(ans, p.s);
        }
    } while (next_permutation(all(index)));

    if (ans == inf) {
        cout << "IMPOSSIBLE\n";
        return;
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
        cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
