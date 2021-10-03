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

const ll inf = 4e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 8000011;
vll v[N];
map<ll, ll> tot;
ll n;
ll f[N];
ll ans = 0ll;
bool vis[N];

map<ll, ll> dfs(ll node) {
    vis[node] = 1;
    bool enter = 0;

    map<ll, ll> nodem;
    for (auto child : v[node]) {
        if (!vis[child]) {
            enter = 1;
            map<ll, ll> childm = dfs(child);

            if (sz(childm) == 0) ans++;
            else {
                trav(it, childm) {
                    ll x = it->f;
                    ll rem = it->s;

                    // assert(rem);
                    if (nodem[x]) {
                        nodem[x] = nodem[x] + rem - tot[x];
                    }
                    else {
                        nodem[x] = rem;
                    }

                    if (nodem[x] == 0) {
                        auto itf = nodem.find(x);
                        if (itf != nodem.end()) {
                            nodem.erase(itf);
                        }
                    }
                }
            }
        }
    }

    ll x = f[node];
    auto it = nodem.find(x);

    if (it == nodem.end()) nodem[x] = tot[x] - 1;
    else nodem[x]--;

    if (nodem[x] == 0) {
        auto itf = nodem.find(x);
        if (itf != nodem.end()) {
            nodem.erase(itf);
        }
    }
    debug("after", node, x, nodem);
    return nodem;
}
void solve() {
    // / /clear
    ans = 0ll;
    rep(i, n + 1) {
        vis[i] = 0;
        f[i] = 0;
        v[i].clear();
    }
    tot.clear();

    cin >> n;
    rep(i, n - 1) {
        ll x,  y;
        cin >> x >> y;

        v[x].pb(y);
        v[y].pb(x);
    }


    rep(i, n) {
        cin >> f[i + 1];
        tot[f[i + 1]]++;
    }

    FOR(i, 1, n) cerr << f[i] << " ";
    cerr << "\n";

    debug(tot);
    map<ll, ll> anss = dfs(1);
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
        cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
