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

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

ll check(string s) {
    ll n = sz(s);
    ll ct = 0ll;
    rep(i, n) {
        if (s[i] == 'X') {
            ct++;
            while (i < n && s[i] != 'O') i++;
            i--;
        }
        else if (s[i] == 'O') {
            ct++;
            while (i < n && s[i] != 'X') i++;
            i--;
        }
    }

    return (max(ct - 1, 0ll));
}

void brute(string s) {
    ll n = sz(s);

    map<ll, ll>m;
    ll ans = 0ll;
    ll x = 0ll, o = 0ll;;
    rep(i, n) {
        ll xx = 0ll;
        map<ll, ll> m1;
        FOR(j, 0 , i - 1) {
            ll val = check(s.substr(j, i - j + 1));
            ans += val;
            xx += val;

            if (val) {
                m[val]++;
                m1[val]++;
            }
            ans %= mod;
        }

        if (s[i] == 'X') {
            x = xx;
        }
        else if (s[i] == 'O') {
            o = xx;
        }

        cout << i << ": " << s[i] << " (" << x << ", " << o << ") \n";
        // cout << " index -> " << i << " " << s[i] << ": " << xx << "\n";
        // trav(it1, m1) {
        //     cout << it1->f << ": " << it1->s << "\n";
        // }
        // cout << "\n";
    }

    // trav(it, m) cout << it->f << ": " << it->s << "\n";
    // cout << "\n";

    cout << ans << "\n";
}
void solve() {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    // brute(s);
    // cout << "***************\n";
    ll x = 0ll, o = 0ll;
    char prev = '?';
    ll lasto = -1, lastx = -1;

    ll ans = 0ll;
    rep(i, n) {
        if (s[i] == 'O') {
            if (prev == 'X' && lastx != -1) {
                o = (2 * x - o) + max(0ll, (lastx - lasto));
                ans += o;
            }
            else ans += o;

            prev = 'O';
            lasto = i;
        }
        else if (s[i] == 'X') {
            if (prev == 'O' && lasto != -1) {
                x = (2 * o - x) + max(0ll, (lasto - lastx));
                ans += x;
            }
            else ans += x;

            prev = 'X';
            lastx = i;
        }
        else {
            if (prev == 'X') ans += x;
            else if (prev == 'O') ans += o;
        }
        ans %= mod;

        // cout << i << ": " << s[i] << " (" << x << ", " << o << ") \n";
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
