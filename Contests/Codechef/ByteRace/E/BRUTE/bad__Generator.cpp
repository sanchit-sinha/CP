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

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5+11;


ll get(int l , int r){
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n = uniform_int_distribution<int> (l , r)(rng);
    return n;

}
int main(int argc, char* argv[]) {
	ll maxn = 10;
	cout << 1 << endl;
	ll n = get(1 , maxn);

	ll m = get(1 , n);
	cout << n << " " << m << endl;
	for(int i = 0; i < n; i++){
		cout << get(1 , 5) << " ";
	}
	cout << endl;

	set<ll> st;
	for(int i = 0; i < m; i++){
		ll ele = get(1 , n);
		while(st.find(ele) != st.end()){
			ele = get(1 , n);
		}
		st.insert(ele);
	}
	for(auto it : st){
		cout << it << " ";
	}
	cout << endl;

    
}		