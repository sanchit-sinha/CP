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
const ll mod = 998244353;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 2e5 + 11;
ll tr[4 * N], a[N];
ll pull(ll l, ll r) {
    ll p = (l + r); //operation
    return p;
}
void build(ll node, ll l, ll r) {
    if (l == r) tr[node] = a[l];
    else {
        ll mid = l + (r - l) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        tr[node] = pull(tr[node * 2], tr[node * 2 + 1]);
    }
}
void update(ll node, ll l, ll r, ll index, ll val) {
    if (index > r || index < l) return ;
    if (l == r) a[index] = val , tr[node] = val; //update operation
    else {
        ll mid = l + (r - l) / 2;
        update(node * 2, l, mid, index, val);
        update(node * 2 + 1, mid + 1, r, index, val);

        tr[node] = pull(tr[node * 2], tr[node * 2 + 1]);
    }
}
ll query(ll node, ll l, ll r, ll start, ll end) {
    if (end < l || start > r) return 0ll; //operation (inf , -inf , 0 ...)
    else if (start <= l && end >= r) return tr[node];
    else {
        ll mid = l + (r - l) / 2;
        ll p1 = query(2 * node, l, mid, start, end);
        ll p2 = query(2 * node + 1, mid + 1, r, start, end);

        return pull(p1, p2); //operation
    }
}
//build(1,0,n-1) .... query(1,0,n-1,l,r) .... update(1,0,n-1,x,a[x])

void solve() {
    ll n, m;
    cin >> n >> m;

    vll s(n + 3, 0ll);
    vll t(max(m, n) + 3, 0ll);

    FOR(i, 1, n) cin >> s[i];
    FOR(i, 1, m) cin >> t[i];

    debug(s);
    debug(t);

    ll mx = 2e5 + 1;
    FOR(i, 1, n) a[s[i]] += 1;
    build(1, 0, mx);

    vvll dp(n + 3, vll(2 , 0ll));
    // dp[i][0] : number of strings s == t such that
    // dp[i][1] : number of strings s < t

    auto pres = [&](ll index, ll x) { // AMBIGUITY
        // ll cnt = 0ll;
        // FOR(i, 1, n) cnt += (s[i] == x);
        // FOR(i, 1, index - 1) cnt -= (t[i] == x);
        // return (cnt > 0);

        ll cnt = query(1, 0, mx - 1, x, x);
        return (cnt > 0);
    };

    auto less = [&](ll index, ll x) {
        // ll cnt = 0ll;
        // FOR(i, 1, n) cnt += (s[i] < x);
        // FOR(i, 1, index - 1) cnt -= (t[i] < x);
        // return max(0ll, cnt);


        ll cnt = query(1, 0, mx - 1, 0, x - 1);
        return max(0ll, cnt);
    };

    FOR(i, 1, n) {
        if (i == 1) {
            if (pres(1, t[i])) {
                dp[i + 1][0] = 1;
            }

            ll num = less(1, t[i]);
            dp[i + 1][1] = num;

            update(1, 0, mx - 1, t[i], a[t[i]] - 1);
            continue;
        }

        if (pres(i, t[i])) {
            dp[i + 1][0] += dp[i][0];
            dp[i][0] %= mod;
        }

        dp[i + 1][1] += (dp[i][1]) * (n - i + 1);
        dp[i + 1][1] %= mod;

        ll num = less(i, t[i]);
        dp[i + 1][1] += dp[i][0] * num;
        dp[i + 1][1] %= mod;

        //
        update(1, 0, mx - 1, t[i], a[t[i]] - 1);
    }

    debug(dp);
    ll ans = dp[n + 1][1] % mod; ans %= mod;
    ans += (dp[n + 1][0]) % mod; ans  %= mod;
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
