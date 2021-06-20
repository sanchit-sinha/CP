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
#define sz(c)               (int)(c.size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

string to_string(string s) {return '"' + s + '"';} string to_string(const char* s) {return to_string((string) s);} string to_string(bool b) {return (b ? "true" : "false");} template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";} template <typename A>string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", ";} first = false; res += to_string(x);} res += "}"; return res;} void debug_out() { cerr << "\n"; } template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n"; debug_out(T...);}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
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
stack<ll> update(vll &v1) {
    stack<ll> s1;
    rep(j, sz(v1)) {
        if (s1.empty()) s1.push(v1[j]);
        else if (s1.top() != v1[j]) s1.push(v1[j]);
    }

    return s1;
}

void displays(stack<ll> s1) {
    while (!s1.empty()) {
        cerr << s1.top() << " ";
        s1.pop();
    }

    cerr << "\n";
}
void displayr(stack<ll> s1) {
    stack<ll> s2;
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }

    while (!s2.empty()) {
        cerr << s2.top() << " " ;
        s2.pop();
    }

    cerr << "\n";
}
void add(stack<pll> &s2, stack<pll> &s1, ll x, ll index, vll &visited) {
    if (sz(s2) && s2.top().f == x) {
        s1.push(mp(x, index));
        visited[index] = 1;
    }
    else {
        s2.push(mp(x, index));
        visited[index] = 2;
    }
}

ll try1(vll a) {
    ll n = sz(a);
    stack<ll> s1, s2;
    vector<bool> vis(n , 0);

    rep(i , n) {
        if (s1.empty()) {
            s1.push(a[i]);
            vis[i] = 1;
        }
        else {
            if (a[i] != s1.top()) s1.push(a[i]), vis[i] = 1;
        }
    }

    rep(i , n) {
        if (!vis[i]) {
            if (s2.empty()) s2.push(a[i]);
            else if (s2.top() != a[i]) s2.push(a[i]);
        }
    }

    ll ans = sz(s1) + sz(s2);
    return ans;
}

ll try2(vll a, ll c) {
    ll n = sz(a);

    vll dummy(n , 0);
    FOR(i , 0 , n - 1) {
        dummy[i] = c;

        if (c) c = 0;
        else c = 1;
    }

    vll v1, v2;
    rep(i , n) {
        if (dummy[i]) v1.pb(a[i]);
        else v2.pb(a[i]);
    }

    stack<ll> s1 = update(v1);
    stack<ll> s2 = update(v2);

    ll ans = sz(s1) + sz(s2);
    return ans;
}
void solve() {
    ll n;
    cin >> n;

    vll a(n);
    rep(i , n) cin >> a[i];

    set<ll> ss;
    rep(i , n) ss.insert(a[i]);

    stack<ll> s = update(a);

    ll ans = sz(ss);
    ans = min(ans, sz(s));
    ans = min(ans , try2(a, 0));
    ans = min(ans , try2(a, 1));


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
    // cin >> NTC;

#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    factorial();
#endif
#ifdef PREPROCESS
    preprocess();
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
