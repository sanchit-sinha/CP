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
#define pll                 pair<ll, ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (ll)((c).size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin(); a != x.end(); a++)
#define rep(i, n)           for(ll i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(ll i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(ll i = (b); i >= (a); i--)

#ifdef LOCAL
bool DEBUG = 1;
#include "debug.cpp"
#else
bool DEBUG = 0;
#define debug(...) 42
#define cerr if(false) cerr
#endif

inline ll gcd(ll a, ll b) {if (b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a, ll b) {return ((a > b) ? a : b);}
inline ll min(ll a, ll b) {return ((a > b) ? b : a);}
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 4e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

void convert(vll &a, ll i, ll j, ll k, map < ll, set <ll>> &id) {
        ll ti = a[i], tj = a[j], tk = a[k];

        auto iti = id[a[i]].find(i);
        if (iti != id[a[i]].end()) id[a[i]].erase(iti);

        auto itj = id[a[j]].find(j);
        if (itj != id[a[j]].end()) id[a[j]].erase(itj);

        auto itk = id[a[k]].find(k);
        if (itk != id[a[k]].end()) id[a[k]].erase(itk);

        a[i] = tk, a[j] = ti, a[k] = tj;

        id[a[i]].insert(i);
        id[a[j]].insert(j);
        id[a[k]].insert(k);

        debug(i, j, k);
        debug("after", a);
}
void solve() {
        ll n;
        cin >> n;

        vll a(n);
        rep(i, n) cin >> a[i];

        vll b = a;
        sort(all(b));

        map<ll, set<ll>> id;
        rep(i, n) id[a[i]].insert(i);

        debug("Sorted", b);
        rep(i, n) { // invariant: sorted till i at ith iteration
                if (a[i] != b[i]) {
                        ll ii = i, jj = i + 1, kk = -1;

                        auto it = id[b[i]].ub(i);
                        if (it != id[b[i]].begin()) {
                                // > 1 time dealing with b[i] : 1st , i , gr i
                                ii = *id[b[i]].begin();
                                jj = i;
                                kk = *it;

                                if (ii >= n || jj >= n || kk >= n) break;
                                else {
                                        convert(a, ii, jj, kk, id);
                                }
                        }
                        else  {
                                // first time dealing with b[i] : i, x(!i , !gr x), gr i
                                kk = *it, jj = i + 1, ii = i;
                                if (jj == kk) jj = i + 2;

                                if (ii >= n || jj >= n || kk >= n) break;
                                else {
                                        convert(a, ii, jj, kk, id);
                                }
                        }
                }
        }

        debug(a);

        if (b != a) cout << "NO\n";
        else cout << "YES\n";
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
