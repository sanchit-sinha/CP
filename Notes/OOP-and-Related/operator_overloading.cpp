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


inline ll gcd(ll a, ll b) {if (b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a, ll b) {return ((a > b) ? a : b);}
inline ll min(ll a, ll b) {return ((a > b) ? b : a);}
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

struct RationalNumber {
	int p, q;
	RationalNumber() {
		p = 0, q = 1;
	}
	RationalNumber(int num, int den) {
		assert(den != 0);
		p = num, q = den;
		int g = gcd(p, q);
		p /= g, q /= g;
	}

	// first argument R1 is understood here
	RationalNumber operator +(RationalNumber other) {
		int p1 = this->p;
		int q1 = this->q;

		int p2 = other.p;
		int q2 = other.q;

		return RationalNumber(q2 * p1 + p2 * q1, q1 * q2);
	}
	RationalNumber operator *(RationalNumber other) {
		int p1 = this->p;
		int q1 = this->q;

		int p2 = other.p;
		int q2 = other.q;

		return RationalNumber(p1 * p2 , q1 * q2);
	}

	bool operator >(RationalNumber other) {
		int p1 = this->p;
		int q1 = this->q;

		int p2 = other.p;
		int q2 = other.q;

		return (q2 * p1 > p2 * q1);
	}

	bool operator <(RationalNumber other) {
		int p1 = this->p;
		int q1 = this->q;

		int p2 = other.p;
		int q2 = other.q;

		return (q2 * p1 < p2 * q1);
	}


	bool operator >=(RationalNumber other) {
		int p1 = this->p;
		int q1 = this->q;

		int p2 = other.p;
		int q2 = other.q;

		return (q2 * p1 >= p2 * q1);
	}

	bool operator <=(RationalNumber other) {
		int p1 = this->p;
		int q1 = this->q;

		int p2 = other.p;
		int q2 = other.q;

		return (q2 * p1 <= p2 * q1);
	}

	bool operator ==(RationalNumber other) {
		int p1 = this->p;
		int q1 = this->q;

		int p2 = other.p;
		int q2 = other.q;

		return (q2 * p1 == p2 * q1);
	}

};

bool operator !=(RationalNumber R1, RationalNumber R2) {// use two arguments
	int p1 = R1.p;
	int q1 = R1.q;

	int p2 = R2.p;
	int q2 = R2.q;

	return (q2 * p1 != p2 * q1);
}
ostream& operator <<(ostream& out, RationalNumber R) {
	out << R.p << "/" << R.q ;
	return out;
}
void solve() {
	RationalNumber R1(1, 2), R2(1, 3);
	cout << R1 + R2 << "\n";
	// 5/6

}

int main() {
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
