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

const ll N = 4e5 + 11;
ll n, k, szz[N];
set<ll> v[N];
map<ll, set<ll>> szchild;

void solve() {
    // clear
    rep(i, n + 1) {
        szz[i] = 0;
        v[i].clear();
    }
    szchild.clear();

    cin >> n >> k;
    rep(i, n - 1) {
        ll x, y;
        cin >> x >> y;

        v[x].insert(y), v[y].insert(x);
    }


    set<ll> rem;
    rep(i, n) rem.insert(i + 1);
    FOR(i, 1, n) {
        ll x = sz(v[i]);
        szz[i] = x, szchild[x].insert(i);
    }

    FOR(i, 1, k) {
        debug(rem);
        if (sz(rem) == 0) break;

        // remove 0,1 child nodes
        trav(it, szchild[0]) rem.erase(rem.find(*it)), szz[*it] = 0, v[*it].clear();
        trav(it, szchild[1]) rem.erase(rem.find(*it)), szz[*it] = 0;

        // remove 1 child nodes and update their parent
        set<ll> pr; map<ll, ll> oldsz;
        trav(it, szchild[1]) {
            ll node = *it; ll prr = *v[node].begin();
            auto itp = rem.find(prr);
            if (itp != rem.end()) {
                v[prr].erase(v[prr].find(node));

                if (!oldsz.count(prr)) oldsz[prr] = szz[prr];
                szz[prr]--; pr.insert(prr);
            }
        }

        szchild[0].clear();
        szchild[1].clear();

        // update parent
        trav(it, pr) {
            ll prr = *it, os = oldsz[prr], ns = szz[prr];
            szchild[os].erase(szchild[os].find(prr));
            szchild[ns].insert(prr);
        }
    }

    cout << sz(rem) << "\n";
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