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
#define sz(c)               (int)(c.size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

string to_string(string s) {return '"' + s + '"';} string to_string(const char* s) {return to_string((string) s);} string to_string(bool b) {return (b ? "true" : "false");} template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";} template <typename A>string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", ";} first = false; res += to_string(x);} res += "}"; return res;} void debug_out() { cerr << "\n"; } template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n"; debug_out(T...);}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
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

// uff
void erase(set<ll> &s , ll x , set<ll> &t , ll y) {
    if (x != -1) {
        auto it1 = s.find(x);
        if (it1 != s.end()) s.erase(it1);
    }

    if (y != -1) {
        auto it2 = t.find(y);
        if (it2 != t.end()) t.erase(it2);
    }
}
void solve() {
    ll n;
    cin >> n;

    vll a(n + 11);
    FOR(i , 1 , n) cin >> a[i];

    set<ll> cangive , cantake;
    FOR(i , 1 , n) cantake.insert(i);

    FOR(i , 1 , n) {
        ll giver = i;
        ll taker = a[i];

        if (taker) {
            // can't take any more
            erase(cangive , -1 , cantake , taker);
        }
        else { // taker = 0
            cangive.insert(i); // can give
        }
    }

    vll same , samectr;
    ll ele = -1;
    trav(it , cangive) {
        ll gives = *it;

        auto it2 = cantake.find(gives); // taker == giver
        if (it2 != cantake.end()) same.pb(*it), samectr.pb(*it);
    }

    sort(all(same));

    sort(all(samectr));
    reverse(all(samectr));

    if (sz(same) & 1) {
        swap(samectr[sz(same) / 2] , samectr[0]);
    }

    rep(i , sz(same)) {
        ll gives = same[i];
        ll takes = samectr[i];

        if (gives != takes) {
            a[gives] = takes;
            erase(cangive , gives , cantake , takes);
        }
        else ele = gives;
    }

    ll taker = ele;
    if (taker != -1) {
        if (*cangive.begin() != taker) {
            ll giver = *cangive.begin();
            a[giver] = taker;

            erase(cangive , giver , cantake , taker);

        }
        else if (*cangive.rbegin() != taker) {
            ll giver = *cangive.rbegin();
            a[giver] = taker;

            erase(cangive , giver , cantake , taker);
        }
    }

    while (!cantake.empty()) {
        ll takermn = *cantake.begin();
        ll givermn = *cangive.begin();

        if (takermn == givermn) givermn = *cangive.rbegin();

        a[givermn] = takermn ;
        erase(cangive , givermn , cantake , takermn);
    }

    FOR(i , 1 , n) cout << a[i] << " ";
    cout << "\n";


}

int main() {
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
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        // cout << "\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}