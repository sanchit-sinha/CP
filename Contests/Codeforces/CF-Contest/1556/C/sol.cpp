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


void solve() {
    ll n;
    cin >> n;


    vll a(n);
    rep(i, n) cin >> a[i];

    vll open, close;
    rep(i, n) {
        if (i % 2 == 0) open.pb(a[i]);
        else close.pb(a[i]);
    }

    ll len = sz(close);
    ll ans = 0ll;

    debug(open);
    debug(close);
    rep(i, len) {
        ll toto = open[i];
        ll totc = close[i];
        ans += min(toto, totc);

        ll extrao = toto - totc;
        ll mx = 0ll;
        if (toto >= totc) {
            FOR(j, i + 1, len - 1) {
                ll o = open[j];
                ll c = close[j];

                if (toto < totc) break; // every point before final j this should be true
                if (c >= o) {
                    // ll extrac = c - o;
                    // ll extra_o = extrao - mx;

                    // ll extra_c = extrac - (toto - totc - extra_o);
                    // debug(i, j, extrao, mx, extrac, extra_o, extra_c);
                    // if (extra_o >= 0 && extra_c >= 0) {
                    //     ans += 1 + min(extra_o, extra_c);
                    // }

                    debug(mx);
                    ll extra_o = extrao - mx;
                    ll dif = (toto - totc - extra_o);
                    ll eo = 0 , ec = 0;
                    bool ok = 1;

                    eo = extra_o;
                    ec = c - o;
                    if (dif > 0) {
                        if (ec >= dif) ec -= dif;
                        else ok = 0;
                    }
                    else if (dif < 0) {
                        if (eo + dif >= 0) eo += dif;
                        else ok = 0;
                    }


                    if (ok) {
                        debug(i, j, toto, totc, dif, eo, ec);
                        ans += 1 + min(eo, ec);
                    }
                }

                toto += o;
                totc += c;

                mx = max(mx, totc - toto + extrao);
            }
        }
    }

    cout << ans << "\n";
}
// 8
// [s]:  "(()())((())()"
// [i, j]:  0 5
// [i, j]:  1 2
// [i, j]:  1 4
// [i, j]:  3 4
// [i, j]:  7 10
// [i, j]:  7 12
// [i, j]:  8 9
// [i, j]:  11 12
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
