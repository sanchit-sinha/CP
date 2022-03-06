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

// range update, {min, index} query
const ll N = 2e5 + 11;
pll tree[4 * N];
ll lazy[N * 4], a[N];

pll pull(pll l, pll r) {
	ll x = min(l.f, r.f), y = -1; //operation
	if (l.f < r.f) y = l.s;
	else y = r.s;

	return make_pair(x, y);
}

void push(ll v) {
	tree[v * 2].f += lazy[v];
	lazy[v * 2] += lazy[v];
	tree[v * 2 + 1].f += lazy[v];
	lazy[v * 2 + 1] += lazy[v];
	lazy[v] = 0;
}

void build(ll node, ll l, ll r) {
	if (l == r) tree[node] = {a[l], l};
	else {
		ll mid = l + (r - l) / 2;
		build(2 * node, l, mid);
		build(2 * node + 1, mid + 1, r);

		tree[node] = pull(tree[node * 2], tree[node * 2 + 1]);
	}
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll addend) {
	if (l > r)
		return;
	if (l == tl && tr == r) {
		tree[v].f += addend;
		lazy[v] += addend;
	} else {
		push(v);
		ll tm = (tl + tr) / 2;
		update(v * 2, tl, tm, l, min(r, tm), addend);
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
		tree[v] = pull(tree[v * 2], tree[v * 2 + 1]);
	}
}

pll query(ll v, ll tl, ll tr, ll l, ll r) {
	if (l > r) return {inf, -1}; //operation (inf , -inf , 0 ...)
	if (l <= tl && tr <= r) return tree[v];
	push(v);

	ll tm = (tl + tr) / 2;
	pll p1 = query(v * 2, tl, tm, l, min(r, tm));
	pll p2 = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);

	return pull(p1, p2);
}
//build(1,0,n-1) .... query(1,0,n-1,l,r) .... update(1,0,n-1,l,r,add)
void solve() {
	ll n;
	cin >> n;
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
