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

string A = "ACGT";
set<vector<string>> ans;
void display(vector<string> &s) {
    ll n = sz(s);
    ll m = sz(s[0]);

    rep(i , n) {
        rep(j , m) cerr << s[i][j];
        cerr << "\n";
    }
    cerr << "\n";
}
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
    if (sz(s) != sz(t)) return inf;
    if (sz(s[0]) != sz(t[0])) return inf;
    ll n = sz(s);
    ll m = sz(s[0]);

    ll ans = 0ll;
    rep(i , n) {
        rep(j , m) ans += 1ll * (s[i][j] != t[i][j]);
    }

    return ans;
}

void brute(ll n, ll m, vector<string> &s) {
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

    cout << "minimum moves : " << mn << "\n";
    ll index = 1;
    trav(it , newans) {
        cout << index++ << "\n";
        rep(ii , n) {
            rep(jj , m) cout << (*it)[ii][jj];
            cout << "\n";
        }
        cout << "\n";
    }
}

void dothis(vector<string> &s, vector<string> &use, vector<string> &ANS, ll &mn, vector<string> &grid) {
    if (check(grid)) {
        ll n = sz(s);
        ll m = sz(s[0]);

        ll current = count(s, grid);
        vll rowrev(n, inf);
        vll colrev(m, inf);

        rep(i , n) {
            ll x = current;
            char a = grid[i][0];
            char b = grid[i][1];
            // a b a b => b a b a
            rep(j , m) {
                if (j % 2 == 0) {
                    if (s[i][j] == b) x--;
                    else {
                        if (s[i][j] == a) x++;
                    }
                }
                else if (j % 2) {
                    // put a
                    if (s[i][j] == a) x--;
                    else {
                        if (s[i][j] == b) x++;
                    }
                }
            }
            rowrev[i] = x;
        }

        rep(j , m) {
            ll x = current;
            char a = grid[0][j];
            char b = grid[1][j];
            // a b a b
            rep(i , n) {
                if (i % 2 == 0) {
                    if (s[i][j] == b) x--;
                    else {
                        if (s[i][j] == a) x++;
                    }
                }
                else if (i % 2) {
                    // put a
                    if (s[i][j] == a) x--;
                    else {
                        if (s[i][j] == b) x++;
                    }
                }
            }
            colrev[j] = x;
        }

        ll presans = inf;
        rep(i , n) presans = min(presans , rowrev[i]);
        rep(i , m) presans = min(presans , colrev[i]);

        if (presans < mn) {
            ll row = -1, col = -1;
            rep(i , n) if (rowrev[i] == presans) row = i;
            rep(j , m) if (colrev[j] == presans) col = j;
            debug("gotindside", row, col);

            if (row != -1) {
                vector<string> current = grid;
                char a = grid[row][0];
                char b = grid[row][1];

                rep(j , m) {
                    if (j % 2 == 0) {
                        current[row][j] = b;
                    }
                    else if (j % 2) {
                        current[row][j] = a;
                    }
                }

                mn = min(mn, presans);
                if (mn == presans) ANS = current;

                debug("in row", row, presans, mn);
                cerr << "INSIDE ANS\n";
                display(ANS);
                cerr << "\n";
                debug(count(s, ANS));

                cerr << "GRID\n";
                display(grid);
                debug(count(s, ANS));

                cerr << "****************\n";

            }
            else if (col != -1) {
                vector<string> current = grid;
                char a = grid[0][col];
                char b = grid[1][col];

                rep(i, n) {
                    if (i % 2 == 0) {
                        current[i][col] = b;
                    }
                    else if (i % 2) {
                        current[i][col] = a;
                    }
                }

                mn = min(mn, presans);
                if (mn == presans) ANS = current;

                debug("in col", col, presans, mn);
                cerr << "INSIDE ANS\n";
                display(ANS);
                cerr << "\n";
                debug(count(s, ANS));

                cerr << "GRID\n";
                display(grid);
                debug(count(s, grid));

                cerr << "****************\n";
            }
        }
    }
}
void getans(vector<string> &s, vector<string> &use, vector<string> &ANS, ll &mn) {
    ll n = sz(s);
    ll m = sz(s[0]);

    rep(ii , sz(use)) {
        vector<string> grid(n, string(m , '?'));
        vector<string> grid5(n, string(m , '?'));
        string t = use[ii];
        grid[0][0] = t[0];
        grid[0][1] = t[1];
        grid[1][0] = t[2];
        grid[1][1] = t[3];

        rep(i, n) {
            rep(j , m) {
                if (i >= 2) grid[i][j] = grid[i - 2][j];
                else {
                    if (j >= 2) {
                        grid[i][j] = grid[i][j - 2];
                    }
                }
            }
        }


        grid5[0][0] = t[0];
        grid5[0][1] = t[1];
        grid5[1][0] = t[2];
        grid5[1][1] = t[3];
        rep(i, n) {
            rep(j , m) {
                if (i >= 2) grid5[i][j] = grid5[i - 2][j];
                else {
                    if (j >= 2) {
                        grid5[i][j] = grid5[i][j - 2];
                    }
                }
            }
        }

        vector<string> dummy;
        string d1 = "TGACA";
        string d2 = "ACTGT";
        string d3 = "TGACA";
        string d4 = "ACTGT";
        dummy.pb(d1);
        dummy.pb(d2);
        dummy.pb(d3);
        dummy.pb(d4);


        if (check(grid)) {
            if (grid == dummy) {
                cout << "gotcha\n";
                cerr << "####################\ngotcha\n";
                debug(count(s, dummy));
            }
            ll cnt = count(s, grid);
            mn = min(mn , cnt);
            if (cnt == mn) {
                ANS = grid;
                debug("change in getans", count(s, ANS));
                display(ANS);
            }
        }

        // vector<string> grid1 = grid;
        // vector<string> grid2 = grid;
        // vector<string> grid3 = grid;
        // vector<string> grid4 = grid;

        // for (int i = 1 ; i < n ; i += 2) {
        //     swap(grid1[i][m - 1] , grid1[i - 1][m - 1]);
        // }
        // if (n & 1) grid1[n - 1][m - 1] = grid[n - 2][m - 1];

        // for (int i = 1 ; i < n ; i += 2) {
        //     swap(grid2[i][0] , grid2[i - 1][0]);
        // }
        // if (n & 1) grid2[n - 1][0] = grid[n - 2][0];

        // for (int i = 1 ; i < m ; i++) {
        //     swap(grid3[n - 1][i], grid3[n - 1][i - 1]);
        // }
        // if (m & 1) grid3[n - 1][m - 1] = grid[n - 1][m - 2];


        // for (int i = 1 ; i < m ; i++) {
        //     swap(grid3[0][i], grid3[0][i - 1]);
        // }
        // if (m & 1) grid3[0][m - 1] = grid[0][m - 2];


        // if (check(grid1)) {
        //     ll cnt = count(s, grid1);
        //     if (mn < cnt) ANS = grid1;
        //     mn = min(mn , cnt);
        // }

        // if (check(grid2)) {
        //     ll cnt = count(s, grid2);
        //     if (mn < cnt) ANS = grid2;
        //     mn = min(mn , cnt);
        // }

        // if (check(grid3)) {
        //     ll cnt = count(s, grid3);
        //     if (mn < cnt) ANS = grid3;
        //     mn = min(mn , cnt);
        // }

        // if (check(grid4)) {
        //     ll cnt = count(s, grid4);
        //     if (mn < cnt) ANS = grid4;
        //     mn = min(mn , cnt);
        // }
        dothis(s, use, ANS, mn, grid);
        // dothis(s, use, ANS, mn, grid1);
        // dothis(s, use, ANS, mn, grid2);
        // dothis(s, use, ANS, mn, grid3);
        // dothis(s, use, ANS, mn, grid4);
    }
}
vector<string> transpose(vector<string> s) {
    ll n = sz(s);
    ll m = sz(s[0]);

    vector<string> ans(m , string(n , '?'));
    rep(i , n) {
        rep(j , m) ans[j][i] = s[i][j];
    }

    return ans;
}
void solve() {
    ll n, m;
    cin >> n >> m;

    vector<string> s(n);
    rep(i , n) cin >> s[i];

    vector<string> use;
    string B = A;
    do {
        use.pb(B);
    } while (next_permutation(all(B)));


    brute(n, m, s);
    vector<string> ANS;
    ll mn = inf;
    getans(s, use, ANS, mn);
    debug(mn , ANS);

    vector<string> sT = transpose(s);
    brute(m, n, sT);
    ll mnT = inf;
    vector<string> ANST;
    getans(sT, use, ANST, mnT);
    debug(mnT , ANST);
    vector<string> ANSTT = transpose(ANST);

    // vector<string> dummy;
    // string d1 = "GTGTC";
    // string d2 = "CACAG";
    // string d3 = "GTGTC";
    // dummy.pb(d1);
    // dummy.pb(d2);
    // dummy.pb(d3);
    // cerr << count(s, dummy);

    cerr << "s\n";
    display(s);

    cerr << "work : " << mn << ":\n";
    display(ANS);
    debug(count(s, ANS));

    cerr << "work : " << mnT << ": \n";
    display(ANSTT);
    debug(count(s, ANSTT));


    cout << "MOVES: " << min(mn, mnT) << "\n";
    if (mnT < mn) ANS = ANSTT;
    mn = min(mn, mnT);

    cerr << "s\n";
    display(s);

    cerr << "ANS\n";
    display(ANS);

    debug(mn);

    cout << "COUNT " << count(s, ANS) << "\n";
    rep(i , n) {
        rep(j , m) cout << ANS[i][j];
        cout << "\n";
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
