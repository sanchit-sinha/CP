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

bool check(ll mid, ll n, ll m, vvll &p, vector<multiset<pll>> &fr) {
    vector<bool> vis(m, 0);
    rep(i, n) {
        auto p = *fr[i].rbegin();
        if (p.f < mid) return 0;
        else {
            vis[p.s] = 1;
        }
    }

    ll all = 0;
    rep(i, m) all += (vis[i] == 1);
    assert(all <= n);

    if (all <= n - 1) return 1;

    if (all == n && m >= 2) {
        rep(i, m) {
            ll cnt = 0ll;
            rep(j, n) {
                if (p[i][j] >= mid) cnt ++;
            }

            if (cnt > 1) return 1;
        }
        return 0;
    }

    return 1;
}


void solve() {
    ll n, m;
    cin >> m >> n;

    vvll p(m, vll(n, 0));
    vector<multiset<pll>> fr(n);

    ll mx = 0ll;
    rep(i, m) rep(j, n) cin >> p[i][j], mx = max(mx, p[i][j]);

    rep(j, n) {
        rep(i, m) {
            fr[j].insert({p[i][j], i});
        }
    }

    debug(fr);

    ll ans = 0, l = 0, r = mx;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid, n, m, p, fr)) {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
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
