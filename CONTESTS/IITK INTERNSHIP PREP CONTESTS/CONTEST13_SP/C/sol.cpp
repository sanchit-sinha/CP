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
const ll N = 5e3 + 1ll;

bool vis[N][52];
ll n, m, k;
vpll v[N];
ll dis[N][52];

void dij(ll node) {
    set<pair<pll, ll> > s;
    FOR(i, 1, n) {
        rep(j , 52) {
            if (i == node) {
                dis[i][j] = 0;
                s.insert(mp(mp(dis[i][j], j), i));
            }
            else {
                dis[i][j] = LLONG_MAX;
                s.insert(mp(mp(dis[i][j], j), i));
            }
        }
    }

    while (!s.empty()) {
        pair<pll, ll> p = *s.begin();
        ll from = p.s;
        ll moves = p.f.s;

        vis[from][moves] = 1;
        s.erase(s.begin());
        for (auto child : v[from]) {
            ll to = child.first;
            ll len = child.second;

            if (!vis[to][moves]) {
                if (dis[from][moves] + len < dis[to][moves]) {
                    pll p1 = mp(dis[to][moves], moves);
                    pair<pll, ll> p = mp(p1, to);
                    s.erase(s.find(p));

                    dis[to][moves] = dis[from][moves] + len;
                    p.f.f = dis[to][moves];
                    s.insert(p);
                }
            }

            if (moves + 1 < 51 && !vis[to][moves + 1]) {
                if (dis[from][moves] < dis[to][moves + 1]) {
                    pll p1 = mp(dis[to][moves + 1], moves + 1);
                    pair<pll, ll> p = mp(p1, to);
                    s.erase(s.find(p));

                    dis[to][moves + 1] = dis[from][moves];
                    p.f.f = dis[to][moves + 1];
                    s.insert(p);
                }
            }
        }
    }
}
void solve() {
    cin >> n >> m >> k;
    rep(i, m) {
        ll x, y , c;
        cin >> x >> y >> c;

        v[x].pb({y, c});
        v[y].pb({x, c});
    }

    dij(1);

    FOR(i, 1, n) {
        ll ans = inf;
        FOR(j, 0, k) ans = min(ans, dis[i][j]);

        cout << ans << " ";
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
    // cin >> NTC;

#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    factorial();
#endif
#ifdef PREPROCESS
    preprocess();
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
