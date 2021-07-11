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
ll n, m, k;
vll v[N];
ll sz[N];
ll parent[N];
void make_set(ll node) {
    parent[node] = node;
    sz[node] = 1;
}
ll find_set(ll a) {
    if (a == parent[a]) return a;
    return parent[a] = find_set(parent[a]);
}
void union_set(ll a , ll b) {
    ll p1 = find_set(a);
    ll p2 = find_set(b);
    if (p1 != p2) {
        if (sz[p2] > sz[p1]) swap(p1 , p2);
        parent[p2] = p1;
        sz[p1] += sz[p2];
    }
}

ll special_nodes[N];
void solve() {
    cin >> n >> m >> k;

    FOR(i, 1, n) make_set(i);
    rep(i, m) {
        ll x, y;
        cin >> x >> y;

        v[x].pb(y);
        v[y].pb(x);

        union_set(x, y);
    }

    set<ll> p;
    rep(i, n) p.insert(find_set(i + 1));
    debug("parent", p);

    FOR(i, 1, k) cin >> special_nodes[i];

    set<ll> parent_with_special_node;
    set<ll> parent_without_special_node = p;
    debug(parent_without_special_node);

    FOR(i, 1, k) {
        ll x = special_nodes[i];
        ll prnt = find_set(x);

        parent_with_special_node.insert(prnt);

        auto it = parent_without_special_node.find(prnt);
        if (it != parent_without_special_node.end()) parent_without_special_node.erase(it);
    }

    set<pll> without, with;
    for (auto x : parent_without_special_node) without.insert({sz[x], x});
    for (auto x : parent_with_special_node) with.insert({sz[x], x});

    debug(with);
    debug(without);

    vll a;
    ll ppp = -1;
    if (sz(with)) {
        pll p = *with.rbegin();
        a.pb(p.f);
        ppp = p.s;
    }

    assert(ppp != -1);
    for (auto x : without) {
        a.pb(x.f);
        union_set(ppp, x.s);
    }
    sort(all(a));

    ll len = sz(a);
    vll sfx(len , 0);
    FORR(i, len - 1, 0) {
        (i == len - 1) ? (sfx[i] = a[i]) : (sfx[i] = sfx[i + 1] + a[i]);
    }

    ll cost = 0ll;
    debug(a);
    debug(sfx);
    rep(i, len - 1) {
        debug(i, a[i], sfx[i + 1]);
        cost += (a[i] * sfx[i + 1]);
    }

    ll add = 0ll;
    p.clear();
    rep(i, n) p.insert(find_set(i + 1));

    for (auto x : p) {
        ll len_comp = sz[x];
        add += (len_comp * (len_comp - 1)) / 2;
    }

    add -= m;


    cout << add << " " << cost << "\n";
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
