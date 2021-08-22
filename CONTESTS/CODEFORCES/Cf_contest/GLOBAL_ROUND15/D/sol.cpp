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

void pr(vll &ans) {
    cout << "YES\n";
    for (auto &x : ans) cout << x << " ";
    cout << "\n";
    return;
}
bool check(vll &ans, vll &a) {
    ll n = sz(ans);

    rep(i, n) {
        ll x = a[i];
        bool got = 0;

        rep(j, n) {
            rep(k, n) {
                if (ans[k] - ans[j] == a[i]) got = 1;
            }
        }

        if (!got) return 0;
    }

    return 1;
}


vll convert(ll bit, ll n) {
    vll ans(n, 0);

    ll index = 0;
    while (bit) {
        ans[index++] = bit % 3;
        bit /= 3;
    }

    return ans;

}
void solve() {
    ll n;
    cin >> n;

    vll a(n);
    rep(i, n) cin >> a[i];

    map<ll, ll> m;
    rep(i, n) m[abs(a[i])]++;

    debug(m);
    vll ans(n, 0);

    ans[0] = 0;
    ll index = 1;

    rep(i, n) {
        ll x = abs(a[i]);
        if (x && m[x] && index < n) {
            ans[index] = ans[0] - x;

            m[x] = 0;
            index++;
        }
    }

    if (check(ans, a)) {
        cout << "YES\n";
        return;
    }
    else {
        unordered_map<ll, ll> element;
        rep(i, n) element[a[i]] = i;

        vpll store;

        ll mx = power(3, n);
        cerr << mx << "\n";

        FOR(i, 1, mx - 1) {
            vll bit = convert(i, n);
            ll val = 0;

            rep(j, n) {
                if (bit[j] == 1) val += a[j];
                else if (bit[j] == 2) val -= a[j];
            }

            if (element.count(val)) {
                ll indexx = element[val];
                if (bit[indexx]) continue;

                cout << "YES\n";
                return;
            }
        }

        cout << "NO\n";
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
