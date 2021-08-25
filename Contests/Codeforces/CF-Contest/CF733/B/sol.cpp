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

ll dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

void dfs(ll i, ll j, vector<string> &s) {
    ll n = sz(s), m = sz(s[0]);
    s[i][j] = '1';
    bool ok = 1;
    rep(k, 8) {
        ll x = i + dx[k], y = j + dy[k];
        if ((x == n - 1) || x == 0 || y == m - 1 || y == 0) {
            if (s[x][y] == '1') ok = 0;
        }
    }
}
void solve() {
    ll n, m;
    cin >> n >> m;

    vector<string> s(n, string(m, '0'));
    vector<string> t(n, string(m, '0'));

    ll ans = 0;
    rep(ii, m) {
        s[0][ii] = '1';
        rep(i, n) {
            rep(j, m) {
                if (s[i][j] == '0') {
                    if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                        bool ok = 1;
                        rep(k, 8) { // neighbours
                            ll x = i + dx[k], y = j + dy[k];
                            if (x >= 0 && x < n && y >= 0 && y < m) {
                                if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
                                    if (s[x][y] == '1') ok = 0 ;
                                }
                            }
                        }
                        if (ok) s[i][j] = '1';
                    }
                }
            }
        }

        ll one = 0;
        rep(i, n) {
            rep(j, m) {
                one += (s[i][j] == '1');
            }
        }

        if (one > ans) {
            ans = one;
            t = s;
        }

        rep(i, n) {
            rep(j, m) s[i][j] = '0';
        }
    }

    rep(i, n) cout << t[i] << "\n";
    cout << "\n";
}

int main() {
#ifdef LOCAL
    freopen(".. / error.txt", "w", stderr);
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
