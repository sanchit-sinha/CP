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

const ll N = 1e5 + 11;
ll a[N], b[N];
map<ll, set<ll>> m;
ll n, x;

void change(ll i, ll j) {
    auto it1 = m[a[i]].find(i);
    if (it1 != m[a[i]].end()) m[a[i]].erase(it1);

    auto it2 = m[a[j]].find(j);
    if (it2 != m[a[j]].end()) m[a[j]].erase(it2);

    m[a[i]].insert(j);
    m[a[j]].insert(i);

    swap(a[i], a[j]);
}
void solve() {
    /// clear
    rep(i, n + 1ll) a[i] = b[i] = 0ll;
    m.clear();

    cin >> n >> x;
    rep(i, n) cin >> a[i], b[i] = a[i];
    rep(i, n) m[a[i]].insert(i);

    sort(b, b + n);
    if (DEBUG) {
        rep(i, n) cerr << b[i] << " ";
        cerr << "\n";
    }

    bool ok = 1;
    rep(i, n) {
        ll req = b[i];
        ll cur = a[i];

        if (req != cur) {
            ll j1 = *m[req].begin();
            ll j2 = *m[req].rbegin();

            if (abs(i - j2) >= x) {
                change(i, j2);
            }
            else if (abs(j1 - n + 1) >= x) {
                change(j1, n - 1);
                change(i, n - 1);
            }
            else if (abs(i) >= x && abs(j2) >= x) {
                change(j2, 0);
                change(i, 0);
                change(j2, 0);
            }
            else if (abs(j2) >= x && abs(i - n + 1) >= x && abs(n - 1) >= x) {
                change(j2, 0);
                change(0, n - 1);
                change(i, n - 1);
                change(0, j2);
            }
            else {
                ok = 0;
                break;
            }
        }

        auto it = m[a[i]].find(i);
        if (it != m[a[i]].end()) m[a[i]].erase(it);
    }

    if (ok) cout << "YES\n";
    else cout << "NO\n";
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
