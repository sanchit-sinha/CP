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


void solve() {
    ll n;
    cin >> n;

    vll a(n);
    vll b(n);

    multiset<pll, greater<pll>> abig;
    multiset<pll> bsmall;

    rep(i , n) cin >> a[i] >> b[i];

    rep(i , n) {
        abig.insert(mp(a[i] , i));
        bsmall.insert(mp(b[i] , i));
    }

    debug(abig);
    debug(bsmall);

    ll cur_steps = 0 ;
    ll ans = 0ll;
    while (!bsmall.empty()) {
        ll req_steps = (bsmall.begin()) -> f;
        ll index = (bsmall.begin()) -> s;

        ll to_eat = a[index];
        if (cur_steps >= req_steps) {
            cur_steps += a[index];
            ans += a[index] * 1;

            debug("1" , index, a[index]);
            auto itb = bsmall.find(mp(b[index], index));
            if (itb != bsmall.end()) bsmall.erase(itb);

            auto ita = abig.find(mp(a[index], index));
            if (ita != abig.end()) abig.erase(ita);

            a[index] = 0;
        }
        else {
            ll eat = abig.begin() -> f;
            ll index = abig.begin() -> s;

            ll req = req_steps - cur_steps;
            ll choose = min(req, eat);

            eat -= choose;
            cur_steps += choose;
            ans += 2 * choose;

            debug("2" , index, req_steps, choose, a[index]);
            if (eat == 0) {
                auto itb = bsmall.find(mp(b[index], index));
                if (itb != bsmall.end()) bsmall.erase(itb);

                auto ita = abig.find(mp(a[index], index));
                if (ita != abig.end()) abig.erase(ita);

                a[index] = 0;
            }
            else {
                auto ita = abig.find(mp(a[index], index));
                if (ita != abig.end()) abig.erase(ita);

                a[index] -= choose;
                abig.insert({a[index], index});
            }
        }
    }

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
