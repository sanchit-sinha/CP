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

const ll inf = 4e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
void solve() {
    ll n, m;
    cin >> n >> m;

    vector<string> s(n);
    rep(i, n) cin >> s[i];

    pll lab = { -1, -1};
    rep(i, n) rep(j, m) if (s[i][j] == 'L') lab = {i, j};

    queue<pll> q;
    q.push(lab);

    vvll vis(n, vll(m, 0));
    vis[lab.f][lab.s] = 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        rep(k, 4) {
            ll i = cur.f + dx[k];
            ll j = cur.s + dy[k];

            if (i < 0 || i >= n) continue;
            if (j < 0 || j >= m) continue;


            if (!vis[i][j] && s[i][j] != '#') {
                bool good = 0;
                ll fcells = 0;
                rep(l, 4) {
                    ll x = i + dx[l];
                    ll y = j + dy[l];


                    if (x < 0 || x >= n) continue;
                    if (y < 0 || y >= m) continue;


                    if (vis[x][y]) {
                        if (s[x][y] == 'L' || s[x][y] == '+') good = 1;
                    }
                    if (s[x][y] == '.') fcells += 1;
                }

                if (good && fcells <= 1) {
                    s[i][j] = '+';
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

    }

    rep(i, n) cout << s[i] << "\n";
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
