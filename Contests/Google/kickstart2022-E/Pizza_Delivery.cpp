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
bool DEBUGG = 1;
#include "debug.cpp"
#else
bool DEBUGG = 0;
#define debug(...) 42
#define cerr if(false) cerr
#endif

inline ll gcd(ll a, ll b) { if (b == 0) return a; a %= b; return gcd(b, a); }
inline ll max(ll a, ll b) { return ((a > b) ? a : b); }
inline ll min(ll a, ll b) { return ((a > b) ? b : a); }
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 4e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

// N E W S 
ll dx[4] = { -1, 0, 0, 1 };
ll dy[4] = { 0, 1, -1, 0 };


ll operate(ll prev, ll add, char op) {
    if (prev == -inf) return -inf;
    if (op == '+') return prev + add;
    if (op == '-') return prev - add;
    if (op == '*') return prev * add;
    if (op == '/') return (ll)floor((ld)prev / add);

    return -inf;
}
ll dir(ll fromx, ll fromy, ll tox, ll toy) {
    if (fromx == tox) {
        if (toy - fromy == 1) return 0; // O - -1: N
        else return 3;
    }

    if (fromy == toy) {
        if (tox - fromx == 1) return 1; // 0 - -1 : E
        else return 2; // 0 - 1 : W
    }

    return 0;
}
void solve() {
    ll n, p, m, ar, ac;
    cin >> n >> p >> m >> ar >> ac;
    --ar, --ac;

    vector<char> op(4, '?');
    vll toll(4, 0);
    rep(i, 4) {
        cin >> op[i] >> toll[i];
    }

    rep(i, p) {
        ll x, y, c;
        cin >> x >> y >> c;
        --x, --y;
    }

    if (p) {
        cout << "IMPOSSIBLE\n";
        return;
    }


    vector<vvll> dp(n + 1, vvll(n + 1, vll(m + 2, -inf)));

    FOR(t, 0, m) {
        rep(i, n) {
            rep(j, n) {
                if (t == 0) {
                    if (i == ar && j == ac) dp[i][j][t] = 0;
                }
                else {
                    ll ans = -inf;
                    ans = max(ans, dp[i][j][t - 1]);
                    rep(k, 4) {
                        ll x = i + dx[k], y = j + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            ll index = 3 - k;
                            ans = max(ans, operate(dp[x][y][t - 1], toll[index], op[index]));
                        }
                    }
                    dp[i][j][t] = ans;
                }
            }
        }
    }


    ll ans = 0ll;
    rep(i, n) {
        rep(j, n) {
            ans = max(ans, dp[i][j][m]);
        }
    }

    cout << ans << "\n";
}

int main() {
#ifdef ERROR
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
        cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) { if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex, ll md) { ll ans = 1ll; while (ex > 0) { if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md; } return ans; }

