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
    ll n , q;
    cin >> n >> q;

    vll a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    vll dp(n, 0);
    vll save(n, 0);
    map<pll, ll> m;
    vpll v;

    dp[0] = 1;
    save[0] = a[0];
    FOR(i, 1, n - 1) {
        if (a[i] == a[i - 1] + 1) {
            dp[i] = dp[i - 1] + 1;
            save[i] = save[i - 1];
        }
        else {
            v.pb(mp(save[i - 1], a[i - 1]));
            dp[i] = 1;
            save[i] = a[i];
        }
    }

    v.pb(mp(save[n - 1], a[n - 1]));

    ll prev = 0ll;
    rep(i , sz(v)) {
        prev += (v[i].s - v[i].f + 1);
        m[v[i]] = prev;
    }

    map<pll, ll> mainm;
    prev = 1ll;
    ll sum = 0ll;
    trav(it, m) {
        ll fnum = (it->f).f;
        ll snum = (it->f).s;

        if (it == m.begin()) {
            mainm[mp(1, fnum - 1)] = 0;
            prev = fnum;
        }
        else {
            ll pres = fnum - sum - 1;
            mainm[mp(prev, pres)] = sum;
            prev = pres + 1;
        }
        sum = it->s;
    }
    mainm[mp(prev, inf)] = sum;

    debug(mainm);

    debug(m);

    debug(v);
    while (q--) {
        ll k;
        cin >> k;

        auto it = mainm.ub(mp(k, inf));
        assert(it != mainm.begin());
        it--;

        cout << k + (it -> s) << "\n";
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
    // cin >> NTC;

#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    factorial();
#endif
#ifdef PREPROCESS
    preprocess();
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
