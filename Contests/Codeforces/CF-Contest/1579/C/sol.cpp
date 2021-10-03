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

const ll inf = 4e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

bool iscenter(ll i, ll j, vector<string> &s) {
    ll n = sz(s);
    ll m = sz(s[0]);

    ll xl = i - 1, yl = j - 1;
    ll xr = i - 1, yr = j + 1;

    if (xl < 0 || xr < 0) return 0;
    if (yl < 0 || yr >= m) return 0;

    if (s[xl][yl]  == '*' && s[xr][yr] == '*') return 1;
    return 0;
}
void solve() {
    ll n, m , k;
    cin >> n >> m >> k;

    vector<string> s(n);
    rep(i, n) cin >> s[i];

    vpll c;
    rep(i, n) {
        rep(j, m) {
            if (s[i][j] == '*' && iscenter(i, j, s)) {
                c.pb({j, -i});
            }
        }
    }

    sort(all(c));
    debug(c);

    map<pll, vpll> mp;
    rep(index, sz(c)) {
        ll i = -c[index].s, j = c[index].f;
        ll xl = i - 1, yl = j - 1;
        ll xr = i - 1, yr = j + 1;

        // trav(it, mp) {
        //     debug("cell", it->f);
        //     debug("c", it->s);
        // }
        bool ok = 1;
        rep(temp, k) {
            if (xl < 0 || xr < 0) {
                ok = 0;
                break;
            }
            if (yl < 0 || yr >= m) {
                ok = 0;
                break;
            }

            if (s[xl][yl] == '*' && s[xr][yr] == '*') {
                // mp[ {xl, yl}].pb({i, j});
                // mp[ {xr, yr}].pb({i, j});
                xl--, yl--;
                xr--, yr++;
            }
            else {
                ok = 0;
                break;
            }
        }

        if (ok) {
            mp[ {i, j}] .pb({i, j});

            ll xl = i - 1, yl = j - 1;
            ll xr = i - 1, yr = j + 1;
            while (1) {
                if (xl < 0 || xr < 0) break;
                if (yl < 0 || yr >= m) break;

                if (s[xl][yl] == '*' && s[xr][yr] == '*') {
                    mp[ {xl, yl}].pb({i, j});
                    mp[ {xr, yr}].pb({i, j});
                    xl--, yl--;
                    xr--, yr++;
                }
                else {
                    break;
                }
            }

        }
    }

    // trav(it, mp) {
    //     debug("cell", it->f);
    //     debug("c", it->s);
    // }
    // return;

    rep(i, n) {
        rep(j, m) {
            if (s[i][j] == '*') {
                debug(mp[ {i, j}]);
                ll len = mp[ {i, j}].size();
                if (len == 0) {
                    debug(i, j);
                    debug(mp[ {i, j}]);
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
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
