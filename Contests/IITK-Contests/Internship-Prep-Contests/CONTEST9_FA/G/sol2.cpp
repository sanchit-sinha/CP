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

void find(vll &a, vll &b){
	ll n = sz(a);
	rep(i , n) cout << a[i] << " ";
	cout << "\n";

	rep(i , n) cout << b[i] << " ";
	cout << "\n";

	vll index1(n + 1 , 0) , index2(n + 1 , 0);
	FOR(i , 0 , n - 1) index1[a[i]] = i;
	FOR(i , 0 , n - 1) index2[b[i]] = i;

	FOR(i ,1, n){
		FOR(j , i + 1 , n){
			FOR(k ,j + 1 , n){
				ll x[3] = {index1[i] , index1[j] , index1[k]};
				ll y[3] = {index2[i] , index2[j] , index2[k]};
			
				bool ok1 = 1 , ok2 = 1;
				FOR(j ,1 , 2){
					if(x[j] > x[j - 1] && y[j] < y[j - 1]) ok1 = 0;
					if(x[j] < x[j - 1] && y[j] > y[j - 1]) ok1 = 0;
				}			
				if(ok1 && ok2){
					cout << i << " " << j <<  " " << k << "\n";
					cout << "\n";
				}
			}
		}
	}


	cout << "****************************************\n\n";

}
int main(int argc, char* argv[]) {
	ll n = 7;
	cout << n << "\n";

	vll a(n) , b(n);
	rep(i , n) a[i] = i + 1;
	rep(i , n) b[i] = i + 1;

	ll fact = 1;
	FOR(i , 2 , n) fact *= i;
	fact *= fact; 

	ll ct = 200;
	int pos = 0;
	vll c , d;

	do {
		if(pos == ct) break;
		do{
			pos++;
			if(pos == ct) break;
			c = a;
			d = b;
		}while(next_permutation(all(b)));
	} while (next_permutation(all(a)));

	find(c , d);
}