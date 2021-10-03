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

ll eval(vll &a) {
    ll n = sz(a);
    ll ans = 0ll;

    rep(i, n) {
        ll x = a[i];
        ll ct = 0ll;
        while (i < n && a[i] == x) i++, ct++;
        i--;

        ans += (ct - 1);
    }

    return ans;
}
void brute(ll a, ll b, ll c, ll m) {
    vll v;
    rep(i , a) v.pb(1);
    rep(i , b) v.pb(2);
    rep(i , c) v.pb(3);

    set<ll> ans;
    map<ll, vll> mp;
    do {
        ll x = eval(v);
        ans.insert(x);
        mp[x] = v;
    } while (next_permutation(all(v)));

    cout << "Ans : ";
    trav(it, ans) cout << *it << " ";
    cout << "\n**************\n";

    trav(it, mp) {
        cout << it->f << ": ";
        rep(j, sz(it->s)) cout << it->s[j] << " ";
        cout << "\n";
    }
    cout << "\n";
}
bool poss(ll a, ll b, ll c) {
    if (c < b) swap(c, b);
    // c: max

    ll mn = min(a, c);
    a -= mn;
    c -= mn;

    if (c) {
        if (abs(b - c) <= 2) return 1;
        return 0;
    }
    else {
        // a
        if (b - a <= 2 && b - a >= 0) return 1;
        return 0;
    }

    return 0;
}
bool check1(ll a, ll b, ll c, ll m) {
    if (a - 1 < m) return 0;
    a -= (m + 1);

    return poss(a, b, c);
}

bool check2(ll a, ll b, ll c, ll m) {
    if (a - 1 > m) return 0;
    m -= (a - 1);
    a = 0;

    bool ok = 0;
    ok = check1(b, c, a, m);
    ok = check1(c, b, a, m);

    return ok;
}
void solve() {
    ll a, b, c, d, m;
    cin >> a >> b >> c >> m;

    ll mx = (a + b + c - 3);
    ll mn = 0;

    ll mxx = max({a, b, c});
    ll mnn = min({a, b, c});
    ll mid = a + b + c - mxx - mnn;

    if (mxx > mnn + mid + 1) mn = (mxx - mnn - mid - 1);

    if (m >= mn && m <= mx) cout << "YES\n";
    else cout << "NO\n";
    // brute(a, b, c, m);
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
