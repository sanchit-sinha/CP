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

void solve() {
    // clear
    ll n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;

    ll a = 0ll;
    rep(i, n) a += (s[i] == 'a');

    if (a == 0) {
        rep(i, x - 1) cout << 'b';
        cout << "\n";
        return;
    }
    if (a == n) {
        cout << s << "\n";
        cout << "\n";
        return;
    }

    vll mul, sfx;
    auto trim = [&](char c) {
        string t ;
        ll n = sz(s);

        rep(i, n) {
            if (s[i] != '*') t.pb(s[i]), mul.pb(1);
            else {
                ll cnt = 0ll;
                while (i < n && s[i] == '*') i++, cnt++;
                i--;

                mul.pb(cnt * k + 1);
                t.pb('*');
            }
        }

        return t;
    };
    string t = trim('*');

    ll len = sz(t);
    sfx.assign(len + 3, 1);

    // recursive lambda
    function <string(ll, ll)> calc = [&](ll index, ll x) {
        string ans;
        if (index >= len) return ans;

        if (x <= 1) {
            if (t[index] == 'a') ans.pb('a');
            return (ans + calc(index + 1, x));
        }

        if (t[index] == 'a') {
            ans.pb('a');
            return (ans + calc(index + 1, x));
        }

        if (x < sfx[index + 1]) return calc(index + 1, x);

        // (x <= sfx[index]) :: take all
        if (x == sfx[index + 1]) {
            FOR(i, index + 1, len - 1) {
                if (t[i] == 'a') {
                    ans.pb('a');
                }
                else {
                    rep(j, mul[i] - 1) ans.pb('b');
                }
            }
            cerr << "no b : " << index << " : "  << ans << "\n";

            return ans;
        }

        // 1b atleast and x > sfx[index + 1]
        x -= sfx[index + 1];
        FOR(i, 1, mul[index] - 1) {
            if (x <= sfx[index + 1]) {
                rep(j, i) ans.pb('b');
                return (ans + calc(index + 1, x));
            }
            else x -= sfx[index + 1];
        }

        return ans;
    };

    bool ok = 0;
    ll index = 0;
    FORR(i, len - 1, 0) {
        if (sfx[i + 1] > x / mul[i]) {
            sfx[i] = -1;
            index = i;
            break;
        }

        if (t[i] == '*') sfx[i] = sfx[i + 1] * mul[i];
        else sfx[i] = sfx[i + 1];
    }

    debug(index);
    debug(t);
    debug(mul);
    debug(sfx);

    string ans;
    rep(i, index) {
        if (t[i] == 'a') ans.pb('a');
    }

    debug(ans);
    cout << ans + calc(index, x) << "\n";
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