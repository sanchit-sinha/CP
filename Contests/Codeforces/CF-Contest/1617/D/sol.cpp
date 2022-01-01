#include "bits/stdc++.h"
using namespace std;
#define f                   first
#define s                   second
#define pb                  push_back
#define ll                  int
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

ll add = 0ll;
// vll cur = {0, 1, 1, 0, 1, 0, 0};
vll cur = {0, 0, 1, 1, 0, 0, 1, 0, 1, 0};
ll ans(ll a, ll b, ll c) {
    add++;
    ll x = 0ll;
    x += (cur[a] == 1);
    x += (cur[b] == 1);
    x += (cur[c] == 1);

    if (x >= 2) return 0;
    return 1;
}
ll ask(ll a, ll b, ll c) {
    cout << "? " << a << " " <<  b << " " << c << endl;

    ll res;
    cin >> res;
    // res = ans(a, b, c);

    return res;
}
void solve() {
    ll n;
    cin >> n;

    vll imp(n + 1, false);
    ll prev = 0;

    ll o = 0, z = 0;
    FOR(i, 1, n - 2) {
        ll res = ask(i, i + 1, i + 2);
        if (i > 1) {
            // i-1 i i+1 i+2
            if (res == 0 && prev == 1) o = i + 2, z = i - 1;
            if (res == 1 && prev == 0) z = i + 2, o = i - 1;
        }
        prev = res;
    }
    debug(o, z);

    imp[o] = 1;
    FOR(i, 1, n) {
        if (i == o || i == z) continue;
        ll res = ask(o, z, i);
        if (res == 0) imp[i] = 1;
    }


    ll len = 0ll;
    FOR(i, 1, n) len += (imp[i] == 1);

    cout << "! " << len << " ";
    FOR(i, 1, n) if (imp[i]) cout << i << " ";
    cout << endl;
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
