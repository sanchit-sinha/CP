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

const ll N = 1e5 + 11;
ll n;
vll v[N];
ll subtreesz[N], subtreesum[N];
ll incorrect[N], correct[N];
ll dp[N][2];

void dfs1(ll node, ll pr) {
    for (auto child : v[node]) {
        if (child != pr) {
            dfs1(child, node);
            subtreesz[node] += subtreesz[child];
            subtreesum[node] += (subtreesum[child]);
        }
    }
}
void dfs2(ll node, ll pr) {
    ll same = 0ll, diff = 0ll;
    for (auto child : v[node]) {
        if (child != pr) {
            dfs2(child, node);
            same += dp[child][0];
            diff += dp[child][1];
        }
    }

    if (incorrect[node] != correct[node]) {
        debug("1", node, same, diff);
        dp[node][0] = min(dp[node][0], same + 1);
        dp[node][0] = min(dp[node][0], diff + 1);

        dp[node][1] = min(dp[node][1], same + 1 + 1);
        dp[node][1] = min(dp[node][1], diff);
    }
    else {
        debug("2", node, same, diff);
        dp[node][0] = min(dp[node][0], same);
        dp[node][0] = min(dp[node][0], diff + 1 + 1);

        dp[node][1] = min(dp[node][1], same + 1);
        dp[node][1] = min(dp[node][1], diff + 1);
    }

}
void solve() {
    cin >> n;
    rep(i , n - 1) {
        ll x , y;
        cin >> x >> y;

        v[x].pb(y);
        v[y].pb(x);
    }

    rep(i , n) cin >> incorrect[i + 1];
    rep(i , n) cin >> correct[i + 1];

    FOR(i , 1 , n) {
        subtreesz[i] = 1;
        subtreesum[i] = (incorrect[i] ^ correct[i]);
    }

    dfs1(1, 0);

    FOR(i , 1 , n) {
        cerr << i << " " << subtreesum[i] << " " << subtreesz[i] << "\n";
    }

    // cout << 1 + (1 ^ 0) << "\n";
    // cout << 1 + !(1 ^ 0) << "\n";

    FOR(i , 1 , n) {
        rep(j, 2) dp[i][j] = inf;
    }

    dfs2(1, 0);

    // FOR(i , 1 , n) {
    //     cerr << i << " : ";
    //     rep(j, 2) cerr << dp[i][j] << " ";
    //     cerr << "\n";
    // }


    cout << dp[1][0] << "\n";
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
