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
const ll N = 1e6 + 11;
ll A[N], B[N], C[N], D[N];
void phi_1_to_n(int n) {
	A[0] = 0;
	A[1] = 1;
	for (int i = 2; i <= n; i++)
		A[i] = i;

	for (int i = 2; i <= n; i++) {
		if (A[i] == i) {
			for (int j = i; j <= n; j += i)
				A[j] -= A[j] / i;
		}
	}
}

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
#define PREPROCESS
void preprocess() {
	sieve();
	phi_1_to_n(N - 1);

	for (int i = 1; i <= N - 1 ; i++) {
		for (int j = i ; j <= N - 1; j += i) {
			B[j] += A[i];
		}
	}


	// rep(i, N) cerr << spf[i] << "\n";
	rep(i, N) {
		ll x = B[i];
		while (x > 1) {
			ll div = spf[x];
			ll ct = 0;
			while (x % div == 0) ct++, x /= div;
			C[i] += ct;
		}
	}


	rep(i, N) {
		(i == 0) ? (D[i] = C[i]) : (D[i] = D[i - 1] + C[i]);
	}

// 	ll mx = 0ll;
// 	rep(i, N) mx = max(mx, B[i]);
// 	cerr << mx << "\n";
// 	rep(i , 10) cerr << i << " : " << A[i] << " " << B[i] << "\n";
// 	cerr << "\n";
}

void solve() {
	ll n;
	cin >> n;
	cout << D[n] << "\n";
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
// #ifdef SIEVE
// 	sieve();
// #endif
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
