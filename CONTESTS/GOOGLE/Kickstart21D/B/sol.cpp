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
    ll n, c;
    cin >> n >> c;
    vpll v;

    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        v.pb({y, x});
    }

    sort(all(v));
    debug(v);
    map<ll, ll>m;
    rep(i, n) {
        ll l = v[i].s, r = v[i].f;
        m[r + 1]--;
        m[l]++;
    }

    map<ll, ll> id;
    ll index = 1;
    for (auto x : m) {
        id[index++]  = x.f;
    }

    debug(m);

    ll len = sz(id) + 1;
    debug(id, sz(id));

    vll pfx(len, 0);
    FOR(i , 1, len - 1) {
        pfx[i] = pfx[i - 1] + m[id[i]];
    }
    debug(pfx);

    map<ll, ll> border;
    rep(i, n) {
        border[v[i].f]++;
        border[v[i].s]++;
    }
    // FOR(i, 1, 4) cerr << i << " : " << id[i] << " -> " << pfx[i] << "\n";

    set<pair<ll, pll >> s;
    FOR(i, 2, sz(id)) {
        ll cur = id[i];
        ll prev = id[i - 1];

        ll x = prev;
        ll y = cur - 1;

        // ll times = pfx[id[i - 1]];
        ll times = pfx[i - 1];
        debug(x, y, times);

        if (border.count(x)) {
            debug(x, times, border[x], times - border[x]);
            s.insert({times - border[x], mp(x, x)});
            x++;
        }
        if (border.count(y)) {
            debug(y, times, border[y], times - border[y]);
            s.insert({times - border[y], mp(y, y)});
            y--;
        }

        if (x <= y) s.insert(mp(times, mp(x, y)));
    }

    debug(border);
    debug(s);
    ll ans = n;
    while (!s.empty() && c) {
        pair<ll, pll> p = *s.rbegin();
        ll times = p.f;
        pll num = p.s;

        if (times == 0) break;

        s.erase(s.find(p));

        ll dif = num.s - num.f + 1;
        ll add = 0ll;

        ll x = 0ll, y = 0ll, z = 0ll;
        if (dif > 0 && c > 0) {
            ll mn = min(c, dif);
            x = times * mn;

            debug(num.f + 1, num.s - 1, times, mn);

            ans += x;
            c -= mn;
        }

        // if ((times - border[num.f]) > 0 && (times - border[num.f] >= times - border[num.s]) && c > 0) {
        //     ll mn = min(c, 1);
        //     if (mn) y = (times - border[num.f]);

        //     debug(c, num.f , y, mn);
        //     ans += y;
        //     c -= mn;
        // }

        // if (num.s != num.f && (times - border[num.s]) > 0 && c > 0) {
        //     ll mn = min(c, 1);
        //     if (mn) z = (times - border[num.s]);
        //     debug(c, num.s , z, mn);

        //     ans += z;
        //     c -= mn;
        // }
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
