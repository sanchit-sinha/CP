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
#define sz(c)               (int)((c).size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

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


void solve() {
    // multi-test
    ll n;
    cin >> n;

    vll a(n), b(n);
    ll sum1 = 0ll, sum2 = 0ll;

    rep(i, n) cin >> a[i], sum1 += a[i];
    rep(i, n) cin >> b[i], sum2 += b[i];

    debug(a, b);
    debug(sum1, sum2);
    if (sum1 != sum2) {
        cout << -1 << "\n";
        return;
    }

    set<ll> dec, inc;
    rep(i, n) {
        if (a[i] < b[i]) dec.insert(i);
        else if (a[i] > b[i]) inc.insert(i);
    }

    vpll ans;
    while (!dec.empty()) {
        ll index1 = *dec.begin();
        ll val1 = a[index1], req1 = b[index1]; // to increase

        ll index2 = *inc.begin();
        ll val2 = a[index2], req2 = b[index2]; // to decrease

        while (a[index1] != b[index1] && a[index2] != b[index2]) {
            a[index1]++, a[index2]--;
            ans.pb({index2 + 1, index1 + 1});
        }

        if (a[index1] == b[index1]) dec.erase(dec.find(index1));
        if (a[index2] == b[index2]) inc.erase(inc.find(index2));
    }
    // rep(i, n - 1) {
    //     if (a[i] > b[i]) {
    //         while (a[i] != b[i]) {
    //             a[i]--, a[n - 1]++;
    //             ans.pb({i + 1, n});
    //         }
    //     }
    // }

    // debug(a, b);
    // rep(i , n - 1) {
    //     if (a[i] < b[i]) {
    //         while (a[i] != b[i]) {
    //             a[i]++, a[n - 1]--;
    //             ans.pb({n, i + 1});
    //         }
    //     }
    // }
    // debug(a, b);

    if (sz(inc) == 0 && sz(dec) == 0 && sz(ans) <= 100) {
        cout << sz(ans) << "\n";
        for (auto x : ans) cout << x.f << " " << x.s << "\n";
        return;
    }

    cout << -1 << "\n";
    return;

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
