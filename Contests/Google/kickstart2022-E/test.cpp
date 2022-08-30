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
    if (op == '+') return prev + add;
    if (op == '-') return prev - add;
    if (op == '*') return prev * add;
    if (op == '/') return prev / add;

    return 0;
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


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll range(ll l, ll r) {
    ll n = uniform_int_distribution<int>(l, r)(rng);
    return n;
}

void solve() {
    ll n, p, m, ar, ac;
    vector<char> op(4, '?');
    vll toll(4, 0);

    while (1) {
        n = range(1, 2);
        m = range(1, 5);
        p = 0;
        ar = range(0, n - 1);
        ac = range(0, n - 1);

        rep(i, 4) {
            ll opp = range(1, 4);
            if (opp == 1) op[i] = '+';
            else if (opp == 2) op[i] = '-';
            else if (opp == 3) op[i] = '+';
            else if (opp == 4) op[i] = '/';

            ll val = range(1, 4);
            toll[i] = val;
        }


        if (p) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        auto brute = [&]() {
            ll mx = 0ll;
            rep(N, m + 1) {
                rep(E, m + 1) {
                    rep(W, m + 1) {
                        rep(S, m + 1) {
                            if (N + E + W + S <= m) {
                                vll temp;
                                rep(k, N) temp.pb(0);
                                rep(k, E) temp.pb(1);
                                rep(k, W) temp.pb(2);
                                rep(k, S) temp.pb(3);

                                do {
                                    ll x = ar, y = ac;
                                    ll val = 0ll;
                                    for (auto& k : temp) {
                                        x += dx[k], y += dy[k];
                                        if (x >= 0 && x < n && y >= 0 && y < n) {
                                            val = operate(val, toll[k], op[k]);
                                            mx = max(mx, val);
                                        }
                                        else break;
                                    }
                                } while (next_permutation(all(temp)));
                            }
                        }
                    }
                }
            }
            return mx;
        };

        auto DP = [&]() {
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

            if (DEBUGG) {
                rep(t, m + 1) {
                    cerr << t << ":\n ";
                    rep(i, n) {
                        rep(j, n) {
                            if (dp[i][j][t] == -inf) cerr << "-5 ";
                            else cerr << dp[i][j][t] << " ";
                        }
                        cerr << "\n";
                    }
                    cerr << "\n";
                    cerr << "\n";
                }
            }

            return ans;
        };


        if (brute() != DP()) {
            cout << "FALSE\n";
            cout << n << " " << p << " " << m << " " << ar + 1 << " " << ac + 1 << "\n";
            rep(i, 4) cout << op[i] << " " << toll[i] << "\n";

            debug(brute());
            debug(DP());

            break;
        }
        else cout << "TRUE\n";
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
        cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) { if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex, ll md) { ll ans = 1ll; while (ex > 0) { if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md; } return ans; }

