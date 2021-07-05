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
const ll N = 1e5 + 11;

ll n;
vpll v[N];
ll ct[26], val[26];
map<ll, vpll> vis;
ll ans = 0ll;
void dfs(ll node, ll pr) {
    for (auto child : v[node]) {
        if (child.f != pr) {
            ll wt = child.s;
            // debug(node, child.f, wt);
            ct[wt]++; // update

            rep(j, 26) val[j] = ct[j] % 2;
            ll x = 0ll;
            rep(j, 26) {
                if (val[j]) x += (1ll << j);
            }
            if (vis.count(x)) {
                debug("pair", child.f, vis[x]);
                ans += sz(vis[x]);
            }
            rep(j, 26) {
                ll z = (1ll << j);
                ll y = (x ^ z);
                if (vis.count(y)) {
                    // debug("got", node, child.f, x, y, sz(vis[y]));
                    debug("pair", child.f, vis[y]);
                    ans += sz(vis[y]);
                }
            }

            // FOR(j, 0, 4) cerr << ct[j] << " ";
            // cerr << "\n";
            vis[x].pb({node, child.f}); // update

            dfs(child.f, node);
            // vis[x].pb({child.f, node}); // update

            ct[wt]--;
            rep(j, 26) val[j] = 0;
            // vis[x].pop_back();
        }
    }
}
void solve() {
    vis[0].pb({1, 0});
    cin >> n;
    rep(i , n - 1) {
        ll x, y;
        cin >> x >> y;

        char c;
        cin >> c;

        ll wt = (ll)(c - 'a');
        v[x].pb({y, wt});
        v[y].pb({x, wt});
    }

    dfs(1, 0);
    for (auto x : vis) {
        debug(x.f, x.s);
    }
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
