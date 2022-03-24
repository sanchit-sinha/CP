
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

// Case #1: [s, sz(s)]:  "????????????????????" 20
// [t]:  "11010011010011010000"
// [t]:  "10110010110010110000"
// [t]:  "11110010110010110000"
// [t]:  "01101001101001101000"
// [t]:  "11101001101001101000"
// [t]:  "01011001011001011000"
// [t]:  "00110100110100110100"
// [t]:  "11110100110100110100"
// [t]:  "00101100101100101100"
// [t]:  "10110010110010110010"
// [t]:  "11110010110010110010"
// [t]:  "00011010011010011010"
// [t]:  "10011010011010011010"
// [t]:  "10100110100110100110"
// [t]:  "00010110010110010110"
// [t]:  "10010110010110010110"
// [t]:  "01101001101001101001"
// [t]:  "11101001101001101001"
// [t]:  "01011001011001011001"
// [t]:  "01100101100101100101"
// [t]:  "11100101100101100101"
// [t]:  "00001101001101001101"
// [t]:  "01001101001101001101"
// [t]:  "11010011010011010011"
// [t]:  "00001011001011001011"
// [t]:  "11001011001011001011"
// [t]:  "10100110100110100111"
// [t]:  "00010110010110010111"
// [t]:  "10010110010110010111"
// [t]:  "00001101001101001111"
// [t]:  "01001101001101001111"
// [t]:  "00101100101100101111"
// 32 

// Case #1: [s, sz(s)] : "???????????????" 15
// [t] : "011010011010000"
// [t] : "111010011010000"
// [t] : "010110010110000"
// [t] : "001101001101000"
// [t] : "111101001101000"
// [t] : "001011001011000"
// [t] : "000110100110100"
// [t] : "100110100110100"
// [t] : "000101100101100"
// [t] : "100101100101100"
// [t] : "010110010110010"
// [t] : "000011010011010"
// [t] : "010011010011010"
// [t] : "110100110100110"
// [t] : "000010110010110"
// [t] : "110010110010110"
// [t] : "001101001101001"
// [t] : "111101001101001"
// [t] : "001011001011001"
// [t] : "101100101100101"
// [t] : "111100101100101"
// [t] : "101001101001101"
// [t] : "011010011010011"
// [t] : "111010011010011"
// [t] : "011001011001011"
// [t] : "111001011001011"
// [t] : "110100110100111"
// [t] : "000010110010111"
// [t] : "110010110010111"
// [t] : "101001101001111"
// [t] : "000101100101111"
// [t] : "100101100101111"
// 32


vector<string> notp;
set<string> notps;

bool checkdp(string& s) {
    ll n = sz(s);
    vvll dp(n + 1, vll(n + 1, 0));

    FORR(i, n - 1, 0) {
        FOR(j, i, n - 1) {
            if (i == j) {
                dp[i][j] = 1;
            }
            else if (j == i + 1) {
                if (s[i] == s[j]) dp[i][j] = 1;
            }
            else {
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = 1;
                }
            }
        }
    }

    FOR(i, 0, n - 1) {
        FOR(j, i, n - 1) {
            if (j - i + 1 >= 5) {
                if (dp[i][j]) return 0;
            }
        }
    }

    return 1;
}
void brute() {
    ll mx = 5ll;
    string s = "?????";
    rep(i, (1ll << mx)) {
        string t = s;
        rep(j, 5) {
            if ((1ll << j) & i) {
                t[j] = '1';
            }
            else t[j] = '0';
        }

        if (checkdp(t)) {
            notp.pb(t);
            notps.insert(t);
        }
    }
}

#define PREPROCESS
void preprocess() {
    brute();
}

bool check(string& s) {
    ll n = sz(s);
    rep(i, n) {
        if (s[i] == '?') return 0;
    }

    FOR(i, 4, n - 1) {
        string t = s.substr(i - 4, 5);
        auto it = notps.find(t);
        if (it == notps.end()) { // not in not pallindrome 
            return 0;
        }
    }

    return 1;
}
void solve() {
    debug(sz(notp), notp);
    debug(sz(notps), notps);

    ll n;
    cin >> n;

    string s;
    cin >> s;

    if (n < 5) {
        cout << "POSSIBLE\n";
        return;
    }

    FORR(i, n - 1, 4) {
        string t = s.substr(i - 4, 5);
        debug(i, t);
        rep(j, sz(notp)) {
            string poss = notp[j];
            bool ok = 1;
            rep(k, sz(poss)) {
                if (t[k] != '?') {
                    if (t[k] != poss[k]) ok = 0;
                }
            }

            if (ok) { // claim : if found put any of the above 
                t = poss;
                break;
            }
        }
        debug(i, t);
        ll index = 0ll;
        FOR(j, i - 4, i) s[j] = t[index++];
    }

    debug(s);
    if (check(s)) cout << "POSSIBLE\n";
    else cout << "IMPOSSIBLE\n";
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
        cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) { if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex, ll md) { ll ans = 1ll; while (ex > 0) { if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md; } return ans; }

