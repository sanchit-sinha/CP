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
#define get(x,c)            get<x>((c))
#define trav(a,x)           for(auto a = (x).begin() ; a != (x).end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

string to_string(string s) {return '"' + s + '"';} string to_string(const char* s) {return to_string((string) s);} string to_string(bool b) {return (b ? "true" : "false");} template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";} template <typename A>string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", ";} first = false; res += to_string(x);} res += "}"; return res;} void debug_out() { cerr << "\n"; } template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n"; debug_out(T...);}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
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
bool vis[N];
ll dp[N][2][2];
void dfs(ll node, ll pr) {
    vis[node] = 1;
    for (auto child : v[node]) {
        if (child != pr) {
            dfs(child, node);
            // dp[node][0] += dp[child][1];
            // dp[node][1] += min(dp[child][0], dp[child][1]);

            // ch pr
            dp[node][0][0] += dp[child][1][0];
            dp[node][0][1] += min(dp[child][0][0], dp[child][1][0]);

            dp[node][1][0] += min(dp[child][0][1], dp[child][1][1]);
            dp[node][1][1] += min(dp[child][0][1], dp[child][1][1]);
        }
    }

    dp[node][1][0] += 1;
    dp[node][1][1] += 1;
}
void solve() {
    cin >> n;
    ll m;
    cin >> m;
    rep(i , m) {
        ll x , y;
        cin >> x >> y;

        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1 , 0);

    FOR(i , 1 , n) {
        rep(j , 2) {
            rep(k , 2) {
                cout << i << " = " << j << " : " << k << " " << dp[i][j][k] << "\n";
            }
        }
    }

    ll ans = inf;
    ll one = 1ll, zero = 0ll;
    for (auto child : v[1]) {
        one += min(dp[child][1][1], dp[child][0][1]);
        zero += dp[child][1][0];
    }

    debug(one, zero);

    ans = min({ans , one, zero});
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);

    ll NTC = 1;
    // cin>>NTC;

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
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
