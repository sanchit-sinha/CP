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


void solve() {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll len = sz(s);
    if (s[0] == 'D') {
        rep(i, len) {
            if (s[i] == 'R') s[i] = 'D';
            else s[i] = 'R';
        }
    }

    ll r = 0ll, d = 0ll;
    ll rem = n - 1;

    rep(i, len) {
        r += (s[i] == 'R');
        d += (s[i] == 'D');
    }

    if (r == 0) {
        cout << n << "\n";
        return;
    }
    else if (d == 0) {
        cout << n << "\n";
        return;
    }


    ll remr = n - r - 1;
    ll remd = n - d - 1;
    debug(remr, remd);

    ll ans = 0ll; // cant paint
    ll dused = 0ll, rused = 0ll;

    bool okr = 0, okd = 0;
    rep(i, len) {
        if (s[i] == 'R') {
            ll cnt = 0ll;
            while (i < len && s[i] == 'R') i++, cnt++;
            i--;

            rused += cnt;
            if (okr == 0) rused += remr;
            okr = 1;

            cerr << 1 << " " << n - 1 - dused << " " << cnt << "\n";
            ans += ((n - 1 - dused) * cnt);
        }
        else {
            ll cnt = 0ll;
            while (i < len && s[i] == 'D') i++, cnt++;
            i--;

            dused += cnt;
            if (okd == 0) dused += remd;
            okd = 1;

            cerr << 2 << " " << n - 1 - rused << " " << cnt << "\n";
            ans += ((n - 1 - rused) * cnt);

        }
    }

    debug(ans, dused, rused);

    ll res = (n * n) - 1ll * ans;
    cout << res << "\n";
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
