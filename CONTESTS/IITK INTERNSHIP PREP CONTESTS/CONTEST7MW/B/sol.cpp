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

const ll N = 51;
ll dp[N + 3][N + 3][N + 3];
const ll dx[] = { -1, 0};
const ll dy[] = {0, -1};
ll n;

void solve() {
    cin >> n;

    vvll grid(n, vll(n, 0));
    rep(i, n) rep(j, n) cin >> grid[i][j];

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            for (ll ii = 0 ; ii < n; ii++) {
                dp[i][j][ii] = -inf;
            }
        }
    }

    if (grid[0][0] == -1 || grid[n - 1][n - 1] == -1) {
        cout << 0 << "\n";
        return;
    }

    for (ll x1 = 0; x1 < n; x1++) {
        for (ll y1 = 0; y1 < n; y1++) {

            for (ll x2 = 0; x2 < n; x2++) {
                ll y2 = (x1 + y1 - x2);
                if (y2 >= 0 && y2 < n && grid[x1][y1] != -1 && grid[x2][y2] != -1) {

                    if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0) {
                        dp[x1][y1][x2] = grid[x1][y1];
                    }
                    else {
                        for (ll k1 = 0; k1 < 2; k1++) {
                            for (ll k2 = 0; k2 < 2; k2++) {
                                ll newx1 = x1 + dx[k1], newy1 = y1 + dy[k1];
                                ll newx2 = x2 + dx[k2], newy2 = y2 + dy[k2];

                                if (newx1 >= 0 && newx1 < n && newx2 >= 0 && newx2 < n &&
                                        newy1 >= 0 && newy1 < n && newy2 >= 0 && newy2 < n &&
                                        grid[newx1][newy1] != -1 && grid[newx2][newy2] != -1 &&
                                        dp[newx1][newy1][newx2] != -inf) {

                                    if (x1 == x2 && y1 == y2) {
                                        dp[x1][y1][x2] = max(dp[x1][y1][x2], dp[newx1][newy1][newx2] + grid[x1][y1]);
                                    }
                                    else {
                                        dp[x1][y1][x2] = max(dp[x1][y1][x2], dp[newx1][newy1][newx2] + grid[x1][y1] + grid[x2][y2]);
                                    }

                                }
                            }
                        }
                    }

                }
            }
        }
    }

    ll ans = 0ll;
    if (dp[n - 1][n - 1][n - 1] == -inf) ans = 0ll;
    else ans = dp[n - 1][n - 1][n - 1];

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
