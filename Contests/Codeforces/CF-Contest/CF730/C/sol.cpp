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
const ld eps = 1e-7;

ld getAns(ll len, ld c, ld m, ld p, ld v) {
    ll mx = (1ll << len);
    ld ans = p;
    FOR(i, 0, mx - 1) {
        string s(len, '?');
        FOR(j, 0, len - 1) {
            if ((1ll << j) & i) s[j] = 'C';
            else s[j] = 'M';
        }

        ld tempc = c, tempm = m, tempp = p;
        ld p = 1.0;
        bool earlybreak = 0;
        rep(j, sz(s)) {
            if (tempc <= eps && tempm <= eps) {
                earlybreak = 1;
                break;
            }
            if (tempc > eps && s[j] == 'C') {
                p *= tempc;
                ll candidates = (tempm > eps) + (tempp > eps);
                ld dis = ((tempc <= v) ? (tempc) : (v)) / candidates;
                tempc = ((tempc <= v) ? (0.0) : (tempc - v));

                tempm += dis;
                tempp += dis;
                // debug("1", dis, tempc, tempm, tempp);
            }

            if (tempm > eps && s[j] == 'M') {
                p *= tempm;
                ll candidates = (tempc > eps) + (tempp > eps);
                ld dis = ((tempm <= v) ? (tempm) : (v)) / candidates;
                tempm = ((tempm <= v) ? (0.0) : (tempm - v));

                tempm += dis;
                tempp += dis;
                // debug("2", dis, tempc, tempm, tempp);
            }
            // cerr << s[j];
        }
        // cerr << "\n";

        p *= tempp;
        if (!earlybreak) ans += p;
    }

    return ans;
}
void solve() {
    ld c, m, p, v;
    cin >> c >> m >> p >> v;

    ll mx = 10;
    ld ans = p;
    FOR(i, 0, mx) {
        ans += getAns(i, c, m, p, v);
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
