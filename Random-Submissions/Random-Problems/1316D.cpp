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

const ll N = 1e3 + 11;
ll n;
pll a[N + N][N + N];
char s[N][N], temp[N][N];

ll dx[4] = { 1 , -1 , 0 , 0 };
ll dy[4] = { 0 , 0 , 1 , -1 };
bool vis[N + 3][N + 3];
char gen(ll sx, ll sy, ll ex, ll ey) {
    if (sx == ex) {
        if (ey == sy - 1) return 'L';
        else return 'R';
    }

    if (sy == ey) {
        if (ex == sx - 1) return 'U';
        else return 'D';
    }

    return '!';
}


void solve() {
    cin >> n;
    rep(i, n) rep(j, n) s[i][j] = '.';

    rep(i, n) {
        rep(j, n) {
            ll x, y;
            cin >> x >> y;
            --x, --y;

            a[i][j] = make_pair(x, y);
            if (x == i && y == j) vis[i][j] = 1, s[i][j] = 'X';
            if (x < 0 || y < 0) s[i][j] = '?';
        }
    }

    if (DEBUGG) {
        cerr << 1 << "\n";
        rep(i, n) {
            rep(j, n) cerr << s[i][j];
            cerr << "\n";
        }
        cerr << "\n";
    }

    rep(i, n) {
        rep(j, n) {
            if (s[i][j] == '.') {
                ll x = a[i][j].f, y = a[i][j].s;
                if (s[x][y] != 'X') {
                    cout << "INVALID\n";
                    return;
                }
            }
        }
    }

    if (DEBUGG) {
        cerr << 2 << "\n";
        rep(i, n) {
            rep(j, n) cerr << s[i][j];
            cerr << "\n";
        }
        cerr << "\n";
    }


    rep(i, n) {
        rep(j, n) {
            if (s[i][j] == 'X') {
                queue<pll> q;
                q.push({ i,j });
                vis[i][j] = 1;

                while (sz(q)) {
                    auto cur = q.front();
                    ll xx = cur.f, yy = cur.s;
                    q.pop();
                    rep(k, 4) { // go to child with val as (i,j);
                        ll x = xx - dx[k];
                        ll y = yy - dy[k];
                        if (x >= 0 && y >= 0 && x < n && y < n && vis[x][y] == 0) {
                            if (s[x][y] != 'X' && s[x][y] != '?') {
                                if (a[x][y].f == i && a[x][y].s == j) {
                                    vis[x][y] = 1;
                                    q.push({ x,y });
                                    s[x][y] = gen(x, y, xx, yy);
                                }
                            }
                        }
                    }
                }

            }
        }
    }

    if (DEBUGG) {
        cerr << 3 << "\n";
        rep(i, n) {
            rep(j, n) cerr << s[i][j];
            cerr << "\n";
        }
        cerr << "\n";
    }

    // remaining are to place -1s 
    rep(i, n) rep(j, n) temp[i][j] = s[i][j];
    bool ok = 1;
    rep(i, n) {
        rep(j, n) {
            if (temp[i][j] == '?') {
                ll cnt = 0ll;
                rep(k, 4) { // go to child with val as (i,j);
                    ll x = i - dx[k];
                    ll y = j - dy[k];
                    if (x >= 0 && y >= 0 && x < n && y < n && vis[x][y] == 0) {
                        if (s[x][y] == '?') {
                            cnt++;
                        }
                    }
                }

                if (cnt == 0ll) {
                    cout << "INVALID\n";
                    return;
                }

                rep(k, 4) { // go to child with val as (i,j);
                    ll x = i - dx[k];
                    ll y = j - dy[k];
                    if (x >= 0 && y >= 0 && x < n && y < n && vis[x][y] == 0) {
                        if (s[x][y] == '?') {
                            if (temp[x][y] == '?') {
                                char move = gen(x, y, i, j);
                                temp[x][y] = move;
                            }
                            temp[i][j] = gen(i, j, x, y);
                        }
                    }
                    }
                }
            }
        }

    if (!ok) {
        cout << "INVALID\n";
        return;
    }

    rep(i, n) rep(j, n) s[i][j] = temp[i][j];

    if (DEBUGG) {
        rep(i, n) {
            rep(j, n) cerr << s[i][j];
            cerr << "\n";
        }
    }


    rep(i, n) {
        rep(j, n) {
            if (s[i][j] == '.') {
                cout << "INVALID\n";
                return;
            }
        }
    }

    cout << "VALID\n";
    rep(i, n) {
        rep(j, n) cout << s[i][j];
        cout << "\n";
    }
}

int main() {
#ifdef ERROR
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

ll power(ll x, ll y) { if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex, ll md) { ll ans = 1ll; while (ex > 0) { if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md; } return ans; }

