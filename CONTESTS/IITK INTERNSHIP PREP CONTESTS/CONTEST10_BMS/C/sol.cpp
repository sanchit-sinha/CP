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
#define get(x,c)            get<x>((c))
#define trav(a,x)           for(auto a = (x).begin() ; a != (x).end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

string to_string(string s) {return '"' + s + '"';} string to_string(const char* s) {return to_string((string) s);} string to_string(bool b) {return (b ? "true" : "false");} template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";} template <typename A>string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", ";} first = false; res += to_string(x);} res += "}"; return res;} void debug_out() { cerr << "\n"; } template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n"; debug_out(T...);}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
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
const ll N = 111;
vpll v[N];
ll n , m;

vll e[N][N];
set<ll> edges[N];
vll connected;
bool vis[N];
void dfs(ll node) {
    // connected.pb(node);
    vis[node] = 1;
    for (auto child : v[node]) {
        if (!vis[child.f]) {
            rep(i , sz(e[node][child.f])) {
                edges[e[node][child.f][i]].insert(child.f);
                edges[e[node][child.f][i]].insert(node);
            }
            dfs(child.f);
        }
    }
}

// bool visedges[N];
// bool vis2[N];
// void dfs2(ll node) {
//     vis2[node] = 1;
//     for (auto child : v[node]) {
//         if (!vis2[child.f]) {
//             if (visedges[child.s]) {
//                 x = max(x, node * child.f);
//             }
//             dfs2(child.f);
//         }
//     }
// }


void solve() {
    cin >> n;

    cin >> m;
    vll a(m);
    rep(i , m) cin >> a[i];

    cin >> m;
    vll b(m);
    rep(i , m) cin >> b[i];

    cin >> m;
    vll w(m);
    rep(i, m) cin >> w[i];

    rep(i, m) {
        ll x = a[i], y = b[i], wt = w[i];
        v[x].pb(mp(y, wt));
        v[y].pb(mp(x, wt));

        e[x][y].pb(wt);
        e[y][x].pb(wt);
    }


    ll ans = 0ll;
    FOR(i, 1, n) {
        if (!vis[i]) {
            // connected.clear();

            rep(j, 104) edges[j].clear();

            // x = 0ll;
            // rep(j, sz(edgesct)) edgesct[j] = 0;
            // rep(j , sz(edgesct)) visedges[j] = 0;

            dfs(i);

            // rep(j, sz(edgesct)) mxx = max(mxx, edgesct[j]);
            // rep(j , sz(edgesct)) {
            //     if (edgesct[j] == mxx) {
            //         debug(i, j);
            //         visedges[j] = 1;
            //     }
            // }

            // debug(i, x);
            ll mxx = 0;
            ll x = 0;
            FOR(j, 1, 100) {
                mxx = max(mxx, sz(edges[j]));
            }

            // FOR(j , 1 , 100) {
            //     if (sz(edges[j])) debug(edges[j]);
            // }

            FOR(j, 1, 100) {
                if (sz(edges[j]) == mxx) {
                    if (sz(edges[j]) >= 2) {
                        debug(edges[j]);
                        ll big1 = *edges[j].rbegin();

                        auto it = edges[j].find(big1);
                        if (it != edges[j].end()) edges[j].erase(it);

                        ll big2 = *edges[j].rbegin();

                        x = max(x, big1 * big2);
                    }
                }
            }

            ans = max(ans, x);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);

    ll NTC = 1;
    // cin>>NTC;

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
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
