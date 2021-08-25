#include "bits/stdc++.h"
using namespace std;
#define f                   first
#define s                   second
#define pb                  push_back
#define ll                  int
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

const ll inf = 1e9 + 7;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;
const ll N = 1e5 + 11;
vll pr;
#define SIEVE
const ll mX = N;
bool prime[mX + 11];
void sieve() {
    memset(prime, true, sizeof(prime));
    for (ll p = 2 ; p * p <= mX ; p++) {
        if (prime[p] == true) {
            for (ll i = p * p ; i <= mX; i += p) prime[i] = false;
        }
    }
}

#define PREPROCESS
void preprocess() {
    FOR(i, 2, N - 1) if (prime[i]) pr.pb(i);
}


void solve() {
    ll r1, r2;
    ll n;

    cin >> r1 >> r2 >> n;
    string s;
    cin >> s;

    vll dp(n + 1, inf);
    if (s[0] == '*') {
        cout << "No way!\n";
        return;
    }

    dp[0] = 0;
    FOR(i, 0, n - 1) {
        if (s[i] == '#') {
            if (i + 1 < n && s[i + 1] == '#') dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            if (i + 2 < n && s[i + 2] == '#') dp[i + 2] = min(dp[i + 2], dp[i] + 1);

            auto it = ub(all(pr), i + 1);
            ll add = 0;
            if (it != pr.begin()) {
                it--;
                add = it - pr.begin() + 1;
            }

            if (add * r2 >= (i + 1)*r1) {
                if (i + add < n && s[i + add] == '#') {
                    debug(i, add, i + add, dp[i]);
                    dp[i + add] = min(dp[i + add], dp[i] + 1);
                }
            }

        }
    }
    FOR(i , 0, n - 1) cerr << i << " : " << dp[i] << "\n";
    cerr << "\n";


    if (dp[n - 1] == inf) cout << "No way!\n";
    else  cout << dp[n - 1] << "\n";
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

#ifdef SIEVE
    sieve();
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
