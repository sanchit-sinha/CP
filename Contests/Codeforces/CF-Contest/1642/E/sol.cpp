#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include "bits/stdc++.h"
using namespace __gnu_pbds;
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
#define getT(x,c)           get<x>(c)
#define trav(a,x)           for(auto a = (x).begin(); a != (x).end(); a++)
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

const ll N = 2e5 + 3;
ll tr[4 * N], a[N];
ll pull(ll l, ll r) {
    ll p = max(l, r); //operation
    return p;
}
void build(ll node, ll l, ll r) {
    if (l == r) tr[node] = a[l];
    else {
        ll mid = l + (r - l) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        tr[node] = pull(tr[node * 2], tr[node * 2 + 1]);
    }
}
void update(ll node, ll l, ll r, ll index, ll val) {
    if (index > r || index < l) return ;
    if (l == r) a[index] = val , tr[node] = val; //update operation
    else {
        ll mid = l + (r - l) / 2;
        update(node * 2, l, mid, index, val);
        update(node * 2 + 1, mid + 1, r, index, val);

        tr[node] = pull(tr[node * 2], tr[node * 2 + 1]);
    }
}
ll query(ll node, ll l, ll r, ll start, ll end) {
    if (end < l || start > r) return 0ll; //operation (inf , -inf , 0 ...)
    else if (start <= l && end >= r) return tr[node];
    else {
        ll mid = l + (r - l) / 2;
        ll p1 = query(2 * node, l, mid, start, end);
        ll p2 = query(2 * node + 1, mid + 1, r, start, end);

        return pull(p1, p2); //operation
    }
}
//build(1,0,n-1) .... query(1,0,n-1,l,r) .... update(1,0,n-1,x,a[x])

#define opll tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define oll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

/*  order_of_key(k) : number of elements strictly lesser than k
    find_by_order(k) : counting from zero it returns the k-th largest or smallest element in the set - returns iterator  */


void solve() {
    ll n, q;
    cin >> n >> q;

    oll st;
    rep(i, n) st.insert(i + 1);

    vll timer(n + 1, inf), state(n + 1, -1);
    vpll qry; vector<array<ll, 3>> one;

    FOR(i, 1, q) {
        ll t; cin >> t;
        if (t == 0) {
            ll l, r, x;
            cin >> l >> r >> x;

            if (x == 0) { // no sick :: they get fixed
                vll er;
                auto it = st.lb(l);
                for (; it != st.end(); it++) {
                    if (*it > r) break;
                    er.pb(*it);

                    state[*it] = 1; // safe
                    timer[*it] = min(timer[*it], i);
                    update(1, 0, n - 1, *it, timer[*it]);
                }

                for (auto &xx : er) st.erase(st.find(xx));
            }
            else {
                one.pb({i, l, r});
            }
        }
        else {
            ll index; cin >> index;
            qry.pb({index, i});
        }
    }

    debug(state);
    debug(timer);
    for (auto &x : one) { // update atleast ones using fixed elements
        ll time = x[0], l = x[1], r = x[2];

        ll numEle = st.order_of_key(r + 1) - st.order_of_key(l);
        if (numEle == 1) {
            ll ele = *st.lb(l);

            ll timeothers = query(1, 0, n - 1, l, r);
            ll timele = max(timeothers, time);

            timer[ele] = min(timer[ele], timele);
            state[ele] = 0; // sick
        }
    }

    debug(state);
    debug(timer);
    for (auto &x : qry) {
        ll i = x.s, index = x.f;
        if (state[index] == -1 || timer[index] >= i) cout << "N/A" << "\n";
        else {
            if (state[index] == 1) cout << "NO\n";
            else cout << "YES\n";
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
