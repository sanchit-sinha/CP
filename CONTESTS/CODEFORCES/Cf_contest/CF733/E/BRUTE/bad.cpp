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

// 1 indexed .. p[i] is the length of the longest proper prefix of the substring s[0 … i - 1] which is also a suffix of this substring
vector<ll> LPS(string &s) {
    int n = (int)s.length();
    vector<ll> p(n + 1);
    p[0] = 0; p[1] = 0;
    int j;
    for (int i = 2 ; i <= n ; i++) {
        j = p[i - 1];
        while (j > 0 && s[j] != s[i - 1]) j = p[j]; // p[p[j]] gives second largest prefix of the substring s[0 … i - 1]
        if (s[j] == s[i - 1]) j++;
        p[i] = j;
    }
    return p;
}

string brute(string x) {
    ll n = sz(x);
    sort(all(x));

    ll ans = inf;
    string s;

    do {
        vll v = LPS(x);
        ll mx = 0ll;
        rep(i, sz(v)) mx = max(mx , v[i]);

        // m[mx].pb(x);
        if (mx < ans) {
            ans = mx;
            s = x;
        }

    } while (next_permutation(all(x)));


    return s;
}
void solve() {
    string s;
    cin >> s;

    ll n = sz(s);

    // if (n <= 4) {
    if (1) {
        string ans = brute(s);
        cout << " brute \n" << ans << "\n";
        // return;
    }

    map<ll, ll> m;
    rep(i, n) m[s[i] - 'a']++;

    string t = s;
    sort(all(t));

    ll unique = 0ll;
    for (auto x : m) if (x.s == 1) unique++;
    debug(unique);

    if (sz(m) == n || sz(m) == 1) {
        cerr << "1\n";
        // 1: all distinct : abcde
        cout << t << "\n";
    }
    else if (unique) {
        cerr << "2\n";
        // exactly 1 character occurs one time // aabbcccddgff => ga..b..c..s
        char c = -1;
        for (auto x : m) {
            if (x.s == 1) {
                c = (char)('a' + x.f);
                break;
            }
        }

        string ans;
        ans.pb(c);
        rep(i, n) if (t[i] != c) ans.pb(t[i]);
        cout << ans << "\n";
    }
    else {
        cerr << "3\n";
        ll ctsmallest = (m.begin()->s);
        ll rem = n - ctsmallest;
        if (rem >= ctsmallest - 2) {
            // aaabbbbbcccc : aabababacabacabbcc
            string ans;
            char smallest = (char)(m.begin()->f + 'a');

            ans.pb(smallest);
            ans.pb(smallest);

            FOR(i, ctsmallest, n - 1) {
                ans.pb(t[i]);
                if (ctsmallest > 2) {
                    ans.pb(smallest);
                    ctsmallest--;
                }
            }

            cout << ans << "\n";
        }
        else {
            if (sz(m) == 2) {
                cerr << "4\n";
                // abbbbbbbaaaaa
                char smallest = (char)(m.begin()->f + 'a');
                string ans;
                ans.pb(smallest);

                char largest = (char)(m.rbegin()->f + 'a');
                rep(i, m.rbegin()->s) ans.pb(largest);
                rep(i, m.begin()->s - 1) ans.pb(smallest);

                cout << ans << "\n";
            }
            else {
                cerr << "5\n";
                //abaaaaacbbbcccc
                auto it = m.begin();
                char smallest1 = (char)(it->f + 'a');
                ll ctsmallest1 = it->s;

                it++;
                char smallest2 = (char)(it->f + 'a');
                ll ctsmallest2 = it->s;

                it++;
                char smallest3 = (char)(it->f + 'a');
                ll ctsmallest3 = it->s;


                string ans;
                ans.pb(smallest1); // a
                ctsmallest1--;

                ans.pb(smallest2); // ab
                ctsmallest2--;

                while (ctsmallest1) ans.pb(smallest1), ctsmallest1--; // abaaa

                ans.pb(smallest3); // abaaaac
                ctsmallest3--;

                ans.pb(smallest2); // abaaaacb
                ctsmallest2--;

                m[smallest1] = ctsmallest1;
                m[smallest2] = ctsmallest2;
                m[smallest3] = ctsmallest3;

                for (auto x : m) {
                    rep(j , x.s) ans.pb((char)(x.f + 'a'));
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
