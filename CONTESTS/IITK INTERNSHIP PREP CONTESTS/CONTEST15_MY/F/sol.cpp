#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// above one shoud be above using namespace std
using namespace std;

template<typename T>
#define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
// o_set(ll) name ; -- defining ordered set
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : counting from zero it returns the k-th largest or smallest element in the set - returns iterator

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

inline ll max(ll a, ll b) {return ((a > b) ? a : b);}
inline ll min(ll a, ll b) {return ((a > b) ? b : a);}
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

void solve() {
    ll n, k;
    cin >> k >> n;

    vll p(n);
    rep(i, n) cin >> p[i];

    ll q;
    cin >> q;

    vpll v;
    rep(i, n) v.pb(mp(-p[i], i));
    sort(all(v));

    vll ans(n + 1, -1);

    o_set(pll) st1;
    rep(i , n) {
        ll x = -v[i].f;
        ll index = v[i].s;

        while (i < n && v[i].f == -x) {
            st1.insert({v[i].s, x});

            i++;
        }
        ll len = sz(st1);
        if (len >= k)  {
            auto it = st1.find_by_order(k - 1);
            ans[len] =  (it->first);
        }
        i--;

    }

    rep(i , n) v[i].f = abs(v[i].f);
    sort(all(v));
    while (q--) {
        ll tm;
        cin >> tm;

        pll p = mp(tm, -inf);
        auto it = lb(all(v), p);
        if (it != v.begin()) {
            ll big = v.end() - it;
            cout << ans[big] + 1 << "\n";
        }
        else cout << ans[n] + 1 << "\n";
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
