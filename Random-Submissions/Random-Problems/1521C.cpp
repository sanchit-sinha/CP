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

ll ask(ll op, ll i, ll j, ll x) {
    cout << "? " << op << " " << i << " " << j << " " << x << endl;

    // vll v = { 2,5,3,4,1 };
    // if (op == 1) return max(min(x, v[i - 1]), min(x + 1, v[j - 1]));
    // else return min(max(x, v[i - 1]), max(x + 1, v[j - 1]));

    ll ans;
    cin >> ans;
    return ans;
}
void solve() {
    ll n;
    cin >> n;

    auto one = [&](ll x, ll y) {
        ll res = ask(2, x, y, 1);
        if (res <= 2) {
            if (ask(1, x, y, 1) == 1) return y;
            if (ask(1, y, x, 1) == 1) return x;
        }
        return -1LL;
    };

    ll oindex = one(1, n);
    for (ll i = 1; i <= n; i += 2) {
        if (i + 1 <= n) {
            ll index = one(i, i + 1);
            if (index != -1) {
                oindex = index;
                break;
            }
        }
    }

    vll ans(n + 1, 0ll);
    ans[oindex] = 1;

    FOR(i, 1, n) {
        if (i == oindex) continue;
        else {
            ans[i] = ask(1, oindex, i, n - 1); // 1 _ ai
        }
    }

    cout << "! ";
    FOR(i, 1, n) cout << ans[i] << " ";
    cout << endl;
}

int main() {
#ifdef ERROR
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
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) { if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex, ll md) { ll ans = 1ll; while (ex > 0) { if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md; } return ans; }

