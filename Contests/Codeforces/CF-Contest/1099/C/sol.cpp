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
    string s;
    cin >> s;

    ll k;
    cin >> k;

    ll n = sz(s);
    ll index = n;
    ll ct = 0;;
    rep(i , n) {
        if (s[i] == '*') index = i;
        if (s[i] == '?' || s[i] == '*') ct++;
    }

    char c = '?';
    string ans1, ans2;
    FOR(i , 0, min(index, n - 1)) {
        if (s[i] == '?' || s[i] == '*') {
            ans1.pop_back();
        }
        else {
            c = s[i];
            ans1.pb(s[i]);
        }
    }

    FOR(i, index + 1, n - 1) {
        if (s[i] == '?' || s[i] == '*') {
            ans2.pop_back();
        }
        else {
            ans2.pb(s[i]);
        }
    }

    debug(ans1, ans2);
    if (sz(ans1) + sz(ans2) == k) cout << ans1 + ans2 << "\n";
    else if (sz(ans1) + sz(ans2) > k) cout << "Impossible\n";
    else {
        if (index < n) {
            while (sz(ans1) + sz(ans2) != k) {
                ans1.pb(c);
            }

            cout << ans1 + ans2 << "\n";
        }
        else {
            debug(ct);
            if (sz(ans1) + sz(ans2) + ct < k) cout << "Impossible\n";
            else {
                string ans;
                ll req = k - sz(ans1) - sz(ans2);
                debug(req);
                rep(i , n) {
                    assert(s[i] != '*');
                    if (s[i] == '?') {
                        if (req) {
                            req--;
                            continue;
                        }
                        else {
                            ans.pop_back();
                        }
                    }
                    else {
                        ans.pb(s[i]);
                    }
                }

                cout << ans << "\n";
            }
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
