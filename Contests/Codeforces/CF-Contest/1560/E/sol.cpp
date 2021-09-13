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

bool check(vll &cnt) {
    ll n = sz(cnt);
    rep(i, n) if (cnt[i]) return 0;
    return 1;
}
void transform(string &a, char c) {
    string ans;
    rep(i, sz(a)) {
        if (a[i] == c) continue;
        else ans.pb(a[i]);
    }

    a = ans;
}
bool make(string &ans1, string &ans2, string &s) {
    string a = ans1;
    string b = ans2;

    string ans = a;
    rep(i, sz(ans2)) {
        char c = ans2[i] - 'a';
        transform(a, c);
        ans = ans + a;
    }

    if (ans != s) return 0;
    return 1;
}
void solve() {
    string s;
    cin >> s;

    ll n = sz(s);
    string ans1, ans2;

    set<char> st;
    FORR(i, n - 1, 0) {
        auto it = st.find(s[i]);
        if (it == st.end()) {
            st.insert(s[i]);
            ans2.pb(s[i]);
        }
    }
    reverse(all(ans2));

    vll cnt(26, 0);
    rep(i, n) cnt[s[i] - 'a']++;

    ll len = sz(ans2);
    bool ok = 1;
    FORR(i, sz(ans2) - 1, 0) {
        if (len == 0) break;
        if (cnt[ans2[i] - 'a'] % len == 0) {
            cnt[ans2[i] - 'a'] /= len;
            len--;
        }
        else {
            ok = 0;
        }
    }

    rep(i, n) {
        ll x = s[i] - 'a';
        if (cnt[x]) {
            cnt[x]--;
            ans1.pb(s[i]);
        }
        else {
            if (check(cnt)) {
                break;
            }
            else {
                ok = 0;
                break;
            }
        }
    }
    if (!make(ans1, ans2, s)) {
        ok = 0;
    }

    if (!ok) {
        cout << -1 << "\n";
        return;
    }
    cout << ans1 << " " << ans2 << "\n";
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
