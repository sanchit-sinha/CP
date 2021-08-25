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
const ll N = 1e6 + 5;

vll pr;
#define SIEVE
const ll mX = N;
bool prime[mX + 11];
void sieve() {
	memset(prime, true, sizeof(prime));
	for (ll p = 2 ; p * p <= mX ; p++) {
		if (prime[p] == true) {
			pr.pb(p);
			for (ll i = p * p ; i <= mX; i += p) prime[i] = false;
		}
	}
}

bool check(vll &pfx, ll a, ll b, ll l, ll k) {
	ll lo = a, hi = b - l + 1;
	FOR(x, lo , hi) {
		ll mn = x;
		ll mx = x + l - 1;

		ll get = pfx[mx] - pfx[mn - 1];
		if (get < k) return 0;
	}

	return 1;
}
void solve() {
	ll a , b , k;
	cin >> a >> b >> k;

	prime[1] = 0;
	vll pfx(N + 11, 0);
	FOR(i, 1, N) pfx[i] = pfx[i - 1] + 1ll * prime[i];

	// debug(pfx);
	// debug(sz(pr), pr);

	ll lo = 1, hi = b - a + 1, ans = -1;
	while (lo <= hi) {
		ll mid = lo + (hi - lo) / 2;
		if (check(pfx, a, b, mid, k)) {
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}

	debug(a, b - a + 1, ans);
	debug(a, b - ans + 1);
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
		cerr << "Testcase # " << PTC << "\n";
		// cout << "Case #" << PTC << ":" << ' ';
		solve();
		cerr << "*************************\n";
	}
	// cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
