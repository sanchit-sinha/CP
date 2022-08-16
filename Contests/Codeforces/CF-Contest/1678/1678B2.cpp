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
    ll n;
    cin >> n;

    string s;
    cin >> s;

    string t = s;

    ll ans = 0ll;
    rep(i, n) {
        char c = s[i];
        ll cnt = 0ll;
        while (i < n && s[i] == c) i++, cnt++;
        i--;

        if (cnt & 1) {
            if (s[i] == '1') s[i] = '0';
            else s[i] = '1';
            ans++;
            i--;
        }
    }

    s = t;
    n = sz(s);
    vpll ct;
    rep(i, n) {
        char c = s[i];
        ll cnt = 0ll;
        while (i < n && s[i] == c) i++, cnt++;
        i--;
        ct.pb({ cnt, 1ll * (c - '0') });
    }

    debug(ct);
    ll len = sz(ct);
    ll seg = len;

    vector<array<ll, 3>> cond;
    rep(i, len) {
        if (ct[i].f & 1) {
            vll op;
            op.pb(ct[i].f);

            ll ok = 0;
            if ((ct[i].s) == 1) ok = 1;

            i++;
            while ((i < len) && (op[i] % 2 != 1)) {
                op.pb(ct[i].f);
                i++;
            }
            op.pb(ct[i].f);
            debug("before", i, op);

            debug(seg);
            for (ll j = 1; j < sz(op); j += 2) {
                if (op[j] == 1) seg -= 1ll, op[j] -= 1ll;
                else if (op[j] == 2) seg -= 2ll, op[j] -= 2ll;
            }
            debug(seg);

            vll col;
            col.pb(ok);
            FOR(j, 1, sz(op) - 1) col.pb(col.back() ^ 1);

            rep(j, sz(op)) {
                if (op[j] == 0) col[j] ^= 1;
            }

            cond.pb({ col[0], col.back() ,1 });

            debug("after", i, op);
        }
        else {
            cond.pb({ ct[i].s - '0', ct[i].s - '0' ,0 });
        }
    }
    debug(seg);
    debug(cond);

    // rep(i, sz(cond)) {
    //     if (i) {
    //         if (cond[i][0] == cond[i - 1][1]) {
    //             seg--;
    //         }
    //         else {
    //             if (cond[i][2] == 1) {
    //                 seg--;
    //                 cond[i][0] ^= 1;
    //                 cond[i][1] ^= 1;
    //             }
    //         }
    //     }
    // }


    cout << ans << " " << seg << "\n";

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