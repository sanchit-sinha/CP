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
#define sz(c)               (ll)((c).size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(ll i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(ll i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(ll i = (b); i >= (a); i--)

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

bool get_ans(ll n, ll m, ll k) {
    if (n % 2 == 0 && m % 2 == 0) {
        if (m == 0) return 0;

        if (k % 2 == 0) return 1;
        return 0;
    }

    return 0;
}

bool use(vvll &ans, ll i, ll j, ll x) {
    bool ok = 1;

    if (i > 0 && ans[i - 1][j] == x) ok = 0;
    if (j > 0 && ans[i][j - 1] == x) ok = 0;

    return ok;
}

void add_horz(vvll &ans, ll k) {
    debug("horz", k);
    if (k == 0) return;

    // add horz
    ll n = sz(ans);
    ll m = sz(ans[0]);

    ll store[] = {25, 24, 23, 22};
    rep(j, m) {
        rep(i, n) {
            if (ans[i][j] == 0) {
                rep(l, 4) {
                    if (use(ans, i, j, store[l])) {
                        ans[i][j] = store[l];
                        ans[i][j + 1] = store[l];
                        k--;
                        break;
                    }
                }
            }
            if (!k) break;
        }
        if (!k) break;
    }
}

void add_vertz(vvll &ans) {
    ll n = sz(ans);
    ll m = sz(ans[0]);

    // add vertz
    ll store[] = {21, 20, 19, 18};
    // store[0] = 21, store[1] = 20, store[2] = 19, store[3] = 18;
    rep(i, n) {
        rep(j, m) {
            if (ans[i][j] == 0) {
                rep(k, 4) {
                    if (use(ans, i, j, store[k])) {
                        ans[i][j] = store[k];
                        ans[i + 1][j] = store[k];
                        break;
                    }
                }
            }
        }
    }

}
vvll construct(ll n, ll m, ll k) {
    vvll ans(n, vll(m, 0));
    if (n == 0 || m == 0 || !get_ans(n, m, k)) return ans;

    add_horz(ans, k);
    add_vertz(ans);

    return ans;
}

void disp(vvll &ans) {
    rep(i, sz(ans)) {
        rep(j, sz(ans[i])) {
            char c = (char)(ans[i][j] + 'a');
            cout << c;
        }
        cout << "\n";
    }

    return;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;


    vvll ans(n, vll(m, 0));
    if (k == 0) {
        if (n % 2 == 0) {
            cout << "YES\n";

            add_vertz(ans);
            disp(ans);
        }
        else cout << "NO\n";

        return;
    }

    bool ok = 1;
    if (n % 2 == 0 && m % 2 == 0) {
        ok = get_ans(n, m, k);
        if (ok) {
            ans = construct(n, m, k);
        }
    }
    else {
        if (n & 1) {
            if (k < m / 2) ok = 0;
            else {
                // add top: o, e
                vvll res(1, vll(m, 0));
                rep(j, m) {
                    ll i = 0;
                    if (res[i][j] == 0) {
                        if (use(res, i, j, 1)) res[i][j] = res[i][j + 1] = 1;
                        else if (use(res, i, j, 2)) res[i][j] = res[i][j + 1] = 2;
                    }
                }

                ok = get_ans(n - 1, m, k - (m / 2));
                if (ok) {
                    vvll temp = construct(n - 1, m, k - (m / 2));
                    rep(j, m) ans[0][j] = res[0][j];
                    rep(i, n - 1) {
                        rep(j, m) ans[i + 1][j] = temp[i][j];
                    }
                }
            }
        }
        else if (m & 1) {
            ll tot = (n * m) / 2;
            if (tot - k < n / 2) ok = 0;
            else {
                // add last col , e, o
                vvll res(n, vll(1, 0));
                rep(i, n) {
                    ll j = 0;
                    if (res[i][j] == 0) {
                        if (use(res, i, j, 1)) res[i][j] = res[i + 1][j] = 1;
                        else if (use(res, i, j, 2)) res[i][j] = res[i + 1][j] = 2;
                    }
                }

                ok = get_ans(n, m - 1, k);
                if (ok) {
                    vvll temp = construct(n, m - 1, k);
                    rep(i, n) {
                        rep(j, m - 1) ans[i][j] = temp[i][j];
                        ans[i][m - 1] = res[i][0];
                    }
                }
            }
        }
    }

    if (ok) {
        cout << "YES\n";
        disp(ans);
    }
    else cout << "NO\n";

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