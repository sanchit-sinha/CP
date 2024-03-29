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

vll mex(vll &a) {
    ll n = sz(a);
    vll sfxmex(n, 0);

    set<ll> s;
    FORR(i, n - 1, 0) {
        s.insert(a[i]);
        if (i == n - 1) {
            if (a[i] == 0) sfxmex[i] = 1;
            else sfxmex[i] = 0;
        }
        else {
            if (a[i] != sfxmex[i + 1]) sfxmex[i] = sfxmex[i + 1];
            else {
                ll r = a[i];
                while (1) {
                    auto it = s.find(r);
                    if (it == s.end()) break;
                    else r++;
                }

                sfxmex[i] = r;
            }
        }
    }
    return sfxmex;
}
void solve() {
    ll n;
    cin >> n;

    vll a(n);
    rep(i, n) cin >> a[i];

    vll sfxmex = mex(a);

    debug(sfxmex);

    vll b;
    set<ll> s;
    rep(i, n) {
        ll mexx = sfxmex[i];
        b.pb(mexx);

        // finding pfx with mex = mexx;
        ll l = 0;
        if (a[i] == 0) l = 1;

        if (l != mexx) {
            l = 0;
            ll mxx = 0;
            set<ll> s;
            while (i < n) {
                s.insert(a[i]);
                if (a[i] != l) mxx = l;
                else {
                    l = a[i];
                    while (1) {
                        auto it = s.find(l);
                        if (it == s.end()) break;
                        else l++;
                    }
                    mxx = l;
                }

                if (mxx == mexx) break;
                i++;
            }
        }
        debug(i, mexx);
    }

    cout << sz(b) << "\n";
    for (auto &x : b) cout << x << " ";
    cout << "\n";
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
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
