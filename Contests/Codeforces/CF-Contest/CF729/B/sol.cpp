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
    ll n , a , b;
    cin >> n >> a >> b;

    // set<ll> s;
    // s.insert(1);
    // set<ll> t;

    // ll ct = 0;
    // while (ct <= 100) {
    //     ll x = *s.begin();
    //     ll y = x * a;
    //     ll z = x + b;
    //     debug(x, y, z);
    //     t.insert(x);

    //     s.insert(y);
    //     s.insert(z);
    //     s.erase(s.find(x));
    //     ct++;
    // }

    // trav(it, t) cout << *it << "\n";
    // cout << "\n";

    set<ll> s;
    if (a == 1) {
        n -= 1;
        if (n % b == 0) cout << "Yes\n";
        else cout << "No\n";
        return;
    }

    FOR(i, 0, 60) {
        ll x = power(a, i);
        if (x > n) break;
        else s.insert(x);
    }

    trav(it , s) {
        ll x = *it;
        ll rem = n - x;
        if (rem >= 0 && rem % b == 0) {
            rem /= b;
            if (rem == 0) {
                cout << "Yes\n";
                return;
            }
            trav(it1, s) {
                ll y = *it1;
                if (rem % y == 0) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }

    cout << "No\n";
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
