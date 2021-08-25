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
const ll N = 1e5 + 11;
ll n, k, arrival[N], load[N], departure[N];
vector<pair<pll, ll>> v;

ll a[N]; // current server time: time taken by a server
ll server[N]; // ith request is processed by server[i]

// ll tree[4 * N];
// ll pull(ll l, ll r) {
//     ll p = min(l, r); //operation
//     return p;
// }

ll tree[4 * N];
//build(1,0,n-1) .... query(1,0,n-1,l,r) .... update(1,0,n-1,x,a[x])
ll pull(ll left, ll right) {
    return min(left, right);
}
// void build(ll node, ll l, ll r) {
//     if (l == r) tree[node] = a[l];
//     else {
//         ll mid = l + (r - l) / 2;
//         build(2 * node, l, mid);
//         build(2 * node + 1, mid + 1, r);

//         tree[node] = pull(tree[node * 2], tree[node * 2 + 1]);
//     }
// }

void build(ll node, ll l, ll r) {
    if (l == r) {
        tree[node] = a[l];
        return;
    }
    ll mid = l + (r - l) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    tree[node] = pull(tree[node * 2], tree[node * 2 + 1]);
    return;
}
// ll query(ll node, ll l, ll r, ll start, ll end) {
//     if (end < l || start > r) return LLONG_MAX; //operation (inf , -inf , 0 ...)
//     else if (start <= l && end >= r) return tree[node];
//     else {
//         ll mid = l + (r - l) / 2;
//         ll p1 = query(2 * node, l, mid, start, end);
//         ll p2 = query(2 * node + 1, mid + 1, r, start, end);

//         return pull(p1, p2); //operation
//     }
// }

ll query(ll node, ll l, ll r, ll start, ll end) {
    if (start > r || end < l) return inf;
    if (start <= l && end >= r) return tree[node];

    ll mid = l + (r - l) / 2;
    ll q1 = query(node * 2, l, mid, start, end);
    ll q2 = query(node * 2 + 1, mid + 1, r, start, end);

    return pull(q1, q2);
}
void update(ll node, ll l, ll r, ll index, ll val) {
    if (index > r || index < l) return;
    if (l == r) a[index] = val, tree[node] = val;
    else {
        ll mid = l + (r - l) / 2;
        update(node * 2, l, mid, index, val);
        update(node * 2 + 1, mid + 1, r, index, val);

        tree[node] = pull(tree[node * 2], tree[node * 2 + 1]);
    }
}

// void update(ll node, ll l, ll r, ll index, ll val) {
//     if (index > r || index < l) return ;
//     if (l == r) a[index] = val , tree[node] = val; //update operation
//     else {
//         ll mid = l + (r - l) / 2;
//         update(node * 2, l, mid, index, val);
//         update(node * 2 + 1, mid + 1, r, index, val);

//         tree[node] = pull(tree[node * 2], tree[node * 2 + 1]);
//     }
// }
void solve() {
    cin >> k >> n;
    rep(i, n) cin >> arrival[i];

    cin >> n;
    rep(i, n) cin >> load[i];
    rep(i, n) departure[i] = arrival[i] + load[i] - 1;
    rep(i, n) v.pb(mp(mp(arrival[i], departure[i]), i));
    sort(all(v));

    rep(i, k) a[i] = 0;
    build(1, 0, k - 1);
    rep(i, n) server[i] = -3;

    int prev = 0;
    rep(i, n) {
        ll l = v[i].f.f, r = v[i].f.s, index = v[i].s;
        int server_used = -1;
        if (i == 0) {
            server_used = 0;
            a[0] = r;
            server[index] = 0;
            update(1, 0, k - 1, 0, r);
        }
        else {
            ll lo = prev + 1, hi = k - 1, ans = -1;
            while (lo <= hi) {
                ll mid = lo + (hi - lo) / 2;
                ll pfxmn = query(1, 0, k - 1, prev + 1, mid);
                // if (i == 4 || i >= 5) debug(i, prev, mid, pfxmn);
                if (pfxmn <= l) {
                    hi = mid - 1;
                    ans = mid;
                }
                else lo = mid + 1; // pfxmn > r
            }

            if (ans == -1) {
                lo = 0, hi = prev;
                while (lo <= hi) {
                    ll mid = lo + (hi - lo) / 2;
                    ll pfxmn = query(1, 0, k - 1, 0, mid);
                    // if (i == 4 || i >= 5) debug(i, prev, mid, pfxmn);
                    if (pfxmn <= l) {
                        hi = mid - 1;
                        ans = mid;
                    }
                    else lo = mid + 1; // pfxmn > r
                }
            }

            if (ans != -1) {
                server_used = ans;
                a[ans] = r;
                server[index] = server_used;
                update(1, 0, k - 1, ans, r);
            }
            else server_used = prev, server[index] = -2;
        }

        // if (i == 4 || i >= 5) debug(i, server_used, l , r);
        // cerr << "SERVER TIMINGS: ";
        // rep(j, n) cerr << a[j] << " ";
        // cerr << "\n";

        // cerr << "SERVERS ASSIGNED: ";
        // rep(j, n) cerr << server[j] + 1 << " ";
        // cerr << "\n\n";

        prev = server_used;
    }

    rep(i, n) cerr << server[i] << " ";
    cerr << "\n";
    // return;

    vll servercost(k + 1, 0);
    ll mx = 0ll;
    rep(i, n) {
        if (server[i] >= 0) servercost[server[i]] += load[i];
        mx = max(mx, servercost[server[i]]);
    }
    debug(mx);
    vll ans;
    rep(i, sz(servercost)) {
        ll x = servercost[i];
        if (x == mx) ans.pb(i + 1);
    }

    sort(all(ans));
    debug(ans);
    for (auto &x : ans) cout << x << "\n";
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
