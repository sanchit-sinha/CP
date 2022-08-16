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


void solve() {
    ll m;
    cin >> m;

    vvll a(2, vll(m, 0));
    rep(i, 2) {
        rep(j, m) cin >> a[i][j];
    }


    vvll evenadd(2, vll(m, 0)), oddadd(2, vll(m, 0));
    ll index = 0;
    FOR(j, 0, m - 1) oddadd[0][j] = index++;
    FORR(j, m - 1, 0) oddadd[1][j] = index++;

    index = 0;
    FOR(j, 0, m - 1) evenadd[1][j] = index++;
    FORR(j, m - 1, 0) evenadd[0][j] = index++;

    multiset<ll> even, odd;
    rep(i, 2) {
        rep(j, m) {
            even.insert(a[i][j] - evenadd[i][j]);
            odd.insert(a[i][j] - oddadd[i][j]);
        }
    }

    // drurdru..
    ll timer = 0;
    ll ans = inf;
    rep(j, m) {
        if (j == 0) {
            if (timer >= a[1][j]) timer++;
            else  timer = a[1][j] + 1;
        }
        else {
            if (j & 1) {
                if (timer >= a[1][j]) timer++;
                else timer = a[1][j] + 1;

                if (timer >= a[0][j])  timer++;
                else timer = a[0][j] + 1;
            }
            else {
                if (timer >= a[0][j])  timer++;
                else timer = a[0][j] + 1;

                if (timer >= a[1][j]) timer++;
                else timer = a[1][j] + 1;
            }
        }
        debug(j, a[0][j], a[1][j], timer);

        auto it = even.find(a[0][j] - evenadd[0][j]);
        if (it != even.end()) even.erase(it);

        it = even.find(a[1][j] - evenadd[1][j]);
        if (it != even.end()) even.erase(it);

        it = odd.find(a[0][j] - oddadd[0][j]);
        if (it != odd.end()) odd.erase(it);

        it = odd.find(a[1][j] - oddadd[1][j]);
        if (it != odd.end()) odd.erase(it);

        if (j == m - 1) continue;

        ll rem = (m - j - 1) * 2;
        ll mx = 0;
        if (j % 2 == 0) {
            mx = *even.rbegin();
        }
        else {
            mx = *odd.rbegin();
        }

        ll dif = (mx + 1 + j - timer);
        if (dif <= 0) ans = min(ans, timer + rem);
        else ans = min(ans, timer + rem + dif);
        debug(j, ans, timer);
    }
    debug(timer);
    ans = min(ans, timer);

    // rrrr .. d . llll 
    timer = 0;
    FOR(j, 1, m - 1) {
        if (a[0][j] >= timer)timer = a[0][j] + 1;
        else timer++;
    }
    FORR(j, m - 1, 0) {
        if (a[1][j] >= timer) timer = a[1][j] + 1;
        else timer++;
    }
    debug(timer);
    ans = min(ans, timer);

    // d rrrrr .. u .. l ll l l
    timer = 0;
    FOR(j, 0, m - 1) {
        if (a[1][j] >= timer) timer = a[1][j] + 1;
        else timer++;
    }
    FORR(j, m - 1, 1) {
        if (a[0][j] >= timer) timer = a[0][j] + 1;
        else  timer++;
    }
    debug(timer);
    ans = min(ans, timer);

    cout << ans << "\n";
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

