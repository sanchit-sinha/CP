#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define ll long long
#define ld long double
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define mt make_tuple
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define all(c) (c).begin(), (c).end()
#define sz(c) (ll)((c).size())
#define get(x, c) get<x>(c)
#define trav(a, x) for (auto a = x.begin(); a != x.end(); a++)
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define FORR(i, b, a) for (ll i = (b); i >= (a); i--)

#ifdef LOCAL
bool DEBUG = 1;
#include "debug.cpp"
#else
bool DEBUG = 0;
#define debug(...) 42
#define cerr   \
    if (false) \
    cerr
#endif

inline ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    a %= b;
    return gcd(b, a);
}
inline ll max(ll a, ll b) { return ((a > b) ? a : b); }
inline ll min(ll a, ll b) { return ((a > b) ? b : a); }
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 4e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 5e6 + 11;
ll cnt[N];

void solve()
{
    ll n;
    cin >> n;
    ll mx = 0ll;

    vll a(n);
    rep(i, n) {
        cin >> a[i];
        mx = max(mx, a[i]);

        for (ll j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                ll div1 = j, div2 = a[i] / j;
                cnt[div1]++;
                if (div1 != div2)
                    cnt[div2]++;
            }
        }
    }

    if (DEBUG) {
        debug(mx);
        FOR(k, 1, 10) {
            cerr << k << ": " << cnt[k] << "\n";
        }
    }

    ll ans = 0ll, g = 1ll;
    FORR(i, n, 1) {
        ll mxx = 1ll;
        for (ll j = g; j <= mx; j += g) {
            if (cnt[j] >= i) {
                mxx = max(mxx, j);
            }
        }

        ans += mxx;
        debug(i, mxx);

        g = mxx;
    }

    cout << ans << "\n";
}

// [v]:  {100, 10, 10, 5, 1, 3, 3, 7, 42, 54}
// [i, g]:  10 1
// [i, g]:  9 1
// [i, g]:  8 1
// [i, g]:  7 1
// [i, g]:  6 1
// [i, g]:  5 1
// [i, g]:  4 5
// [i, g]:  3 10
// [i, g]:  2 10
// [i, g]:  1 100

int main()
{
#ifdef LOCAL
    freopen("../error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    ll NTC = 1;
    // cin >> NTC;

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
    while ((PTC++) < NTC)
    {
        cerr << "Testcase # " << PTC << "\n";
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll a = power(x, y / 2);
    if (y % 2 == 0)
        return a * a;
    else
        return x * a * a;
}
ll powermod(ll x, ll ex, ll md)
{
    ll ans = 1ll;
    while (ex > 0)
    {
        if (ex & 1ll)
            ans = (ans * x) % md;
        ex >>= 1ll;
        x = (x * x) % md;
    }
    return ans;
}
