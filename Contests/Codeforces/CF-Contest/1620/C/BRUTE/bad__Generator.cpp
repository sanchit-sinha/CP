#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define mp make_pair
#define mt make_tuple
#define get(x,c) get<x>(c)
#define trav(a,x) for(auto a=x.begin();a!=x.end();a++)
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,b,a) for(int i=b;i>=a;i--)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define f first
#define s second

inline ll gcd(ll a, ll b) {if (b == 0)return a; a %= b; return gcd(b, a);}
inline ll max(ll a, ll b) {return ((a > b) ? a : b);}
inline ll min(ll a, ll b) {return ((a > b) ? b : a);}
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5 + 11;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll range(ll l , ll r) {
	ll n = uniform_int_distribution<int> (l , r)(rng);
	return n;
}

int main(int argc, char* argv[]) {
	cout << 1 << "\n";
	ll n = range(1, 20);
	ll k = range(0, n);

	string s;
	rep(i, n) {
		ll x = range(1, 2);
		if (x == 1) s.pb('a');
		else s.pb('*');
	}

	ll asterik = 0ll;
	rep(i, n) asterik += (s[i] == '*');

	vll mul, sfx;
	auto trim = [&](char c) {
		string t ;
		ll n = sz(s);

		rep(i, n) {
			if (s[i] != '*') t.pb(s[i]), mul.pb(1);
			else {
				ll cnt = 0ll;
				while (i < n && s[i] == '*') i++, cnt++;
				i--;

				mul.pb(cnt * k + 1);
				t.pb('*');
			}
		}

		return t;
	};
	string t = trim('*');

	ll len = sz(t);
	sfx.assign(len + 3, 1);

	ll mx = 1e18;
	bool ok = 0;
	FORR(i, len - 1, 0) {
		if (sfx[i + 1] >= 1e18 / mul[i]) {
			ok = 1;
			break;
		}

		if (t[i] == '*') sfx[i] = sfx[i + 1] * mul[i];
		else sfx[i] = sfx[i + 1];
	}


	if (ok) mx = 1e18;
	else mx = sfx[0];

	ll x = range(1, mx);

	cout << n << " " << k << " " << x << "\n";
	cout << s << "\n";
}