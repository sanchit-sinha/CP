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
#define sz(c)               (int)(c.size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

inline ll gcd(ll a,ll b) {if(b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a,ll b) {return((a > b) ? a : b);}
inline ll min(ll a,ll b) {return((a > b) ? b : a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

// trying to constructing a single bamboo : The constraints are misleading xd
const ll N = 1e3+11;
ll n;
vll v[N]; // graph

void solve(){
	cin >> n;

	bool ok = 1;
	vll used(n + 1 , 0);
	rep(i , n - 1){
		ll a, b;
		cin >> a >> b;
		if(b != n) ok = 0;
		used[a]++;
	}

	if(!ok){
		cout << "NO\n";
		return;
	}

	vll notfixednode;
	vpll fixednode;
	FOR(i , 1 , n - 1){
		ll node = i;
		ll dis = used[node];

		if(dis) fixednode.pb({node , dis});
		else notfixednode.pb(node);
	}

	reverse(all(fixednode)); // larger to smaller

	// cout << "FIXED NODE\n";
	// rep(i , sz(fixednode)) cout << fixednode[i].f << " : " << fixednode[i].s << "\n";
	// cout << "\n";
	// cout << "NOT FIXED NODE\n";
	// rep(i , sz(notfixednode)) cout << notfixednode[i] << " ";
	// cout << "\n";
	
	ll parent = n;
	rep(i , sz(fixednode)){
		ll node = fixednode[i].f;
		ll dis = fixednode[i].s;

		while(dis > 1){
			if(sz(notfixednode) == 0){
				ok = 0;
				cout << "NO\n";
				return;
			}
			ll cur_node = notfixednode.back();	
			if(cur_node > node){
				ok = 0;
				cout << "NO\n";
				return;
			} 	

			notfixednode.pop_back();
			v[parent].pb(cur_node);
			parent = cur_node;

			dis--;
		}

		v[parent].pb(node);
		parent = node;
	}


	if(!ok) cout << "NO\n";
	else{
		cout << "YES\n";
		FOR(i ,1 , n){
			ll node = i;
			for(auto child : v[node]) cout << node << " " << child << "\n";
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
   
    ll NTC=1;
    // cin>>NTC;

    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        factorial();
    #endif 
    #ifdef PREPROCESS
        preprocess();
    #endif
    
    ll PTC=0;
    while((PTC++)<NTC){
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
