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

bool check(string &t, string &s) {
    ll n = sz(t);
    rep(i, n) {
        if (s[i] == t[i]) return 0;
    }

    return 1;
}
void solve() {
    string s;
    cin >> s;

    string t = s;
    sort(all(t));

    ll n = sz(t);
    set<pll> st;


    if (n <= 8) {
        string A = t;
        do {
            if (check(A, s)) {
                cout << A << "\n";
                return;
            }
        } while (next_permutation(all(A)));

        cout << "IMPOSSIBLE\n";

        return;
    }

    rep(i, n) {
        char c = t[i];
        ll ct = 0ll;

        while (i < n && t[i] == c) ct++, i++;
        i--;

        st.insert({ct, c - 'a'});
    }

    debug(st);
    string ans(n, '?');

    while (!st.empty()) {
        auto p = *st.rbegin();
        ll cnt = p.first;
        char c = (char)('a' + p.second);

        rep(i, n) {
            if (cnt == 0) break;
            if (s[i] != c && ans[i] == '?') {
                ans[i] = c;
                cnt--;
            }
        }

        if (cnt) break;
        st.erase(st.find(p));
    }

    debug(ans);

    bool ok = 1;
    rep(i, n) if (ans[i] == '?') ok = 0;

    if (ok) cout << ans << "\n";
    else cout << "IMPOSSIBLE\n";
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
