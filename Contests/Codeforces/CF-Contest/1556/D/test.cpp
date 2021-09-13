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

vll a;
ll asks(ll x, ll y) {
    cout << "or" << " " << x << " " << y << endl;
    ll ora;
    // cin >> ora;
    ora = (a[x - 1] | a[y - 1]);

    cout << "and" << " " << x << " " << y << endl;
    ll anda;
    // cin >> anda;
    anda = (a[x - 1] & a[y - 1]);

    ll sum = (ora + anda);
    return sum;
}
void solve() {
    ll n, k;
    cin >> n >> k;

    rep(i, n) {
        ll x;
        cin >> x;
        a.pb(x);
    }

    vll v;
    ll sumab = 0ll, sumbc = 0ll, sumac = 0ll;
    ll i = 1;
    sumab = asks(i, i + 1);
    sumbc = asks(i + 1, i + 2);
    sumac = asks(i, i + 2);

    ll mid = (sumab + sumbc - sumac) / 2;

    ll a1 = sumab - mid;
    ll c1 = sumbc - mid;

    v.pb(a1);
    v.pb(mid);
    v.pb(c1);

    FOR(i, 4, n) {
        ll len = sz(v);
        ll x = v[len - 1];

        ll sum = asks(len, len + 1);
        v.pb(sum - x);
    }


    debug(v);
    sort(all(v));

    ll ans = 0ll;
    ans = v[k - 1];

    cout << "finish " << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("../error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
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
