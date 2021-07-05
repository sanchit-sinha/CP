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
string getMax(ll x) {
    ll len = x / 2;
    string ans;
    rep(j , len) ans.pb('1');

    if (x % 2 == 1) {
        ans.pop_back();
        ans.pb('7');
    }
    return ans;
}

// 0: 6
// 1: 2
// 2: 5
// 3: 5
// 4: 4
// 5: 5
// 6: 6
// 7: 3
// 8: 7
// 9: 6
map<char, char> m;
int ans[15] = { -1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88};

string getMin(ll x) {
    string ans;
    ll digs = x / 7;
    rep(i , digs) ans.pb('8');

    ll rem = x % 7;
    if (rem == 0) return ans;
    if (rem > 1) {
        char c = (char)(rem + '0');
        if (sz(ans) == 0) {

            if (rem == 6) ans.pb('6');
            else ans.pb(m[c]);
            return ans;
        }
        ans.pb(m[c]);
        sort(all(ans));
        return ans;
    }

    if (sz(ans)) ans[0] = '7';
    ans.pb(m['2']);
    sort(all(ans));

    return ans;
}

string comp(string s, string t) {
    if (stoll(s) < stoll(t)) return s;
    return t;
}
ll ct = 0;
void bruteMN(ll rem, string cur, string &ans, ll n) {
    ct++;
    if (rem < 0) return;
    if (rem == 0) {
        if (cur[0] == '0') return;
        if (sz(ans) == 0) ans = cur;
        ans = comp(ans, cur);
        return;
    }

    trav(it , m) {
        ll x = (it->f) - '0';
        rem -= (x);
        cur.pb(it->s);

        bruteMN(rem, cur, ans, n);

        rem += (x);
        cur.pop_back();
    }
    return;
}
const ll N = 2e5 + 11;
map<ll, string> dp;
#define PREPROCESS
void preprocess() {
    dp[2] = "1";
    dp[3] = "7";
    dp[4] = "4";
    dp[5] = "2";
    dp[6] = "14";
    dp[7] = "8";
    dp[8] = "10";
    dp[9] = "18";
    dp[10] = "22";
    dp[11] = "20";
    dp[12] = "28";
    dp[13] = "80";
    dp[14] = "88";
    dp[15] = "108";
    dp[16] = "188";
    dp[17] = "200";
    dp[18] = "208";
    dp[19] = "288";
    dp[20] = "808";
//     rep(i, N) dp.pb("");
//     FOR(i, 2, 20) {
//         string ans = "", cur = "";
//         bruteMN(i, cur, ans, i);
//         dp[i] = ans;
//     }

    FOR(i, 21, N - 1) {
        ll dij = (i + 6) / 6;
        dp[i] = dp[i - 1];
        for (ll j = 0; j + sz(dp[i - 1]) < dij; j++) {
            dp[i] += "8";
        }
    }
}

void solve() {
    // len : val
    m['2'] = '1';
    m['3'] = '7';
    m['4'] = '4';
    m['5'] = '2';
    m['6'] = '0';
    m['7'] = '8';

    ll n;
    cin >> n;

    // string a = getMin(n);
    string b = "";
    b = getMax(n);

    ll x = 1;
    // while (x <= n) {
    //     ct = 0;
    //     string ans = "", cur = "";
    //     bruteMN(x, cur, ans, x);
    //     cerr << "dp[" << x << "]" << " = " << ans << "\n";
    //     x++;
    // }

    // cout << n << " : " << a << " " << b << "\n";
    // cout << n << " " << a << ": " << ans[n] << "\n";
    cout << dp[n] << " " << b << "\n";
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
