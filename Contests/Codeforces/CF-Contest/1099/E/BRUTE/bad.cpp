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
#include "../debug.cpp"
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

string A = "ACGT";
set<vector<string>> ans;
bool check(vector<string> &s) {
    ll n = sz(s);
    ll m = sz(s[0]);

    rep(i , n) {
        rep(j , m) {
            set<char> t;
            int ct = 1;
            t.insert(s[i][j]);

            if (i + 1 < n) t.insert(s[i + 1][j]), ct++;
            if (j + 1 < m) t.insert(s[i][j + 1]), ct++;
            if (i + 1 < n && j + 1 < m) t.insert(s[i + 1][j + 1]), ct++;

            if (sz(t) != ct) return 0;
        }
    }

    return 1;
}
void backtrack(vector<string> &s, vector<string> &grid, ll filled) {
    ll n = sz(s);
    ll m = sz(s[0]);

    if (filled == n * m) {
        if (check(grid))
            ans.insert(grid);
        return;
    }

    rep(i , n) {
        rep(j , m) {
            if (grid[i][j] == '?') {
                string use;
                if (j - 1 >= 0) use.pb(grid[i][j - 1]);
                if (i - 1 >= 0) use.pb(grid[i - 1][j]);
                if (i - 1 >= 0 && j - 1 >= 0) use.pb(grid[i - 1][j - 1]);

                rep(k, sz(A)) {
                    bool got = 0;
                    rep(l , sz(use)) {
                        if (A[k] == use[l]) got = 1;
                    }

                    if (!got) {
                        grid[i][j] = A[k];
                        backtrack(s, grid, filled + 1);
                        grid[i][j] = '?';
                    }
                }

                return;
            }
        }
    }

    return;
}

ll count(vector<string> &s, vector<string> &t) {
    ll n = sz(s);
    ll m = sz(s[0]);

    ll ans = 0ll;
    rep(i , n) {
        rep(j , m) ans += 1ll * (s[i][j] != t[i][j]);
    }

    return ans;
}

ll brute(ll n, ll m, vector<string> &s) {
    vector<string> grid(n, string(m , '?'));

    backtrack(s, grid, 0);
    ll mn = inf;
    trav(it , ans) {
        vector<string> t = *it;
        ll x = count(s, t);
        mn = min(mn , x);
    }

    set<vector<string>> newans;
    trav(it , ans) {
        vector<string> t = *it;
        if (count(s, t) == mn) {
            newans.insert(*it);
        }
    }

    // cout << "minimum moves : " << mn << "\n";
    // ll index = 1;
    // trav(it , newans) {
    //     cout << index++ << "\n";
    //     rep(ii , n) {
    //         rep(jj , m) cout << (*it)[ii][jj];
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }

    return mn;
}
void solve() {
    ll n, m;
    cin >> n >> m;

    vector<string> s(n);
    rep(i , n) cin >> s[i];

    // vector<string> use;
    // string B = A;
    // do {
    //     use.pb(B);
    // } while (next_permutation(all(B)));

    // vector<string> grid(n, string(m , '?'));
    // vector<string> ans;
    // ll mn = inf;
    // rep(ii , sz(use)) {
    //     string t = use[ii];
    //     grid[0][0] = t[0];
    //     grid[0][1] = t[1];
    //     grid[1][0] = t[2];
    //     grid[1][1] = t[3];

    //     rep(i, n) {
    //         rep(j , m) {
    //             if (i >= 2) grid[i][j] = grid[i - 2][j];
    //             else {
    //                 if (j >= 2) {
    //                     grid[i][j] = grid[i][j - 2];
    //                 }
    //             }
    //         }
    //     }

    //     if (check(grid)) {
    //         if (t == "ATGC") debug(grid);
    //         ll cnt = count(s, grid);
    //         if (mn < cnt) ans = grid;
    //         mn = min(mn , cnt);
    //     }

    //     vector<string> grid1 = grid;
    //     for (int i = 1 ; i < n ; i += 2) {
    //         swap(grid1[i][m - 1] , grid1[i - 1][m - 1]);
    //     }
    //     if (n & 1) grid1[n - 1][m - 1] = grid[n - 2][m - 1];

    //     if (check(grid1)) {
    //         if (t == "ATGC") debug(grid1);
    //         ll cnt = count(s, grid1);
    //         if (mn < cnt) ans = grid1;
    //         mn = min(mn , cnt);
    //     }
    // }

    ll mn = brute(n, m, s);
    // cout << "MOVES: " << mn << "\n";
    // rep(i , n) {
    //     rep(j , m) cout << ans[i][j];
    //     cout << "\n";
    // }
    // cout << "\n";

    cout << mn << "\n";
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
