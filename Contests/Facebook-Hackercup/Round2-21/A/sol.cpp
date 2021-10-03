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

const ll inf = 4e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

ll calc(map<ll, ll> &newm, map<ll, ll> &oldcm, map<ll, ll> &olducm, map<ll, ll> &newcm, map<ll, ll> &newucm) {
    // try oldcm
    map<ll, ll> temp = newm;
    trav(it, temp) {
        ll x = it->f;
        ll len = temp[x];
        rep(i, len) {
            if (oldcm.count(x)) {
                // present
                if (oldcm[x]) {
                    newcm[x]++;
                    newm[x]--;
                    oldcm[x]--;
                }
            }
        }
    }

    // try on olducm
    temp = newm;
    trav(it, temp) {
        ll x = it->f;
        ll len = temp[x];
        rep(i, len) {
            if (olducm.count(x)) {
                // present
                if (olducm[x]) {
                    newucm[x]++;
                    newm[x]--;
                    olducm[x]--;
                }
            }
        }
    }
    // all same done with no cost
    ll autom = 0ll;
    trav(it, olducm) {
        ll x = it->f;
        ll len = olducm[x];
        rep(i, len) autom++;
    }

    ll ans = 0ll;
    trav(it, newm) {
        ll x = it->f;
        ll len = newm[x];
        rep(i, len) {
            ans++;
            newcm[x]++;
        }
    }

    return ans - autom;
}
void solve() {
    ll n, m;
    cin >> n >> m;

    vll s(m);
    rep(i, m) cin >> s[i];

    map<ll, ll> oldm, newm;
    map<ll, ll> oldcm, olducm;
    map<ll, ll> newcm, newucm;

    rep(i, m) oldm[s[i]]++, olducm[s[i]]++;

    vvll a(n, vll(m, 0));
    rep(i, n) {
        rep(j, m) {
            ll x;
            cin >> x;
            a[i][j] = x;
        }
    }

    debug(s);
    debug(a);
// 2 3
// 10 20 20
// 20 10 10
// 30 30 20
    ll dif = 0ll;
    rep(i, n) {
        newm.clear();
        newcm.clear();
        newucm.clear();
        rep(j, m) newm[a[i][j]]++;

        ll val = 0ll;
        debug(newm);
        debug(oldcm);
        debug(olducm);
        debug("sas.........");
        val = calc(newm, oldcm, olducm, newcm, newucm);
        debug(newcm);
        debug(newucm);
        debug(val);
        debug("********");

        oldcm = newcm;
        olducm = newucm;

        dif += val;
    }

    cout << dif << "\n";
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
