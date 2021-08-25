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

const ll N = 22;
#define NCR
ll ncr[N][N];
void factorial() {
    // (n r) = (n-1 r-1) + (n-1 r)
    FOR(i, 0, N - 1) {
        FOR(j, 0, N - 1) {
            if (i == 0 && j == 0) ncr[0][0] = 1;
            else if (i == 0) ncr[i][j] = 0;
            else if (j == 0) ncr[i][j] = 1;
            else ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
        }
    }
}
void find_permutation(vll &permutation, ll a, ll b, ll n, ll k) { // k : 1 indexed
    if (a == 0) {
        rep(i, b) permutation.pb(1);
        return;
    }
    if (b == 0) {
        rep(i, a) permutation.pb(0);
        return;
    }
    if (k == 0) {
        rep(i, b) permutation.pb(1);
        rep(i, a) permutation.pb(0);
        return;
    }

    ll moves_placing_smallest = 0;
    ll element = -1;

    moves_placing_smallest = ncr[n - 1][a - 1];
    if (moves_placing_smallest < k) element = 1, k -= moves_placing_smallest, b--;
    else element = 0, a--;

    // // place beta'th position if, beta * moves_placing_smallest >= k (considering all unique)
    // ll first_place = (k + moves_placing_smallest - 1) / moves_placing_smallest;  // first place : 1 indexed
    // if (first_place == 1) element = 0, a--;
    // else element = 1, b--;

    // 0 0 1 1
    // 0 1 0 1
    // 0 1 1 0
    debug(permutation, a, b, k, moves_placing_smallest);
    debug(element);
    if (element != -1) {
        permutation.pb(element);
        find_permutation(permutation, a, b, n - 1, k);
    }
    return ;
}
void solve() {
    ll x , y , k;
    cin >> x >> y >> k;

    debug(ncr[5][2], ncr[6][3]);

    vll ans;
    find_permutation(ans, x, y, x + y, k + 1);
    for (auto x : ans) (x == 0) ? ( cout << "H") : (cout << "V");
    cout << "\n";
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
