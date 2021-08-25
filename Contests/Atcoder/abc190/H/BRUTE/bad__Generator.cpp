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

ll range(ll l ,ll r){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n = uniform_int_distribution<int> (l , r)(rng);
    return n;
}

int main(int argc, char* argv[]) {
	cout << 1 << "\n";
    ll n = range(3,5);
    cout << n <<"\n";
    ll m = range(1,3);
    cout << m << "\n";

    set<pll>s ; 
    rep(i , m){

    	while(1){
	    	ll x = range(0 , n - 1);
	    	ll y = range(0 , n - 1);

			auto it1 = s.find(mp(x , y));	    	
			auto it2 = s.find(mp(y , x));	    	
	    	
	    	if(it1 == s.end() && it2 == s.end() && (x != y)){
	    		cout << x <<" " << y << "\n";
    			s.insert(mp(x , y));
    			s.insert(mp(y , x));
    			break;
    		}

    	}
    }
}		