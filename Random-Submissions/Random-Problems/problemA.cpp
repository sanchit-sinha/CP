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
bool DEBUGG = 1;
#include "debug.cpp"
#else
bool DEBUGG = 0;
#define debug(...) 42
#define cerr if(false) cerr
#endif

inline ll gcd(ll a, ll b) { if (b == 0) return a; a %= b; return gcd(b, a); }
inline ll max(ll a, ll b) { return ((a > b) ? a : b); }
inline ll min(ll a, ll b) { return ((a > b) ? b : a); }
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 4e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

#define opll tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define oll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

/*  order_of_key(k) : number of elements strictly lesser than k
    find_by_order(k) : counting from zero it returns the k-th largest or smallest element in the set - returns iterator  */

pll ask(set<ll>& s) {
    cout << "? ";
    for (auto& x : s) cout << x << " ";
    cout << endl;

    debug(s);


    
    // vll v = { 1,2,3,4,5,8,9,0 };
    // ll mm = 6;
    // opll temp;
    // for (auto& x : s) temp.insert({ v[x - 1],x });

    // auto pp = *temp.find_by_order(mm - 1);
    // debug(temp);
    // debug(pp.s, pp.f);
    // return { pp.s, pp.f };

    ll pos, val;
    cin >> pos >> val;

    return { pos, val };
}

void pr(ll ans) {
    cout << "! " << ans << endl;
}
void solve() {
    ll n, k;
    cin >> n >> k;

    set<ll> s;
    FOR(i, 1, k) s.insert(i);
    auto cur = ask(s);

    ll last = n;
    bool less = 0; ll ansl = 0ll;
    bool more = 0; ll ansm = 0ll;
    FOR(i, 1, k) {
        s.erase(s.find(i));
        s.insert(n);

        pll newcur = ask(s);
        if (newcur.s > cur.s) more = 1, ansm++;
        if (newcur.s < cur.s) less = 1, ansl++;

        s.insert(i);
        s.erase(s.find(n));
    }

    debug(more, ansm);
    debug(less, ansl);

    if (more) pr(ansm);
    else pr(k - ansl + 1);
}

int main() {
#ifdef ERROR
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

ll power(ll x, ll y) { if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex, ll md) { ll ans = 1ll; while (ex > 0) { if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md; } return ans; }

