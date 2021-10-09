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

const ll N = 3e5 + 11;
bool alleq(string &s, char c) {
    rep(i, sz(s)) if (s[i] != c) return 0;
    return 1;
}

const ll mX = N;
bool prime[mX + 11];
void sieve(string &s, char c) {
    ll n = sz(s);
    rep(i, n + 2) prime[i] = 1;

    for (ll p = 2 ; p <= n ; p++) {
        if (prime[p] == true) {
            for (ll i = p; i <= n; i += p) {
                ll index = i - 1;
                if (index >= 0 && index < n && s[index] != c) {
                    prime[p] = false;
                    break;
                }
            }
        }
    }
}
void solve() {
    ll n;
    cin >> n;

    // clear
    rep(i, n + 1)prime[i] = 0;

    char c;
    cin >> c;

    string s;
    cin >> s;


    if (alleq(s, c)) {
        cout << 0 << "\n";
    }
    else {
        if (s[n - 1] == c) {
            cout << 1 << "\n";
            cout << n << "\n";
        }
        else {
            sieve(s, c);
            ll ans = -1;
            for (int i = 2; i <= n; i++) if (prime[i]) ans = i;

            if (ans != -1) {
                rep(i, n) {
                    if ((i + 1) % ans) {
                        s[i] = c;
                    }
                }

                if (alleq(s, c)) {
                    cout << 1 << "\n";
                    cout << ans << "\n";
                }
                else {
                    cout << 2 << "\n";
                    cout << n << " " << n - 1 << "\n";
                }
            }
            else {
                cout << 2 << "\n";
                cout << n << " " << n - 1 << "\n";
            }
        }
    }
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
