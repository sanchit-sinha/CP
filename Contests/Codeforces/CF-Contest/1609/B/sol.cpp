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


void solve() {
    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<set<ll>> pos(3);

    auto add = [&](ll index) {
        ll x = 0, y = 0, z = 0;
        bool good = 1;
        if (s[index] == 'a') {
            if (index + 2 >= n) good = 0;
            if (s[index] != 'a') good = 0;
            if (s[index + 1] != 'b') good = 0;
            if (s[index + 2] != 'c') good = 0;

            if (good) x = index, y = index + 1, z = index + 2;
        }
        else if (s[index] == 'b') {
            if (index + 1 >= n) good = 0;
            if (index - 1 < 0) good = 0;
            if (s[index - 1] != 'a') good = 0;
            if (s[index] != 'b') good = 0;
            if (s[index + 1] != 'c') good = 0;

            if (good) x = index - 1, y = index, z = index + 1;
        }
        else {
            // sindex == 'c'
            if (index >= n) good = 0;
            if (index - 2 < 0) good = 0;
            if (s[index - 2] != 'a') good = 0;
            if (s[index - 1] != 'b') good = 0;
            if (s[index] != 'c') good = 0;

            if (good) x = index - 2, y = index - 1, z = index;
        }
        if (good) {
            pos[0].insert(x);
            pos[1].insert(y);
            pos[2].insert(z);

            return 1;
        }
        return 0;
    };

    auto sub = [&](ll index) {
        ll x = 0, y = 0, z = 0;
        bool good = 1;
        if (s[index] == 'a') {
            if (index + 2 >= n) good = 0;
            if (s[index] != 'a') good = 0;
            if (s[index + 1] != 'b') good = 0;
            if (s[index + 2] != 'c') good = 0;

            if (good) x = index, y = index + 1, z = index + 2;
        }
        else if (s[index] == 'b') {
            if (index + 1 >= n) good = 0;
            if (index - 1 < 0) good = 0;
            if (s[index - 1] != 'a') good = 0;
            if (s[index] != 'b') good = 0;
            if (s[index + 1] != 'c') good = 0;

            if (good) x = index - 1, y = index, z = index + 1;
        }
        else {
            // sindex == 'c'
            if (index >= n) good = 0;
            if (index - 2 < 0) good = 0;
            if (s[index - 2] != 'a') good = 0;
            if (s[index - 1] != 'b') good = 0;
            if (s[index] != 'c') good = 0;

            if (good) x = index - 2, y = index - 1, z = index;
        }


        auto it1 = pos[0].find(x);
        if (it1 == pos[0].end()) good = 0;

        auto it2 = pos[1].find(y);
        if (it2 == pos[1].end()) good = 0;

        auto it3 = pos[2].find(z);
        if (it3 == pos[2].end()) good = 0;

        if (good) {
            pos[0].erase(it1);
            pos[1].erase(it2);
            pos[2].erase(it3);

            return 1;
        }

        return 0;
    };

    rep(i, n) {
        add(i);
    }

    ll ans = sz(pos[0]);

    while (q--) {
        ll index; char c;
        cin >> index >> c;
        index--;

        char old = s[index];
        if (old == c) cout << ans << "\n";
        else {
            ans -= sub(index);
            s[index] = c;
            ans += add(index);

            cout << ans << "\n";
        }
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
