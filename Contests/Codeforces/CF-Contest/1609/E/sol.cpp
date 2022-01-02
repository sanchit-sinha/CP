#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long
#define o_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

#define f                   first
#define s                   second
#define pb                  push_back
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

// claim :: either remove a or b or c
void solve() {
    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    o_set aindex, bindex, cindex;
    rep(i, n) {
        if (s[i] == 'a') aindex.insert(i);
        else if (s[i] == 'b') bindex.insert(i);
        else cindex.insert(i);
    }

    debug(aindex);
    debug(bindex);
    debug(cindex);

    auto getAns = [&]() {
        ll ans = inf;

        if (sz(aindex) == 0) return 0ll;
        if (sz(bindex) == 0) return 0ll;
        if (sz(cindex) == 0) return 0ll;

        // remove only a
        ll largets_c = *cindex.rbegin();
        auto itb = bindex.ub(largets_c);
        if (itb != bindex.begin()) {
            itb--;

            ll b_jst_smaller_than_c = *itb;
            ll num_a_before_this_b = aindex.order_of_key(b_jst_smaller_than_c);
            ans = min(ans, num_a_before_this_b);
            debug(num_a_before_this_b);
        }

        // remove only c
        ll smallest_a = *aindex.begin();
        auto itb2 = bindex.lb(smallest_a);
        if (itb2 != bindex.end()) {
            ll b_jst_greater_than_a = *itb2;

            ll num_c_after_this_b = sz(cindex) - cindex.order_of_key(b_jst_greater_than_a);
            ans = min(ans, num_c_after_this_b);
            debug(num_c_after_this_b);
        }

        // remove only b
        ll b_greater_than_largest_c = sz(bindex) - bindex.order_of_key(largets_c);
        ll b_less_than_smallest_a = bindex.order_of_key(smallest_a);
        ll b_in_betwee = sz(bindex) - b_greater_than_largest_c - b_less_than_smallest_a;
        b_in_betwee = max(0ll, b_in_betwee);
        debug(b_in_betwee);

        ans = min(ans, b_in_betwee);
        ans = max(ans, 0ll);
        if (ans == inf) ans = 0ll;

        return ans;
    };


    auto erase = [&](ll index) {
        if (s[index] == 'a') aindex.erase(aindex.find(index));
        if (s[index] == 'b') bindex.erase(bindex.find(index));
        if (s[index] == 'c') cindex.erase(cindex.find(index));

        return;
    };

    auto add = [&](ll index) {
        if (s[index] == 'a') aindex.insert(index);
        else if (s[index] == 'b') bindex.insert(index);
        else cindex.insert(index);

        return;
    };

    while (q--) {
        ll index; char newc;
        cin >> index >> newc;
        index--;

        erase(index);
        s[index] = newc;
        add(index);

        ll ans = getAns();
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
