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
#define sz(c)               (ll)((c).size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(ll i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(ll i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(ll i = (b); i >= (a); i--)

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

const ll N = 20;
ll n, m, k;
ll l[N] , r[N], a[N];
set<ll> v[N];

ll ispath(ll to, vector<bool> &vis) {
    rep(i, n) {
        if (vis[i]) {
            if (v[i].find(to) != v[i].end()) return 1;
        }
    }

    return 0;
}
pair<bool, vll> check(vll &index) {
    vll ans;
    ll cur = 0ll;

    vector<bool> vis(n, 0);
    ll node = index[0];
    ans.pb(node);

    vis[node] = 1;
    cur += a[node];

    FOR(i, 1, n - 1) {
        ll to = index[i];
        if (cur == k) {
            return {1, ans};
        }

        if (cur < l[to] || cur > r[to]) {
            return {0, ans};
        }

        if (ispath(to, vis)) {
            node = to;
            ans.pb(node);

            vis[node] = 1;
            cur += a[node];
        }
        else return {0, ans};
    }

    if (cur == k) return {1, ans};
    else return {0, ans};
}
void solve() {
    // clear
    rep(i, n + 1) {
        l[i] = r[i] = a[i] = 0;
        v[i].clear();
    }

    cin >> n >> m >> k;
    rep(i, n) {
        cin >> l[i] >> r[i] >> a[i];
    }

    rep(i, m) {
        ll x, y;
        cin >> x >> y;

        v[x].insert(y);
        v[y].insert(x);
    }

    vll index;
    rep(i, n) index.pb(i);
    set<vll> ans;

    do {
        auto p = check(index);
        if (p.f) {
            debug(index);
            debug(p.s);
            ans.insert(p.s);
        }
    } while (next_permutation(all(index)));


    cout << sz(ans) << "\n";
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
