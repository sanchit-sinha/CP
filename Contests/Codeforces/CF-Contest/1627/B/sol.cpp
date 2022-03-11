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
ll dis(pll p1, pll p2) {
    return abs(p1.f - p2.f) + abs(p1.s - p2.s);
}
void solve() {
    ll n, m;
    cin >> n >> m;

    vvll vis(n + 1, vll(m + 1, 0));

    queue<pair<pll, ll>> q;
    pll p1 = {0, 0}, p2 = {n - 1, 0}, p3 = {0, m - 1}, p4 = {n - 1, m - 1};

    ll mxx = inf;
    rep(i, n) {
        rep(j, m) {
            pll p = {i, j};
            ll mx = 0;
            mx = max(mx, dis(p1, p));
            mx = max(mx, dis(p2, p));
            mx = max(mx, dis(p3, p));
            mx = max(mx, dis(p4, p));

            mxx = min(mxx, mx);
        }
    }

    rep(i, n) {
        rep(j, m) {
            pll p = {i, j};
            ll mx = 0;
            mx = max(mx, dis(p1, p));
            mx = max(mx, dis(p2, p));
            mx = max(mx, dis(p3, p));
            mx = max(mx, dis(p4, p));

            if (mx == mxx) {
                q.push({p, mxx});
                vis[i][j] = 1;
            }
        }
    }
    // debug(q.front());
    // return;
    while (!q.empty()) {
        auto cur = q.front();
        pll p = cur.f; ll d = cur.s;

        while (sz(q) && cur.s == d) {
            q.pop();
            cout << d << " ";
            rep(k, 4) {
                ll x = cur.f.f + dx[k];
                ll y = cur.f.s + dy[k];

                if (x >= 0 && x < n && y >= 0 && y < m) {
                    if (!vis[x][y]) {
                        q.push({{x, y}, d + 1});
                        vis[x][y] = 1;
                    }
                }
            }

            cur = q.front();
        }
    }
    cout << "\n";

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