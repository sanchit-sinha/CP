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

const ll N = 104;
ll dx[4] = { 1 , -1 , 0 , 0 };
ll dy[4] = { 0 , 0 , 1 , -1 };
bool vis[N + 3][N + 3];
ll n, m;
string s[N];
vpll comp;
void dfs(ll i, ll j) {
    vis[i][j] = 1;
    comp.pb({ i,j });
    for (ll k = 0;k < 4;k++) {
        ll x = i - dx[k];
        ll y = j - dy[k];
        if (x >= 0 && y >= 0 && x < n && y < m && vis[x][y] == 0 && s[x][y] == '1') {
            dfs(x, y);
        }
    }
}

void solve() {
    // clear
    rep(i, n + 1) {
        rep(j, m + 1) vis[i][j] = 0;
        s[i].clear();
    }
    comp.clear();

    cin >> n >> m;
    rep(i, n) cin >> s[i];

    if (DEBUGG) {
        rep(i, n) debug(s[i]);
    }

    rep(i, n) {
        rep(j, m) {
            if (!vis[i][j]) {
                if (s[i][j] == '1') {
                    comp.clear();
                    dfs(i, j);

                    //add
                    /*
                    set<pll> xmn_ymx, xmx_ymx, xmn_ymn, xmx_ymn;
                    for (auto& p : comp) {
                        ll x = p.f, y = p.s;
                        xmn_ymn.insert({ x,y });
                        xmn_ymx.insert({ x,-y });
                        xmx_ymn.insert({ -x,y });
                        xmx_ymx.insert({ -x,-y });
                    }

                    debug(xmn_ymn);
                    debug(xmn_ymx);
                    debug(xmx_ymn);
                    debug(xmx_ymx);

                    if (xmn_ymn.begin()->f != xmn_ymx.begin()->f) {
                        cout << "NO\n";
                        return;
                    }

                    if (xmx_ymn.begin()->f != xmx_ymx.begin()->f) {
                        cout << "NO\n";
                        return;
                    }

                    if (xmn_ymn.begin()->s != xmx_ymn.begin()->s) {
                        cout << "NO\n";
                        return;
                    }

                    if (xmn_ymx.begin()->s != xmx_ymx.begin()->s) {
                        cout << "NO\n";
                        return;
                    }
                    */

                    map<ll, set<ll>> mp;
                    for (auto& p : comp) {
                        ll x = p.f, y = p.s;
                        mp[x].insert(y);
                    }

                    ll len = sz(mp.begin()->s);
                    ll ymn = *(mp.begin()->s).begin();
                    ll ymx = *(mp.begin()->s).rbegin();
                    for (auto& x : mp) {
                        if (sz(x.s) != len) {
                            cout << "NO\n";
                            return;
                        }
                        ll mn = *((x.s).begin());
                        ll mx = *((x.s).rbegin());

                        if (mn != ymn || mx != ymx) {
                            cout << "NO\n";
                            return;
                        }
                    }
                }
            }
        }
    }

    cout << "YES\n";
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
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) { if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex, ll md) { ll ans = 1ll; while (ex > 0) { if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md; } return ans; }

