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
#define pll                 pair<ll, ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (ll)((c).size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin(); a != x.end(); a++)
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
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e3 + 11;
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

pll ed[N];
void solve() {
    ll n, d;
    cin >> n >> d;

    rep(i, d) {
        ll x, y;
        cin >> x >> y;

        ed[i + 1] = {x, y};
    }


    FOR(i, 1, d) {
        FOR(j, 1, n) make_set(j);
        FOR(j, 1, i) union_set(ed[j].f, ed[j].s);

        set<pll> s;
        FOR(j, 1, n) {
            ll p = find_set(j);
            s.insert({sz[p], p});
        }

        ll effort = 0ll;
        for (auto &p : s) {
            effort += (p.f - 1);
        }


        ll rem = i - effort;
        debug(s);
        debug(rem, effort);

        pll pmx = *s.rbegin();
        s.erase(s.find(pmx));
        while (sz(s)) {
            if (rem == 0) break;
            auto p = *s.rbegin();
            union_set(p.s, pmx.s);

            s.erase(s.find(p));
            rem--;
        }

        ll ans = 0ll;
        FOR(j, 1, n) {
            ans = max(ans, sz[j] - 1);
        }

        cout << ans << "\n";

    }
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
