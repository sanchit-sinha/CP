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
#define get(x,c)            get<x>((c))
#define trav(a,x)           for(auto a = (x).begin() ; a != (x).end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

string to_string(string s) {return '"' + s + '"';} string to_string(const char* s) {return to_string((string) s);} string to_string(bool b) {return (b ? "true" : "false");} template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";} template <typename A>string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", ";} first = false; res += to_string(x);} res += "}"; return res;} void debug_out() { cerr << "\n"; } template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n"; debug_out(T...);}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
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
vector<int> nearestsmallest(vector<int> &A) {
    int n = A.size();
    stack<pair<int, int>> s;
    vector<int> index(n, -1);

    for (int i = 0; i < n; i++) {
        int x = A[i];
        while (!s.empty() && s.top().first >= x) s.pop();
        if (s.empty()) index[i] = -1;
        else index[i] = s.top().second;

        s.push(make_pair(A[i], i));
    }

    return index;
}

vll smallestele(vll &v) {
    ll n = sz(v);
    stack<pll> s;

    vll index(n , -1);
    rep(i , n) {
        ll x = v[i];
        while (!s.empty() && s.top().first > x) s.pop();

        if (!s.empty()) index[i] = s.top().second;
        else index[i] = -1;

        s.push(mp(x, i));
    }

    return index;
}
void solve() {
    ll n;
    cin >> n;

    vll v(n);
    rep(i, n) cin >> v[i];

    reverse(all(v));
    vll right = smallestele(v);

    reverse(all(right));
    reverse(all(v));

    rep(i , n) if (right[i] != -1) right[i] = n - 1 - right[i];

    // rep(i , n) {
    //     if (right[i] != -1) cout << i << " : " << v[i] << " = " << v[right[i]] << "\n";
    // }

    ll ans = 0ll;
    vll nodis;
    rep(i , n) {
        if (right[i] == -1) nodis.pb(i), ans += v[i];
        else {
            ll x = (v[i] - v[right[i]]);
            ans += x;
        }
    }

    cout << ans << "\n";
    rep(i , sz(nodis)) cout << nodis[i] <<  " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);

    ll NTC = 1;
    // cin>>NTC;

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
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
