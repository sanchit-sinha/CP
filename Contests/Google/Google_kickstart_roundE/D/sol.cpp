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
#define sz(c)               (ll)((c).size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(ll i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(ll i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(ll i = (b); i >= (a); i--)

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

ld stirlingFactorial(int n)
{
    if (n == 1)
        return 1.0;
    ld z;
    ld e = 2.71;
    z = sqrt(2 * 3.14 * n) * pow((n / e), n);
    return 1.0 / z;
}
const ll N = 1e7 + 1;
ld fact[N + 3];
#define PREPROCESS
void preprocess() {
    fact[1] = 1;
    for (ll i = 2; i < N; i++) {
        fact[i] = (1.0 / i) * fact[i - 1];
    }
}

void solve() {
    ll n;
    cin >> n;

    if (n <= 8) {
        vll a(n, 0);
        rep(i, n) a[i] = i + 1;

        ld ans = 0.0;
        ll tot = 0ll;
        ll cnt = 0ll;

        set <pll> store;
        do {
            ll ct = 1;
            tot++;

            ll val = (1ll << a[0]);
            FOR(i, 1, n - 1) {
                if (a[i] > a[i - 1]) {
                    val += (1ll << a[i]);
                    ct += 1;
                }
                else {
                    store.insert({val, ct});
                    break;
                }
            }
            if (ct == n) {
                debug("in1", ct, val);
                store.insert({val, ct});
            }
            // ans += (fact[n]) * ct;
            // cnt += ct;

        } while (next_permutation(all(a)));

        cnt = 0;
        trav(it, store) cnt += (it->s);
        debug(cnt, tot);
        ans = (1.0 * cnt) / tot;
        cout << ans << "\n";
        return;
    }

    if (n < N) {
        cout << (1 + 1 - fact[n]) << "\n";
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
        cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
