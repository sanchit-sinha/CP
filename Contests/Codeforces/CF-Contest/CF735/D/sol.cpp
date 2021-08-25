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

ll getAns(ll n, ll m) {
    vll v;
    for (int i = 0; i <= m; i++) {
        v.pb(n ^ i);
    }
    sort(all(v));

    ll ans = 0ll;
    rep(i, sz(v)) {
        if (v[i] != i) {
            ans = i;
            return ans;
        }
    }
    ans = sz(v);
    return ans;
}

ll dig(ll x) {
    ll ans = 0ll;
    while (x) {
        x /= 2;
        ans++;
    }

    return ans;
}
void solve() {
    ll n, m;
    cin >> n >> m;

    if (n > m) {
        cout << 0 << "\n";
        return;
    }


    // n <= m
    ll d = dig(n);
    ll ctn = 0, ctm = 0;
    FORR(i, d - 1, 0) {
        if ((1ll << i)&n) ctn++;
        if ((1ll << i)&m) ctm++;
    }


    if (ctn >= ctm) {
        cerr << "1\n";
        ll ans = 0ll;
        FORR(i, 32, d ) {
            if ((1ll << i)&m) {
                ans += (1ll << i);
            }
        }
        cout << ans << "\n";
        return;
    }
    else {
        // ctm > ctn
        bool done = 0;
        ll ans = 0ll;
        FOR(i, 0, 32) {
            if (done == 0 && (1ll << i)&m) continue;
            else {
                if (done == 0) ans += (1ll << i);
                else {
                    if ((1ll << i)&m) ans += (1ll << i);
                }
                done = 1;
            }
        }

        cout << ans << "\n";
        return;
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
