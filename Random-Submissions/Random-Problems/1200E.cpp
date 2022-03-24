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


const ll N = 1e6 + 3;
const ll  MOD = 1e9 + 9;
ll PR[2] = { 31,53 };
ll pw[2][N], minv[2][N], pfx[2][N];

// 0 - indexed hashing
#define PREPROCESS
void preprocess() {
    pw[0][0] = pw[1][0] = minv[0][0] = minv[1][0] = 1LL;
    for (int i = 1; i < N; i++) {
        pw[0][i] = (pw[0][i - 1] * PR[0]) % MOD;
        pw[1][i] = (pw[1][i - 1] * PR[1]) % MOD;
    }

    minv[0][1] = powermod(PR[0], MOD - 2, MOD), minv[1][1] = powermod(PR[1], MOD - 2, MOD);
    for (int i = 2; i < N; i++) {
        minv[0][i] = (minv[0][i - 1] * minv[0][1]) % MOD;
        minv[1][i] = (minv[1][i - 1] * minv[1][1]) % MOD;
    }
}

void gen_hashes(string& s, ll index) {
    vll val(2, 0LL), p(2, 1LL);
    if (index) {
        rep(j, 2) {
            val[j] = pfx[j][index - 1];
            p[j] = pw[j][index - 1] * PR[j];p[j] %= MOD;
        }
    }

    for (int i = index; i < sz(s); i++) {
        rep(j, 2) {
            val[j] += (((s[i] - 'A' + 1) * p[j]) % MOD);
            val[j] %= MOD; p[j] = (p[j] * PR[j]) % MOD;
            pfx[j][i] = val[j];
        }
    }
}

ll get(int ii, int jj, int k) {
    return ((minv[k][ii] * (pfx[k][jj] - ((ii - 1 >= 0) ? pfx[k][ii - 1] : 0))) % MOD + MOD) % MOD;
}

class rollinghash {
public:
    string s;
    ll PR;
    ll MOD;
    vector<ll> ro;
    vector<ll> minv;
    vector<ll> pw;
    rollinghash(string ss, ll pr, ll mod) {
        s = ss; PR = pr; MOD = mod; int N = (int) s.length(); ll p = 1ll, val = 0;
        ro.resize(N); minv.resize(N + 1); pw.resize(N + 1);
        for (int i = 0; i < N; i++) {
            val += (((s[i] - 'A' + 1) * p) % MOD); val %= MOD; p = (p * PR) % MOD; ro[i] = val;
        }
        pw[0] = 1; minv[0] = 1; minv[1] = powermod(PR, MOD - 2, MOD);
        for (int i = 1; i <= N; i++) pw[i] = (pw[i - 1] * PR) % MOD;
        for (int i = 2; i <= N; i++) minv[i] = (minv[i - 1] * minv[1]) % MOD;
    }

    ll get(int ii, int jj) {
        return ((minv[ii] * (ro[jj] - ((ii - 1 >= 0) ? ro[ii - 1] : 0))) % MOD + MOD) % MOD;
    }
};
// constructing rolling hash of prefixes - rollinghash r (str, PR, MOD);
// getting prefix of substring : r.get(l, r)

void solve() {
    ll n;
    cin >> n;

    vector<string> s(n);
    rep(i, n) cin >> s[i];

    string ans = s[0];
    gen_hashes(ans, 0);

    FOR(i, 1, n - 1) {
        rollinghash r1(s[i], PR[0], MOD), r2(s[i], PR[1], MOD);

        ll r = sz(ans) - 1, l = r, index = -1;
        FOR(j, 0, sz(s[i]) - 1) {
            if (l < 0) break;

            if (i == 2 && j == 3) {
                debug(l, r, 0, j, ans, s[i]);
                debug(get(l, r, 0), r1.get(0, j));
                debug(get(l, r, 1), r2.get(0, j));
            }

            if (get(l, r, 0) == r1.get(0, j) && get(l, r, 1) == r2.get(0, j)) {
                index = j;
            }

            l--;
        }
        debug(index);

        ll last = sz(ans);
        FOR(j, index + 1, sz(s[i]) - 1) {
            ans.pb(s[i][j]);
        }

        gen_hashes(ans, last);
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

