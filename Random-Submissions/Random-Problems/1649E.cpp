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
const ll mod = 998244353;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 2e5 + 11;
#define NCR
const ll mX = N;
ll fact[mX + 11], invfact[mX + 11];
void factorial() {
    fact[0] = invfact[0] = 1;
    for (ll i = 1; i < mX; i++) {
        fact[i] = i * fact[i - 1];
        fact[i] %= mod;
    }
    invfact[mX - 1] = powermod(fact[mX - 1], mod - 2, mod); // if mod is prime
    for (ll i = mX - 2; i > 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1);
        invfact[i] %= mod;
    }
}
ll ncr(ll n, ll r) {
    if (r > n || n < 0 || r < 0)return 0;
    ll p = (fact[n] * invfact[r]) % mod;
    p *= invfact[n - r];
    return p % mod;
}


struct FenwickTree {
    vector<long long> bit;  // binary 1-indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0ll);
    }

    FenwickTree(vector<long long> a) : FenwickTree(a.size()) { // a : 1 - indexed
        for (size_t i = 1; i < a.size(); i++)
            update(i, a[i]);
    }

    void update(int x, ll increment) {
        while (x <= n) {
            bit[x] += increment; // update operation
            x += (x & -x);
        }
    }

    ll query(int x) { // 1 .. x
        ll val = 0ll; // operation (inf , -inf , 0 ...)
        while (x > 0) {
            val += bit[x]; // operation
            x -= (x & -x);
        }
        return val;
    }

    ll query(int l, int r) { // l .. r
        return query(r) - query(l - 1);
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;

    vll s(n), t(m);
    rep(i, n) cin >> s[i];
    rep(i, m) cin >> t[i];

    map<ll, ll> cnt;
    rep(i, n) cnt[s[i]]++;

    FenwickTree fT(N + 3);
    ll cur = fact[n] % mod;
    for (auto& x : cnt) {
        fT.update(x.f, x.s);
        cur *= invfact[x.s], cur %= mod;
    }

    debug(cnt);
    ll ans = 0ll;
    rep(i, min(n, m)) {
        ll ti = t[i], rem = (n - i);
        ll sumL = 0ll, inv = powermod(rem, mod - 2, mod);
        if (ti > 1) sumL = fT.query(1, ti - 1) % mod;

        ll val = cur * inv; val %= mod;
        val *= sumL; val %= mod;
        ans += val, ans %= mod;

        if (cnt.count(ti) && cnt[ti]) {
            cur *= inv; cur %= mod;
            cur *= cnt[ti]; cur %= mod;

            cnt[ti]--;
            fT.update(ti, -1);

            if (i == min(n, m) - 1 && m > n) {
                debug("in");
                ans++;ans %= mod;
            }
        }
        else {
            break;
        }
    }
    cout << ans << "\n";
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

