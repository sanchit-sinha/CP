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


void solve() {
    ll k;
    cin >> k;

    ll n, m;
    cin >> n >> m;

    vll a(n), b(m);
    rep(i, n) cin >> a[i];

    rep(i, m) cin >> b[i];

    vpll v;

    ll l = 0, r = 0 ;
    ll lines = k;
    debug(a, b);
    while (l < n && r < m) {
        if (a[l] == 0) {
            while (l < n && a[l] == 0)v.pb({a[l], 0}), l++, lines++;
        }
        else if (b[r] == 0) {
            while (r < m && b[r] == 0)v.pb({b[r], 1}), r++, lines++;
        }
        else {
            ll mn = min(a[l], b[r]);
            if (mn <= lines) {
                if (mn == a[l]) v.pb({a[l], 0}), l++;
                else v.pb({b[r], 1}), r++;
            }
            else {
                cout << -1 << "\n";
                return;
            }
        }
    }
    debug(l, n, r, m);
    debug(v);
    if (l < n) {
        while (l < n) {
            if (a[l] == 0) {
                while (l < n && a[l] == 0)v.pb({a[l], 0}), l++, lines++;
            }
            else {
                ll mn = a[l];
                if (mn <= lines) {
                    if (mn == a[l]) v.pb({a[l], 0}), l++;
                }
                else {
                    cout << -1 << "\n";
                    return;
                }
            }
        }
    }
    else if (r < m) {
        while (r < m) {
            if (b[r] == 0) {
                while (r < m && b[r] == 0)v.pb({b[r], 1}), r++, lines++;
            }
            else {
                ll mn = b[r];
                if (mn <= lines) {
                    if (mn == b[r]) v.pb({b[r], 1}), r++;
                }
                else {
                    cout << -1 << "\n";
                    return;
                }
            }
        }
    }
    rep(i , sz(v)) {
        cout << v[i].f << " ";
    }

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
