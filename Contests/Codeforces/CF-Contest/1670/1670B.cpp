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

set<ll> st[26];
void solve() {
    rep(i, 26) st[i].clear();

    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll k;
    cin >> k;

    vector<bool> spl(26, 0);
    rep(i, k) {
        char c;
        cin >> c;
        spl[c - 'a'] = 1;
    }

    set<ll> index;
    rep(i, n) index.insert(i);

    for (auto& x : index) {
        if (spl[s[x] - 'a']) st[s[x] - 'a'].insert(x);
    }

    ll ans = 0ll;
    while (1) {
        vll er;
        rep(i, 26) {
            if (sz(st[i])) debug(i, st[i]);
            for (auto& x : st[i]) {
                auto it = index.lb(x);
                if (it != index.begin()) {
                    ll err = (*(--it));
                    er.pb(err);
                }
            }
        }
        debug(er);
        if (sz(er) == 0) {
            cout << ans << "\n";
            return;
        }
        else {
            ans++;
            for (auto& x : er) {
                if (spl[s[x] - 'a']) {
                    auto its = st[s[x] - 'a'].find(x);
                    if (its != st[s[x] - 'a'].end()) st[s[x] - 'a'].erase(its);
                }

                auto iti = index.find(x);
                if (iti != index.end()) index.erase(iti);
            }
        }
    }

    cout << ans << "\n";
    return;
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

