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

// insert from front, remove from front, query function for elements present
template<typename T, class F = function<T(const T& , const T&)>>
struct fstack { // like min stack
    stack<T> stk , fstk;
    F func;

    fstack(const F &f): func(f) {};

    fstack() {
        fstack(nullptr);
    }

    void push(T add) {
        if (stk.empty()) fstk.push(add);
        else fstk.push(func(fstk.top() , add));

        stk.push(add);
    }

    void pop() {
        assert(!stk.empty());
        stk.pop();
        fstk.pop();
    }

    T top() {
        assert(!stk.empty());
        return stk.top();
    }

    T query() {
        assert(!fstk.empty());
        return fstk.top();
    }

    bool empty() {
        return stk.empty();
    }
};

// insert from front, remove from back, query function for elements present
template<typename T, class F = function<T(const T& , const T&)>>
struct fqueue { // like min queue
    fstack<T> stk[2];
    F func;

    fqueue(const F &f) : func(f) {
        stk[0] = fstack<T> (f);
        stk[1] = fstack<T> (f);
    }

    fqueue() {
        fqueue(nullptr);
    }

    void push(T add) {
        stk[0].push(add);
    }

    void pop() {
        if (!stk[1].empty()) stk[1].pop();
        else {
            while (!stk[0].empty()) {
                stk[1].push(stk[0].top());
                stk[0].pop();
            }

            stk[1].pop();
        }
    }

    T query() {
        if (stk[1].empty()) return stk[0].query();
        else if (stk[0].empty()) return stk[1].query();
        else return func(stk[0].query() , stk[1].query());
    }

    bool empty() {
        return (stk[0].empty() && stk[1].empty());
    }
};
// Usage :: fqueue<ll> gcdq([&](ll x , ll y){return gcd(x , y);});
/* any function that can be used with seg trees can be used here : min , max , gcd , xor */
void solve() {
    ll n;
    cin >> n;

    vll a(n);
    rep(i, n) cin >> a[i];
    ll k;
    cin >> k;

    fqueue<ll> s([&](ll x, ll y) {return max(x, y);});
    vll dp(n + 1 , -inf);
    dp[0] = a[0];
    rep(i, k) {
        if (i == 0) s.push(dp[i]);
        else {
            dp[i] = a[i] + s.query();
            s.push(dp[i]);
        }
    }

    FOR(i, k, n - 1) {
        dp[i] = a[i] + s.query();
        s.push(dp[i]);
        s.pop();
    }

    debug(dp);

    cout << dp[n - 1] << "\n";
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
