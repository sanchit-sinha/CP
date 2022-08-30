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


vector<long long> nearest_smallest_on_left(vector<long long>& A) {
    int n = A.size();
    rep(i, n) A[i] = -A[i];
    stack<pair<long long, long long>> s;
    vector<long long> index(n, -1);

    for (int i = 0; i < n; i++) {
        int x = A[i];
        while (!s.empty() && s.top().first >= x) s.pop();
        if (s.empty()) index[i] = -1;
        else index[i] = s.top().second;

        s.push(make_pair(A[i], i));
    }
    rep(i, n) A[i] = -A[i];

    return index;
}
// reverse(A.begin(), A.end());
// vector<int> right = nearest_smallest_on_left(A);
// reverse(right.begin(), right.end());
// for (int i = 0; i < n; i++) if (right[i] != -1) right[i] = n - 1 - right[i];
// reverse(A.begin(), A.end());

void solve() {
    ll n, q;
    cin >> n >> q;

    vll a(n);
    rep(i, n) cin >> a[i];

    deque<ll> d;
    rep(i, n) d.pb(a[i]);
    debug(d);

    ll pos = 0;
    rep(i, n) if (a[i] == n) pos = i;

    map<ll, vll> timer;
    rep(i, n) {
        if (d.front() == n) break;

        ll a = d.front();
        d.pop_front();
        ll b = d.front();
        d.pop_front();

        if (a < b) swap(a, b);
        timer[a].pb(i + 1);

        d.push_front(a);
        d.push_back(b);
    }

    auto ans = [&](ll x, ll k) {
        if (timer.count(x) == 0) return 0LL;

        auto it = ub(all(timer[x]), k);
        if (it == timer[x].begin()) return 0LL;
        else {
            --it;
            return 1ll * (it - timer[x].begin() + 1);
        }
    };

    debug(a);
    if (DEBUGG) {
        for (auto& x : timer) debug(x.f, x.s);
    }

    ll start = (pos);
    while (q--) {
        ll index, k;
        cin >> index >> k;
        --index;

        if (k > start) {
            if (a[index] == n) cout << (k - start + (timer.count(a[index]) == 1)) << "\n";
            else {
                cout << ans(a[index], k) << "\n";
            }
        }
        else {
            cout << ans(a[index], k) << "\n";
        }
    }
    cout << "\n";
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
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) { if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex, ll md) { ll ans = 1ll; while (ex > 0) { if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md; } return ans; }

