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

void fill(string &s, ll l, ll r) {
    FOR(i, l, r) s[i] = 'W';
}
void solve() {
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vpll gaps, extra;
    rep(i, n) {
        if (s[i] == 'L') {
            ll l = i;
            while (i < n && s[i] == 'L') i++;
            i--;

            ll r = i;

            if (l != 0 && r != n - 1) gaps.pb({r - l + 1, l});
            else {
                extra.pb({r - l + 1, l});
            }
        }
    }

    sort(all(gaps));
    sort(all(extra));
    // 2 * wins - consecutive wins

    rep(i, sz(gaps)) {
        if (k == 0) break;
        ll range = gaps[i].first, l = gaps[i].second;

        ll r = min(l + range - 1, l + k - 1);
        debug(i, l, r);
        k -= (r - l + 1);
        fill(s, l, r);
    }
    debug(gaps, s, k);
    debug(extra);

    rep(i, sz(extra)) {
        if (k == 0) break;
        ll range = extra[i].first, l = extra[i].second;
        ll r = l + range - 1;

        if (l == 0) {
            ll newl = r - min(range - 1, k - 1);
            fill(s, newl, r);
            k -= (r - newl + 1);
        }
        else {
            ll newr = min(l + range - 1, l + k - 1);
            fill(s, l, newr);
            k -= (newr - l + 1);
        }
    }

    debug(s, k);

    ll ans = 0ll;
    FOR(i, 0, n - 1) {
        if (i == 0) {
            if (s[i] == 'W') ans += 1ll;
        }
        else {
            if (s[i] == 'W') {
                if (s[i - 1] == 'W') ans += 2ll;
                else ans += 1ll;
            }
        }
    }

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
