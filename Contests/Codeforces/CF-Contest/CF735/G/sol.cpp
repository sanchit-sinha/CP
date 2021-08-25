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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll range(ll l , ll r) {
    ll n = uniform_int_distribution<int> (l , r)(rng);
    return n;
}

bool check(vll &a) {
    ll n = sz(a);

    vll b = a;
    vpll v;
    rep(i, n) {
        ll temp = a[i];
        ll index = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] > temp) {
                swap(a[j], a[j + 1]);
                index = j;
            }
            else {
                break;
            }
        }
        if (index != -1) v.pb({index, i});
    }


    rep(i, sz(v)) {
        ll x = v[i].f, y = v[i].s;
        ll mn = min(x, y), mx = max(x, y);
        FORR(j, mx - 1, mn) {
            swap(b[j], b[j + 1]);
        }
    }

    // vll b = a;
    // vpll v;
    // rep(i, n) {
    //     ll temp = a[i];
    //     int j = i - 1;
    //     for (j = i - 1; j >= 0; j--) {
    //         if (a[j] > temp) {
    //             v.pb({j + 2, j + 1});
    //             swap(a[j], a[j + 1]);
    //         }
    //         else break;
    //     }
    // }


    // rep(i, sz(v)) {
    //     ll x = v[i].f, y = v[i].s;
    //     swap(b[x - 1], b[y - 1]);
    // }


    return (is_sorted(all(b)));
}
void solve() {

    // /*
    ll n;
    cin >> n;

    vll a(n);
    rep(i, n) {
        string s;
        cin >> s;
        cin >> a[i];
    }

    vll b = a;
    vpll v;
    rep(i, n) {
        ll temp = a[i];
        ll index = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] > temp) {
                swap(a[j], a[j + 1]);
                index = j;
            }
            else {
                break;
            }
        }
        if (index != -1) v.pb({index, i});
    }


    rep(i, sz(v)) {
        ll x = v[i].f, y = v[i].s;
        ll mn = min(x, y), mx = max(x, y);
        FORR(j, mx - 1, mn) {
            swap(b[j], b[j + 1]);
        }
    }


    rep(i, sz(v)) {
        cout << "Move " << v[i].f + 1 << " to " << v[i].s + 1 << "\n";
    }


    // */


    // int iters = 0;
    // while (iters < 1000) {
    //     ll n = range(1, 100);
    //     vll a(n);
    //     rep(i, n) {
    //         a[i] = range(1, n);
    //     }

    //     if (!check(a)) {
    //         cout << "false\n";
    //         break;
    //     }
    //     else cout << "correct\n";

    //     iters++;
    // }
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
