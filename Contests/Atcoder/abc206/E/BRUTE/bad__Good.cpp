// Problem: E - Divide Both
// Contest: AtCoder - AtCoder Beginner Contest 206（Sponsored by Panasonic）
// URL: https://atcoder.jp/contests/abc206/tasks/abc206_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;
#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ld  long double
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vvi vector<vector<int>>
#define vs vector<string>
#define vpll vector<pll>
#define vpi vector<pi>
#define pb push_back
#define eb emplace_back
#define fi first
#define sc second
#define all(c)  (c).begin(),(c).end()
#define sz(c) int((c).size())
#define MP make_pair

#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORI(i, a, b) for(int i = (a); i >= (b); i--)

const int INF = 1e9 + 7;
const long long MOD = 1e9 + 7;

// credits : tourist
string to_string(string s) {return '"' + s + '"';} string to_string(const char* s) {return to_string((string) s);} string to_string(bool b) {return (b ? "true" : "false");} template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";} template <typename A>string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", ";} first = false; res += to_string(x);} res += "}"; return res;} void debug_out() { cerr << "\n"; } template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n"; debug_out(T...);}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
ll gcd(ll x , ll y) {
	if (y == 0)  return x;
	if (x == 0)  return y;
	if (x < y) swap(x , y);
	return gcd(x % y , y);
}

const int N = 1e6 + 8;

ll dp[N]; /* number of pairs with gcd = g*/

ll brute(int L , int R, int g) {
	ll p = 0;
	for (int i = L; i <= R; i++) {
		for (int j = i + 1; j <= R; j++) {
			p += gcd(i , j) == g;
		}
	}
	return p;
}
void solve() {
	int L , R;
	cin >> L >> R;

	if (L >= R) {
		cout << 0 << "\n";
		return;
	}

	for (int g = R;  g >= 1; g--) {
		int cnt = 0;
		for (int m = g; m <= R; m += g) {
			if (m != g) {
				dp[g] -= dp[m];
			}
			if (m >= L) cnt++;
		}
		ll val = 1LL * cnt * (cnt - 1) / 2;
		dp[g] += val;
	}

	ll ans = 0;
	for (int g = 2; g <= R; g++) {
		ll val = dp[g];
		ll remove = 0;
		if (g >= L) remove = (R / g) - 1;

		ans += 2LL * (val - remove);
	}
	cout << ans << endl;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tt = 1;
	// cin >> tt;

#ifdef SIEVE
	construct();
#endif

#ifdef NCR
	compute_combinations_table(MOD);
#endif

#ifdef FACTORIALS
	compute_factorials(MOD);
#endif

	for (int tc = 1; tc <= tt; tc++) {
		// cout << "Case #" << tc << ": ";
		solve();
	}
}