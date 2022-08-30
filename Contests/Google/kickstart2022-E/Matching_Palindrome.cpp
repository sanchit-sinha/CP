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


// 0 - indexed hashing
const ll PR1 = 31;
const ll PR2 = 53;
const ll  MOD = 1e9 + 9;
class rollinghash {
public:
    string s;
    ll PR;
    ll MOD;
    vector<ll> ro;
    vector<ll> minv;
    vector<ll> pw;
    rollinghash(string ss, ll pr, ll mod) {
        s = ss; PR = pr; MOD = mod; int N = (int)s.length(); ll p = 1ll, val = 0;
        ro.resize(N); minv.resize(N + 1); pw.resize(N + 1);
        for (int i = 0; i < N; i++) {
            val += (((s[i] - 'a' + 1) * p) % MOD); val %= MOD; p = (p * PR) % MOD; ro[i] = val;
        }
        pw[0] = 1; minv[0] = 1; minv[1] = powermod(PR, MOD - 2, MOD);
        for (int i = 1; i <= N; i++) pw[i] = (pw[i - 1] * PR) % MOD;
        for (int i = 2; i <= N; i++) minv[i] = (minv[i - 1] * minv[1]) % MOD;
    }

    ll get(int ii, int jj) {
        if (ii > jj) return 0ll;
        return ((minv[ii] * (ro[jj] - ((ii - 1 >= 0) ? ro[ii - 1] : 0))) % MOD + MOD) % MOD;
    }
};
// constructing rolling hash of prefixes - rollinghash r (str, PR, MOD);
// getting prefix of substring - r.get(l, r)

void solve() {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    string t = s;
    reverse(all(t));

    rollinghash r1(s, PR1, MOD);
    rollinghash r2(s, PR2, MOD);

    rollinghash rr1(t, PR1, MOD);
    rollinghash rr2(t, PR2, MOD);


    auto check = [&](ll l, ll r) {
        ll mid = (l + r) / 2;

        ll lleft = l, rleft = mid, lright = mid + 1, rright = r;
        ll rh1 = 0, rh2 = 0, rrh1 = 0, rrh2 = 0;
        if ((r - l + 1) & 1) rleft--;

        ll olright = n - 1 - rright;
        ll orright = n - 1 - lright;

        rh1 = r1.get(lleft, rleft);
        rh2 = r2.get(lleft, rleft);

        rrh1 = rr1.get(olright, orright);
        rrh2 = rr2.get(olright, orright);

        if (rh1 == rrh1 && rh2 == rrh2) return 1;
        return 0;
    };


    FOR(i, 1, n - 1) {
        if (check(i, n - 1) && check(0, i - 1)) {
            debug(i);
            string ans = s.substr(0, i);
            cout << ans << "\n";
            return;
        }
    }

    cout << s << "\n";
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
        cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) { if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex, ll md) { ll ans = 1ll; while (ex > 0) { if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md; } return ans; }

