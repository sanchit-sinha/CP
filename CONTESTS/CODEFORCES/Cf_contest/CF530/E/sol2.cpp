#include "bits/stdc++.h"
using namespace std;
#define f                   first
#define s                   second
#define pb                  push_back
#define ll                  int
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

// saw the editorial :
// IDEA : either every row or every col has exactly 2 distinct characters
string A = "AGCT";
void display(vector<string> &s) {
	ll n = sz(s);
	ll m = sz(s[0]);

	rep(i , n) {
		rep(j , m) cerr << s[i][j];
		cerr << "\n";
	}
	cerr << "\n";
}
bool check(vector<string> &s) {
	ll n = sz(s);
	ll m = sz(s[0]);

	rep(i , n) {
		rep(j , m) {
			set<char> t;
			int ct = 1;
			t.insert(s[i][j]);

			if (i + 1 < n) t.insert(s[i + 1][j]), ct++;
			if (j + 1 < m) t.insert(s[i][j + 1]), ct++;
			if (i + 1 < n && j + 1 < m) t.insert(s[i + 1][j + 1]), ct++;

			if (sz(t) != ct) return 0;
		}
	}

	return 1;
}
ll count(const vector<string> &s, const vector<string> &t) {
	if (sz(s) != sz(t)) return inf;
	if (sz(s[0]) != sz(t[0])) return inf;
	ll n = sz(s);
	ll m = sz(s[0]);

	ll ans = 0ll;
	rep(i , n) {
		rep(j , m) ans += 1ll * (s[i][j] != t[i][j]);
	}

	return ans;
}

set<vector<string>> ans;
// pattern finding
void backtrack(vector<string> &s, vector<string> &grid, ll filled) {
	ll n = sz(s);
	ll m = sz(s[0]);

	if (filled == n * m) {
		if (check(grid))
			ans.insert(grid);
		return;
	}

	rep(i , n) {
		rep(j , m) {
			if (grid[i][j] == '?') {
				string use;
				if (j - 1 >= 0) use.pb(grid[i][j - 1]);
				if (i - 1 >= 0) use.pb(grid[i - 1][j]);
				if (i - 1 >= 0 && j - 1 >= 0) use.pb(grid[i - 1][j - 1]);

				rep(k, sz(A)) {
					bool got = 0;
					rep(l , sz(use)) {
						if (A[k] == use[l]) got = 1;
					}

					if (!got) {
						grid[i][j] = A[k];
						backtrack(s, grid, filled + 1);
						grid[i][j] = '?';
					}
				}

				return;
			}
		}
	}

	return;
}
ll brute(vector<string> &s) {
	ll n = sz(s);
	ll m = sz(s[0]);

	vector<string> grid(n, string(m , '?'));

	backtrack(s, grid, 0);
	ll mn = inf;
	trav(it , ans) {
		vector<string> t = *it;
		ll x = count(s, t);
		mn = min(mn , x);
	}

	set<vector<string>> newans;
	trav(it , ans) {
		vector<string> t = *it;
		if (count(s, t) == mn) {
			newans.insert(*it);
		}
	}

	cerr << "***************\n";
	trav(it , newans) {
		vector<string> v = *it;
		rep(i, n) {
			rep(j, m) cerr << v[i][j];
			cerr << "\n";
		}
	}

	return mn;
}
pair<ll , vector<string>> generate(const vector<string> &s) {
	ll n = sz(s);
	ll m = sz(s[0]);

	ll mn = inf;
	vector<string> ans;

	string use = "ACGT";
	vector<string> grid(n, string(m, '?'));
	do {
		char a = use[0];
		char b = use[1];

		// top most row
		grid[0][0] = a;
		grid[0][1] = b;
		FOR(j, 2, m - 1) grid[0][j] = grid[0][j - 2];
		FOR(i, 1, n - 1) {
			string mnrow, row1, row2; // ab , ba
			string preschoice;
			rep(ii, 4) {
				if (A[ii] != a && A[ii] != b) preschoice.pb(A[ii]);
			}

			char anew = preschoice[0], bnew = preschoice[1];
			rep(j , m) {
				if (j & 1) {
					row1.pb(anew);
					row2.pb(bnew);
				}
				else {
					row1.pb(bnew);
					row2.pb(anew);
				}
			}

			ll cost1 = 0ll, cost2 = 0ll;
			rep(j, m) cost1 += 1ll * (s[i][j] != row1[j]);
			rep(j, m) cost2 += 1ll * (s[i][j] != row2[j]);

			if (cost1 < cost2) mnrow = row1;
			else mnrow = row2;

			rep(j , m) grid[i][j] = mnrow[j];

			a = anew, b = bnew;
		}

		ll price = count(s, grid);
		mn = min(mn, price);
		if (price == mn) ans = grid;
	} while (next_permutation(all(use)));

	return mp(mn, ans);
}
vector<string> transpose(const vector<string> &s) {
	ll n = sz(s);
	ll m = sz(s[0]);

	vector<string> ans(m , string(n , '?'));
	rep(i , n) {
		rep(j , m) ans[j][i] = s[i][j];
	}

	return ans;
}
void solve() {
	ll n, m;
	cin >> n >> m;

	vector<string> s(n);
	rep(i , n) cin >> s[i];

	vector<string> sT = transpose(s);

	pair<ll, vector<string>> p1 = generate(s);
	pair<ll, vector<string>> p2 = generate(sT);

	vector<string> ANS;
	ll mn = min(p1.f, p2.f);

	if (mn == p1.f) ANS = p1.s;
	else ANS = transpose(p2.s);

	rep(i, n) {
		rep(j, m) cout << ANS[i][j];
		cout << "\n";
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
