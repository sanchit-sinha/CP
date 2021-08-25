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

    vll a(n + 1, 0);
    rep(i, n) cin >> a[i + 1];

    set<ll> not_used;
    rep(i, n) not_used.insert(i + 1);

    map<ll, ll> m;
    rep(i, n) {
        ll x = a[i + 1];
        m[x]++;
        auto it = not_used.find(x);
        if (it != not_used.end()) not_used.erase(it);
    }

    set<ll> main_num;
    for (auto x : m) if (x.s > 1) main_num.insert(x.f);

    debug(not_used, main_num);

    if (sz(main_num) == 1 && m[*main_num.begin()] == 2) {
        vll b(n + 1, 0);
        ll pos = -1, ele = *main_num.rbegin();
        FOR(i, 1, n) {
            ll x = a[i];
            if (m[x]) {
                b[i] = x;
                if (m[x] == 2) pos = i;
                m[x] = 0;
            }
        }

        assert(pos != -1);
        debug(ele, pos, not_used);
        FOR(i, 1, n) {
            if (b[i] == 0) {
                auto it = not_used.begin();
                assert(it != not_used.end());

                ll x = *it;
                if (i == x) {
                    b[i] = x;
                    swap(b[i], b[pos]);
                }
                else b[i] = x;

                not_used.erase(not_used.find(x));
            }
        }

        ll ans = 0ll;
        rep(i, n) ans += (b[i + 1] == a[i + 1]);
        cout << ans << "\n";
        //     rep(i, n) cout << b[i + 1] << " ";
        //     cout << "\n";
    }
    else {
        vll b(n + 1, 0);
        FOR(i, 1, n) {
            ll x = a[i];
            if (m[x]) {
                b[i] = x;
                m[x] = 0;
            }
        }

        debug(not_used);
        debug(b);

        set<ll> x = not_used;
        vll crucial;
        FOR(i, 1, n) {
            if (b[i] == 0) {
                auto it = not_used.rbegin();
                ll x = *it;
                if (i == x) {
                    b[i] = x;
                    crucial.pb(i);
                }
                else b[i] = x;
                not_used.erase(not_used.find(x));
            }
        }

        ll len = sz(crucial);
        rep(i, len / 2) {
            ll x = crucial[i], y = crucial[len - 1 - i];
            swap(b[x], b[y]);
        }

        if (len & 1) {
            ll ele = b[len / 2];
            ll swapele = -1;
            for (auto xx : x) if (xx != ele) swapele = xx;
            ll pos = -1;
            rep(i, n) if (b[i + 1] == swapele) pos = i + 1;

            assert(pos != -1);
            swap(b[pos], b[len / 2]);
        }

        ll ans = 0ll;
        rep(i, n) ans += (b[i + 1] == a[i + 1]);
        cout << ans << "\n";
        // rep(i, n) cout << b[i + 1] << " ";
        // cout << "\n";
    }

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
