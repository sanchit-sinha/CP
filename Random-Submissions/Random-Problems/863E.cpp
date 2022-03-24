
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
bool DEBUGG = 1;
#include "debug.cpp"
#else
bool DEBUGG = 0;
#define debug(...) 42
#define cerr if(false) cerr
#endif

inline ll gcd(ll a, ll b) { if (b == 0) return a; a %= b; return gcd(b, a); }
inline ll max(ll a, ll b) { return ((a > b) ? a : b); }
inline ll min(ll a, ll b) { return ((a > b) ? b : a); }
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 4e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

// nice problem :) 
// saw the editorial 
/*
3
1 7
0 3
5 8
ans is -1
*/

// credits :: tourist 
class segtree {
public:
    struct node {
        long long add = 0; // add: lazy value
        long long mx = 0; // max value in interval
        long long sum = 0; // sum of interval values
        void apply(int l, int r, long long v) { // applying lazy value
            mx += v;
            sum += v * (r - l + 1);
            add += v;
        }
    };

    node unite(const node& a, const node& b) const {
        node res;
        res.mx = min(a.mx, b.mx); // update operation (max,min,gcd)
        res.sum = a.sum + b.sum;
        return res;
    }

    inline void push(int x, int l, int r) {
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        if (tree[x].add != 0) {
            tree[x + 1].apply(l, y, tree[x].add);
            tree[z].apply(y + 1, r, tree[x].add);
            tree[x].add = 0;
        }
    }

    inline void pull(int x, int z) {
        tree[x] = unite(tree[x + 1], tree[z]);
    }

    int n;
    vector<node> tree;

    void build(int x, int l, int r) {
        if (l == r) {
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y);
        build(z, y + 1, r);
        pull(x, z);
    }

    template <typename M>
    void build(int x, int l, int r, const vector<M>& v) {
        if (l == r) {
            tree[x].apply(l, r, v[l]);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y, v);
        build(z, y + 1, r, v);
        pull(x, z);
    }

    node get(int x, int l, int r, int ls, int re) {
        if (ls <= l && r <= re) {
            return tree[x];
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        node res{};
        if (re <= y) {
            res = get(x + 1, l, y, ls, re);
        }
        else {
            if (ls > y) {
                res = get(z, y + 1, r, ls, re);
            }
            else {
                res = unite(get(x + 1, l, y, ls, re), get(z, y + 1, r, ls, re));
            }
        }
        pull(x, z);
        return res;
    }

    template <typename... M>
    void modify(int x, int l, int r, int ls, int re, const M&... v) {
        if (ls <= l && r <= re) {
            tree[x].apply(l, r, v...);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        if (ls <= y) {
            modify(x + 1, l, y, ls, re, v...);
        }
        if (re > y) {
            modify(z, y + 1, r, ls, re, v...);
        }
        pull(x, z);
    }

    int find_first_knowingly(int x, int l, int r, const function<bool(const node&)>& f) {
        if (l == r) {
            return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[x + 1])) {
            res = find_first_knowingly(x + 1, l, y, f);
        }
        else {
            res = find_first_knowingly(z, y + 1, r, f);
        }
        pull(x, z);
        return res;
    }

    int find_first(int x, int l, int r, int ls, int re, const function<bool(const node&)>& f) {
        if (ls <= l && r <= re) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_first_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (ls <= y) {
            res = find_first(x + 1, l, y, ls, re, f);
        }
        if (re > y && res == -1) {
            res = find_first(z, y + 1, r, ls, re, f);
        }
        pull(x, z);
        return res;
    }

    int find_last_knowingly(int x, int l, int r, const function<bool(const node&)>& f) {
        if (l == r) {
            return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[z])) {
            res = find_last_knowingly(z, y + 1, r, f);
        }
        else {
            res = find_last_knowingly(x + 1, l, y, f);
        }
        pull(x, z);
        return res;
    }

    int find_last(int x, int l, int r, int ls, int re, const function<bool(const node&)>& f) {
        if (ls <= l && r <= re) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_last_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (re > y) {
            res = find_last(z, y + 1, r, ls, re, f);
        }
        if (ls <= y && res == -1) {
            res = find_last(x + 1, l, y, ls, re, f);
        }
        pull(x, z);
        return res;
    }

    segtree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }

    template <typename M>
    segtree(const vector<M>& v) {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }

    node get(int ls, int re) {
        assert(0 <= ls && ls <= re && re <= n - 1);
        return get(0, 0, n - 1, ls, re);
    }

    node get(int p) {
        assert(0 <= p && p <= n - 1);
        return get(0, 0, n - 1, p, p);
    }

    template <typename... M>
    void modify(int ls, int re, const M&... v) {
        assert(0 <= ls && ls <= re && re <= n - 1);
        modify(0, 0, n - 1, ls, re, v...);
    }

    // find_first and find_last call all FALSE elements
    // to the left (right) of the sought position exactly once

    int find_first(int ls, int re, const function<bool(const node&)>& f) {
        assert(0 <= ls && ls <= re && re <= n - 1);
        return find_first(0, 0, n - 1, ls, re, f);
    }

    int find_last(int ls, int re, const function<bool(const node&)>& f) {
        assert(0 <= ls && ls <= re && re <= n - 1);
        return find_last(0, 0, n - 1, ls, re, f);
    }
};
// segtree tree_name(size);
// modify(lft, rgt, increment) : range update
// get[left,right] : returns node

void solve() {
    ll n;
    cin >> n;

    vpll v; set<ll> s;
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        v.pb({ x,y });
        s.insert(x), s.insert(y);
    }

    map<ll, ll> id;
    for (auto& x : s) id[x] = id[x - 1] = id[x + 1] = 1;

    ll mx = sz(id), index = 1;
    for (auto& x : id) x.s = index++;

    debug(id);

    segtree pfx(mx + 1);
    rep(i, n) {
        ll l = id[v[i].f], r = id[v[i].s];
        pfx.modify(l, r, 1);
    }

    rep(i, n) {
        ll l = id[v[i].f], r = id[v[i].s];

        pfx.modify(l, r, -1);
        ll res = pfx.get(l, r).mx;
        pfx.modify(l, r, 1);

        if (res) {
            cout << i + 1 << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
#ifdef ERROR
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

ll power(ll x, ll y) { if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex, ll md) { ll ans = 1ll; while (ex > 0) { if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md; } return ans; }

