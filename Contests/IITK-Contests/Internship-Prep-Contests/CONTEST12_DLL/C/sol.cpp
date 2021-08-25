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
string inc(const string &s, int x) {
    string ans;

    ll n = sz(s);
    FOR(i, 0, n - 1) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            int cnew = (s[i] - 'a') + x;
            cnew %= 26;

            char c = (char)(cnew + 'a');
            ans.pb(c);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            int cnew = (s[i] - 'A') + x;
            cnew %= 26;

            char c = (char)(cnew + 'A');
            ans.pb(c);
        }
        else {
            ans.pb(s[i] + 1);
            // assert(0);
        }
    }
    return ans;
}
ll evaluate(const string &s, const string &t) {
    ll n = sz(s);
    ll m = sz(t);

    vvll dp(n + 11, vll(m + 11 , 0));
    // base
    dp[0][0] = 0;
    FOR(i, 0, n) dp[i][0] = i;
    FOR(j, 0, m) dp[0][j] = j;

    FOR(i , 1 , n) {
        FOR(j, 1, m) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                // dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    return dp[n][m];
}
void solve() {
    string source, target;
    cin >> source >> target;

    ll ans = inf;
    rep(i, 26) {
        string source_new = inc(source, i);
        ans = min(ans , evaluate(source_new, target));
    }

    cout << ans << "\n";
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
