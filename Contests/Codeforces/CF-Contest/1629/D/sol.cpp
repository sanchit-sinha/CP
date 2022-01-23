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


void solve() {
    ll n;
    cin >> n;

    vector<string> s(n);
    rep(i, n) cin >> s[i];

    rep(i, n) {
        if (sz(s[i]) == 1) {
            cout << "YES\n";
            return;
        }
        else {
            ll len = sz(s[i]);
            if (s[i][0] == s[i][len - 1]) {
                cout << "YES\n";
                return;
            }
        }
    }

    multiset<string> st, st2;
    rep(i, n) {
        st.insert(s[i]);
        if (sz(s[i]) == 3) {
            string t;
            t.pb(s[i][1]), t.pb(s[i][2]);
            st2.insert(t);
        }
    }

    debug(st);
    debug(st2);
    // return;

    rep(i, n) {
        string x = s[i];
        ll len = sz(x);

        auto it11 = st.find(x);
        if (it11 != st.end()) st.erase(it11);

        if (len == 3) {
            string tt;
            tt.pb(s[i][1]), tt.pb(s[i][2]);

            auto it12 = st2.find(tt);
            if (it12 != st2.end()) st2.erase(it12);
        }


        if (len >= 2) { // both rev
            string ta = x;
            reverse(all(ta));

            auto ita = st.find(ta);
            if (ita != st.end()) {
                cout << "YES\n";
                return;
            }
        }

        if (len == 2) { // ab _ba
            string tb;
            tb.pb(x[1]);
            tb.pb(x[0]);

            auto itb = st2.find(tb);
            if (itb != st2.end()) {
                cout << "YES\n";
                return;
            }
        }

        if (len == 3) { // abx ba
            string tc;
            tc.pb(x[1]);
            tc.pb(x[0]);

            auto itc = st.find(tc);
            if (itc != st.end()) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
    return;
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
