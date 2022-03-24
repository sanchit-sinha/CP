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
    ll n, C;
    cin >> n >> C;

    unordered_map<ll, ll> coin, id;
    rep(i, n) {
        ll c, d, h;
        cin >> c >> d >> h;
        coin[c] = max(coin[c], h * d);
    }

    vll dp(C + 3, 0ll); // max hd from coin i
    for (auto& x : coin) {
        ll hd = x.s;
        for (ll j = x.f; j <= C; j += x.f) {
            dp[j] = max(dp[j], (j / x.f) * hd);
        }
    }

    map<ll, ll> minC; // min coin for max hd
    FOR(i, 0, C) {
        if (dp[i]) {
            if (minC.count(dp[i])) minC[dp[i]] = min(minC[dp[i]], i);
            else minC[dp[i]] = i;
        }
    }

    ll index = 0ll;
    vll sfx;
    for (auto& x : minC) {
        sfx.pb(x.s);
        id[x.f] = index++;
    }

    ll len = sz(sfx);
    FORR(i, len - 2, 0) { // sfx mn 
        sfx[i] = min(sfx[i + 1], sfx[i]);
    }

    debug(minC);
    debug(id);
    debug(sfx);

    ll m;
    cin >> m;
    rep(i, m) {
        ll d, h;
        cin >> d >> h;

        ll mx = d * h;
        ll ans = -1;

        auto it = minC.ub(mx);
        if (it == minC.end()) {
            ans = -1;
        }
        else {
            ll x = it->f;
            ll index = id[x];
            ans = sfx[index];
        }
        // FOR(j, 0, C) {
        //     if (dp[j] > mx) {
        //         ans = j;
        //         break;
        //     }
        // }

        cout << ans << " ";
    }
    cout << "\n";
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

