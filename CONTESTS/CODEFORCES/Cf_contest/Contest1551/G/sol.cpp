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

ll poww(ll x, ll ex, ll mod) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans *= x, ans %= mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }

    return ans;
}

// gives number of even and odd pallindromes centered at i
vector<vector<long long>>  manacher(string s) {
    ll n = (int)s.size();
    string t; t.push_back('@');
    t.push_back('#');
    for (int i = 0 ; i < n ; i++) t.push_back(s[i]) , t.push_back('#');
    t.push_back('?');

    n = (int)t.size();
    vector<long long> P(n + 1 , 0);
    for (int i = 0 , c = 0 , r = 0 ; i < n ; i++) {
        P[i] = (i > r) ? (0) : (min(P[c + c - i] , r - i));
        while (t[i - P[i] - 1] == t[i + P[i] + 1]) P[i]++;

        if (i + P[i] > r) c = i , r = i + P[i];
    }

    vector<vector<long long>> ans;
    vector<long long> odd , even;

    for (int i = 1 ; i < n - 1 ; ++i) {
        if (t[i] == '#') even.push_back(P[i] / 2);
        else odd.push_back((P[i] + 1) / 2);
    }

    ans.push_back(even);
    ans.push_back(odd);

    return ans;
}
vector<vector<ll>> manacher2(string s) {
    ll n = sz(s);
    string t;
    t.pb('@');
    t.pb('#');
    rep(i, n) t.pb(s[i]), t.pb('#');
    t.pb('?');

    n = sz(t);
    vll P(n + 1, 0);
    for (int i = 0, c = 0, r = 0 ; i < n; i++) {
        P[i] = (i > r) ? (0) : (min(P[c + c - i], r - i));
        while (t[i - P[i] - 1] == t[i + P[i] + 1]) P[i]++;
        if (i + P[i] > r) c = i, r = i  + P[i];
    }

    vvll ans;
    vll even, odd;

    FOR(i, 1, n - 2) {
        if (t[i] == '#') even.pb(P[i] / 2);
        else odd.pb((P[i] + 1) / 2);
    }

    ans.pb(even);
    ans.pb(odd);
    return ans;
}

vll LPS2(string &s) {
    ll n = sz(s);
    vll P(n + 1, 0);

    int j;
    FOR(i, 2, n) {
        j = P[i - 1];
        while (j > 0 && s[j] != s[i - 1]) j = P[j];
        if (s[j] == s[i - 1]) j++;
        P[i] = j;
    }

    return P;
}
void solve() {
    cout << poww(3, 4, mod) << "\n";

    string s = "baabaa";
    vvll ans = manacher2(s);
    cout << s << "\n";
    rep(i , sz(ans)) {
        cout << i << " : ";
        rep(j, sz(ans[i])) cout << ans[i][j] << " ";
        cout << "\n";
    }

    vll x = LPS2(s);
    FOR(i, 1, sz(x) - 1) cout << x[i] << " ";
    cout << "\n";
}
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
const ll N  = 11;
ll sz[N];
ll parent[N];
void make_set(ll node) {
    parent[node] = node;
    sz[node] = 1;
}
ll find_set(ll a) {
    if (a == parent[a]) return a;
    return parent[a] = find_set(parent[a]);
}
void union_set(ll a , ll b) {
    ll p1 = find_set(a);
    ll p2 = find_set(b);
    if (p1 != p2) {
        if (sz[p2] > sz[p1]) swap(p1 , p2);
        parent[p2] = p1;
        sz[p1] += sz[p2];
    }
}


bool vis[N];
void dij(ll node, ll n, vll &dis, vector<vpll> &v) {
    set<pll> s;
    FOR(i, 1, n) {
        if (i == node) continue;
        else {
            dis[i] = LLONG_MAX;
            s.insert(mp(dis[i], i));
        }
    }
    s.insert(mp(dis[node], node));

    while (!s.empty()) {
        ll from = s.begin()->second;
        vis[from] = 1;
        s.erase(s.begin());
        for (auto child : v[from]) {
            ll to = child.first;
            ll len = child.second;

            if (!vis[to]) {
                if (dis[from] + len < dis[to]) {
                    s.erase(s.find(mp(dis[to], to)));
                    dis[to] = dis[from] + len;
                    s.insert(mp(dis[to], to));
                }
            }
        }
    }
}

ll a[N][N], dp[N][N];
// shortest path b/w pair of nodes in directed/undirected graph with any weights in O(n^3)
void Floyd_Warshall(ll n) {
    FOR(k , 1 , n) {
        FOR(i , 1 , n) {
            FOR(j , 1 , n) {
                if (dp[i][k] < inf && dp[k][j] < inf) {
                    dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
                }
            }
        }
    }

    // finding pairs having negative cycle
    FOR(k , 1 , n) {
        FOR(i , 1 , n) {
            FOR(j , 1 , n) {
                if (dp[k][j] < inf &&  dp[j][j] < 0 && dp[j][i] < inf) {
                    dp[i][j] = -inf;
                }
            }
        }
    }
}

#define SIEVE
const ll mX = N;
bool prime[mX + 11];
void sieve() {
    memset(prime, true, sizeof(prime));
    for (ll p = 2 ; p * p <= mX ; p++) {
        if (prime[p] == true) {
            for (ll i = p * p ; i <= mX; i += p) prime[i] = false;
        }
    }
}
// note that the complexity is sqrt(n)*log(n)
// can't store all prime numbers directly(need to iterate all numbers : nlog(n))


#define SIEVE
// finding shortest prime factor in O(nlog(n))
const ll mX = N;
ll spf[mX];
void sieve () {
    spf[1] = 1;
    for (ll i = 2 ; i < mX ; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            for (ll j = 1ll * i * i ; j < mX ; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
}

long long n , l , in[N] , out[N];
long long timer = 0;
vector<long long> v[N] , up[N];

void dfs(long long node , long long pr) {
    in[node] = ++timer;

    up[node][0] = pr;
    for (int i = 1 ; i <= l ; i++) {
        up[node][i] = up[up[node][i - 1]][i - 1];
    }

    for (auto child : v[node]) {
        if (child != pr) {
            dfs(child , node);
        }
    }

    out[node] = ++timer;
}

bool is_ancestor(long long ancestor , long long node) {
    return (in[ancestor] <= in[node] && out[ancestor] >= out[node]);
}

long long lca(long long u , long long v) {
    if (is_ancestor(u , v)) return u;
    if (is_ancestor(v , u)) return v;

    for (int i = l ; i >= 0 ; i--) {
        if (!is_ancestor(up[u][i] , v)) u = up[u][i];
    }

    return up[u][0];
}

void preprocess(long long root) {
    timer = 0;
    l = ceil(log2(n));

    for (int i = 0 ; i < n + 1 ; i++) {
        up[i].clear();
        in[i] = out[i] = 0;
        up[i].resize(l + 1);
    }

    dfs(root , root);
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// above one shoud be above using namespace std

template<typename T>
#define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
// o_set(ll) name ; -- defining ordered set
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : counting from zero it returns the k-th largest or smallest element in the set - returns iterator

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
