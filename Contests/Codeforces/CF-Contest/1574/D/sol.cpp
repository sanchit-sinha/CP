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

string genstr(vll &v) {
    ll n = sz(v);

    string s = "";
    rep(i, n) {
        s += to_string(v[i]);
    }

    return s;
}

bool zero(vll &ptr) {
    bool ok = 1;
    rep(i, sz(ptr)) if (ptr[i]) ok = 0;

    return ok;
}
void disp(vll &ptr) {
    ll n = sz(ptr);
    rep(i, n) cout << ptr[i] + 1 << " ";
    cout << "\n";
}
ll getLowest(set<pll> &st) {
    return st.begin()->s;
}
void solve() {
    ll n;
    cin >> n;

    vvll a(n);
    rep(i, n) {
        ll len;
        cin >> len;

        rep(j, len) {
            ll x;
            cin >> x;
            a[i].pb(x);
        }
    }

    debug(a);
    ll m;
    cin >> m;
    vvll db(m, vll(n, 0));

    rep(i, m) {
        rep(j, n) cin >> db[i][j], db[i][j]--;
    }

    set<string> banned;
    rep(i, m) {
        string t = genstr(db[i]);
        banned.insert(t);
    }
    debug(banned);

    set<pll> st;
    vll ptr(n, 0);

    rep(i, n) ptr[i] = sz(a[i]) - 1;
    rep(i, n) st.insert({a[i][ptr[i]], i});

    debug(st)
    ;    while (!zero(ptr)) {
        string t = genstr(ptr);
        debug(t);

        auto it = banned.find(t);
        if (it == banned.end()) {
            debug("ans", t);
            disp(ptr);
            return;
        }
        else {
            rep(i, n) {
                ll lwIndex = getLowest(st);
                if (ptr[lwIndex]) {
                    pll p = {a[lwIndex][ptr[lwIndex]], lwIndex};
                    st.erase(st.find(p));

                    ptr[lwIndex]--;
                    p = {a[lwIndex][ptr[lwIndex]], lwIndex};
                    st.insert(p);
                }
            }
        }
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
