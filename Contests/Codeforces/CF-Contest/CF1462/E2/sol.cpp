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

ll one(ll x,ll y){
	ll  ans = 0;
	// ans = (x - 1)*y + (y - 1)*x + x*x + y*y - (x*(x + 1))/2 - (y*(y + 1))/2;
	ll a = (x*(x - 1))/2;
	a*=y;
	ll b = (y*(y - 1))/2;
	b*=x;
	
	ans = a + b;
	// cout << "one function : " << x <<" " << y <<" " << ans << "\n";
	return ans;
}
void solve(){
    ll n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i]; 

    map<ll,ll> m;
    rep(i , n){
    	m[a[i]]++;
    }

    ll ans = 0;
    // trav(it, m ) cout << it->first << ": " << it->second << "\n";
    trav(it , m){
    	ll x = it->first;
    	ll alpha = it->second;

    	if(alpha >= 3){
    		// cout <<" in1 : " << x << "\n";
    		ans += (alpha*(alpha - 1)*(alpha - 2))/6;
    	}

    	auto it1 = m.find(x + 1);
    	if(it1 != m.end()){
    		ll beta = m[x + 1];
    		// cout << "in2 : " << x << " " << x + 1 << "\n"; 
    		ans += one(alpha , beta);
    		auto it2 = m.find(x + 2);
    		if(it2 != m.end()){
    			ll gama = m[x + 2];
    			ll val = one(alpha, gama) + beta*gama*alpha ;
    			ans += val;
    		}
    	}
    	else{
    		auto it2 = m.find(x + 2);
    		if(it2 != m.end()){
    			ll gama = m[x + 2];
    			ll val = one(alpha, gama);
    			ans += val;
    		}
    	}
    }

    cout << ans << "\n";
    // cout << "--------------\n";
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    ll NTC=1;
    cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
