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
#define sz(c)               (int)(c.size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

string to_string(string s) {return '"' + s + '"';} string to_string(const char* s) {return to_string((string) s);} string to_string(bool b) {return (b ? "true" : "false");} template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";} template <typename A>string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", ";} first = false; res += to_string(x);} res += "}"; return res;} void debug_out() { cerr << "\n"; } template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n"; debug_out(T...);}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
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

// 1 indexed .. p[i] is the length of the longest proper prefix of the substring s[0 … i - 1] which is also a suffix of this substring
vector<ll> LPS(string &s) {
    int n = (int)s.length();
    vector<ll> p(n + 1);
    p[0] = 0; p[1] = 0;
    int j;
    for (int i = 2 ; i <= n ; i++) {
        j = p[i - 1];
        while (j > 0 && s[j] != s[i - 1]) j = p[j]; // p[p[j]] gives second largest prefix of the substring s[0 … i - 1]
        if (s[j] == s[i - 1]) j++;
        p[i] = j;
    }
    return p;
}
void solve() {
    ll n , k;
    cin >> n >> k;

    string s;
    cin >> s;

    s += (s + s);

    debug(s);

    vll lps = LPS(s);
    string before_split = s;
    FOR(i, 0, n + n - 1) {
        ll kmp_len = lps[i + 1];
        if (kmp_len == 0) {
            if (s[0] < s[i]) {
                before_split = s.substr(0, i);
                cerr << " " << s[0] << " : " << s[i] << "\n";
                debug(i , before_split);
                break;
            }
        }
        else {
            if (s[kmp_len] < s[i + 1]) {
                before_split = s.substr(0, i - kmp_len + 1);
                debug(before_split);
                break;
            }
        }
    }

    ll len = sz(before_split);
    ll add = (k + len - 1) / len;

    string new_ans = before_split;
    rep(j, add) new_ans += before_split;
    while (sz(new_ans) != k) new_ans.pop_back();

    cout << new_ans << "\n";
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
