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
#define pll                 pair<ll, ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (ll)((c).size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin(); a != x.end(); a++)
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
const ll mod = 998244353;
const ld PI = acos(-1);
const ld eps = 1e-9;

ll calc(string s, string t) {
    ll one = 0ll;
    ll n = sz(s);
    rep(i, n) one += (s[i] == '1');

    rep(i, n) one -= (s[i] == '1' && t[i] == '1');

    return one;
}
void brute(string s, ll k) {
    string t = s;
    sort(all(s));

    set<string> v;
    do {
        if (calc(s, t) <= k) {
            v.insert(s);
        }
    } while (next_permutation(all(s)));

    cout << sz(v) << "\n";
    for (auto &x : v) cout << x << "\n";
}

const ll N = 5e3 + 11;
#define NCR
const ll mX = N;
ll fact[mX + 11] , invfact[mX + 11];
void factorial() {
    fact[0] = invfact[0] = 1;
    for (ll i = 1 ; i < mX ; i++) {
        fact[i] = i * fact[i - 1];
        fact[i] %= mod;
    }
    invfact[mX - 1] = powermod(fact[mX - 1] , mod - 2 , mod); // if mod is prime
    for (ll i = mX - 2 ; i > 0 ; i--) {
        invfact[i] = invfact[i + 1] * (i + 1);
        invfact[i] %= mod;
    }
}
ll ncr(ll n , ll r) {
    if (r > n || n < 0 || r < 0)return 0;
    ll p = (fact[n] * invfact[r]) % mod;
    p *= invfact[n - r];
    return p % mod;
}


void solve() {
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    // brute(s, k);

    vll pfx(n, 0);
    rep(i, n) {
        if (i == 0) {
            if (s[i] == '1') pfx[i] = 1;
        }
        else {
            pfx[i] = pfx[i - 1];
            if (s[i] == '1') pfx[i] += 1;
        }
    }

    auto getVal = [&](ll l, ll r) {
        if (l < 0 || l >= n) return 0ll;
        if (r < 0 || r >= n) return 0ll;

        ll len = (r - l + 1);

        ll one = pfx[r];
        if (l) one -= pfx[l - 1];

        ll p = fact[len]; p %= mod;
        p *= invfact[one], p %= mod;
        p *= invfact[len - one], p %= mod;

        p -= 1, p += mod, p %= mod;

        return p;
    };

    if (k == 0) {
        cout << 1 << "\n";
        return;
    }

    ll ans = 0ll;
    pll prev = {inf, -inf};
    FOR(i, 0, n - 1) {
        FORR(j, n - 1, i) {
            ll x = pfx[j];
            if (i) x -= pfx[i - 1];

            if (x == k) {
                // i , j
                ll len = (j - i + 1);
                ll p = getVal(i, j);

                ll s = 0ll;

                if (prev.s <= j) {
                    pll comman = {i, prev.s};

                    prev.f = min(prev.f, i);
                    prev.s = max(prev.s, j);

                    s = getVal(comman.f, comman.s);

                    debug(comman, s);
                }
                else {
                    prev = {i, j};
                }

                debug(i, j, p, s);

                ans += p, ans %= mod;
                ans -= s , ans += mod, ans %= mod;

                break;
            }
        }
    }

    ans += 1ll, ans %= mod;
    cout << ans << "\n";
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
