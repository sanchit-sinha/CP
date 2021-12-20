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

char replace(char c, char p) {
    string s;
    s.pb(c), s.pb(p);

    char ans = '?';
    if (s == "01") ans = '2';
    else if (s == "12") ans = '3';
    else if (s == "23") ans = '4';
    else if (s == "34") ans = '5';
    else if (s == "45") ans = '6';
    else if (s == "56") ans = '7';
    else if (s == "67") ans = '8';
    else if (s == "78") ans = '9';
    else if (s == "89") ans = '0';
    else if (s == "90") ans = '1';
    else ans = '?';

    return ans;
}
void solve() {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    vector<string> v;
    v.pb("01");
    v.pb("12");
    v.pb("23");
    v.pb("34");
    v.pb("45");
    v.pb("56");
    v.pb("67");
    v.pb("78");
    v.pb("89");
    v.pb("90");

    while (true) {
        bool found = 0;
        rep(j, sz(v)) {
            n = sz(s);
            vll index;
            FOR(i, 1, n - 1) {
                if (s[i - 1] == v[j][0] && s[i] == v[j][1]) {
                    char c = replace(s[i - 1], s[i]);
                    if (c != '?') {
                        found = 1;
                        index.pb(i - 1);
                    }
                }
            }

            if (sz(index)) {
                debug(index);
                ll len = sz(index);
                char c = replace(v[j][0], v[j][1]);

                string temp;
                ll l = 0;
                rep(k, len) {
                    ll r = index[k];
                    FOR(i, l, r - 1) temp.pb(s[i]);
                    temp.pb(c);
                    l = index[k] + 2;
                }

                ll r = n;
                FOR(i, l, r - 1) temp.pb(s[i]);

                s = temp;
            }
        }

        if (!found) {
            cout << s << "\n";
            return;
        }
    }

    cout << s << "\n";
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
        cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
