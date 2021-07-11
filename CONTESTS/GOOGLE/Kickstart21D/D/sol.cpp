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
struct segmenttree {
    vll tree, b, a;
    ll p;
    // ll tree[4 * N], a[N];

    segmenttree(vll &x, ll y) {
        p = y;
        ll n = x.size();

        b = x;
        rep(i, n) {
            b[i] -= (b[i] % p);
        }

        a.resize(n, 0);
        rep(i, n) {
            ll ct = 0ll, temp = b[i];
            if (temp) while (temp % p == 0) temp /= p, ct++;
            a[i] = ct;
        }

        ll m = n + 1;
        tree.resize(4 * m + 11, 0);

        build(1, 0, n -  1);
    }
    ll pull(ll l, ll r) {
        ll p = (l + r); //operation
        return p;
    }
    void build(ll node, ll l, ll r) {
        if (l == r) tree[node] = a[l];
        else {
            ll mid = l + (r - l) / 2;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);

            tree[node] = pull(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void updateTrees(ll node, ll l, ll r, ll index, ll val) {
        if (index > r || index < l) return ;
        if (l == r) a[index] = val , tree[node] = val; //update operation
        else {
            ll mid = l + (r - l) / 2;
            updateTrees(node * 2, l, mid, index, val);
            updateTrees(node * 2 + 1, mid + 1, r, index, val);

            tree[node] = pull(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void update(ll node, ll l, ll r, ll pos, ll val) {
        b[pos] = val;
        b[pos] -= (b[pos] % p);

        ll temp = b[pos], ct = 0ll;

        if (temp) while (temp % p == 0) temp /= p, ct++;
        a[pos] = ct;

        updateTrees(node, l , r, pos, a[pos]);
    }

    ll query(ll node, ll l, ll r, ll start, ll end) {
        if (end < l || start > r) return 0ll; //operation (inf , -inf , 0 ...)
        else if (start <= l && end >= r) return tree[node];
        else {
            ll mid = l + (r - l) / 2;
            ll p1 = query(2 * node, l, mid, start, end);
            ll p2 = query(2 * node + 1, mid + 1, r, start, end);

            return pull(p1, p2); //operation
        }
    }
//build(1,0,n-1) .... query(1,0,n-1,l,r) .... update(1,0,n-1,x,a[x])
};
void solve() {
    ll n, q , p;
    cin >> n >> q >> p;

    vll a(n);
    rep(i, n) cin >> a[i];

    vll a1(n), a2(n), a3(n), a4(n);
    rep(i , n) a1[i] = a[i];
    rep(i , n) a2[i] = a1[i] * a1[i];
    rep(i , n) a3[i] = a2[i] * a1[i];
    rep(i , n) a4[i] = a3[i] * a1[i];

    debug(a1);
    debug(a2);
    debug(a3);
    debug(a4);
    cerr << "\n";

    segmenttree tree1(a1, p);
    segmenttree tree2(a2, p);
    segmenttree tree3(a3, p);
    segmenttree tree4(a4, p);

    debug(tree1.b);
    debug(tree2.b);
    debug(tree3.b);
    debug(tree4.b);
    cerr << "\n";

    while (q--) {
        ll type;
        cin >> type;

        if (type == 1) {
            ll pos, val;
            cin >> pos >> val;

            pos--;

            a[pos] = val;
            ll val1 = val;
            ll val2 = val1 * val;
            ll val3 = val2 * val;
            ll val4 = val3 * val;

            a1[pos] = val1;
            a2[pos] = val2;
            a3[pos] = val3;
            a4[pos] = val4;

            // update trees
            tree1.update(1, 0, n - 1, pos, a1[pos]);
            tree2.update(1, 0, n - 1, pos, a2[pos]);
            tree3.update(1, 0, n - 1, pos, a3[pos]);
            tree4.update(1, 0, n - 1, pos, a4[pos]);

            debug(tree1.b);
            debug(tree1.a);

            debug(tree3.b);
            debug(tree3.a);

        }
        else {
            ll s, l , r;
            cin >> s >> l >> r;
            l--, r--;

            debug(s, l, r);

            ll ans = 0ll;
            if (s == 1) {
                ans = tree1.query(1, 0, n - 1, l, r);
            }
            else if (s == 2) {
                ans = tree2.query(1, 0, n - 1, l, r);
            }
            else if (s == 3) {
                ans = tree3.query(1, 0, n - 1, l, r);
            }
            else if (s == 4) {
                ans = tree4.query(1, 0, n - 1, l, r);
            }

            cout << ans << " ";
        }
    }
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
