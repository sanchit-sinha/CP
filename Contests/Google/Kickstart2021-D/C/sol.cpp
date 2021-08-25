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
    ll n , m;
    cin >> n >> m;

    vpll v;
    multiset<pll> s;
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        v.pb({x, y});
        s.insert({y, x});
    }

    vll st(m , 0);
    rep(i, m) cin >> st[i];

    vll ans(m, 0);
    rep(i, m) {
        ll x = st[i];
        pll p = mp(x, inf);

        ll l1 = -1, r1 = -1, l2 = -1, r2 = -1;

        auto it = s.lb(p);
        if (it != s.end()) {
            l2 = it->s, r2 = it->f;
        }
        if (it != s.begin()) {
            it--;
            l1 = it->s, r1 = it->f;
        }

        if (r1 == x) {
            ans[i] = r1;
            // cout << r1 << " ";
            pll pp = mp(r1, l1);
            s.erase(s.find(pp));

            r1--;
            if (r1 >= l1) {
                pp = mp(r1, l1);
                s.insert(pp);
            }
        }
        else if (l2 <= x && x <= r2) {
            ans[i] = x;
            // cout << x << "\n";
            pll pp = mp(r2, l2);
            s.erase(s.find(pp));

            if (x - 1 >= l2) {
                pp = mp(x - 1, l2);
                s.insert(pp);
            }

            if (r2 >= x + 1) {
                pp = mp(r2, x + 1);
                s.insert(pp);
            }
        }
        else {
            ll close1 = abs(r1 - x);
            ll close2 = abs(l2 - x);

            if (r1 != -1 && close1 <= close2) {
                ans[i] = r1;
                // cout << r1 << " ";
                pll pp = mp(r1, l1);
                s.erase(s.find(pp));

                r1--;
                if (r1 >= l1) {
                    pp = mp(r1, l1);
                    s.insert(pp);
                }
            }
            else {
                ans[i] = l2;
                // cout << l2 << " ";
                pll pp = mp(r2, l2);
                s.erase(s.find(pp));

                l2++;
                if (r2 >= l2) {
                    pp = mp(r2, l2);
                    s.insert(pp);
                }
            }
        }

    }

    rep(i , m) cout << ans[i] << " ";
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
