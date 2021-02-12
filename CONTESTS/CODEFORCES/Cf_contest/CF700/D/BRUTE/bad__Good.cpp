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

ll check(ll a[] , ll n , ll x){
	a[n] = 0;
	ll b[n] = {0};
	ll temp = x;
	ll index = 0;
	while(temp){
		b[index++] = temp%2;
		temp /= 2;
	}


	vll black , white;
	black.pb(n);
	white.pb(n);
	rep(i , n){
		ll x = a[i];
		if(b[i] == 1){
			if(a[black.back()] != x)black.pb(i);
		}
		else{
			if(a[white.back()] != x) white.pb(i);
		}
	}

	return sz(black) + sz(white) - 2 ;

}
void print(ll a[] , ll n , ll x){
	a[n] = 0;
	ll b[n] = {0};
	ll temp = x;
	ll index = 0;
	while(temp){
		b[index++] = temp%2;
		temp /= 2;
	}

	vll black , white;
	black.pb(n);
	white.pb(n);
	rep(i , n){
		ll x = a[i];
		if(b[i] == 1){
			if(a[black.back()] != x){
				black.pb(i);
			}
		}
		else{
			if(a[white.back()] != x) white.pb(i);
		}
	}
	
	FOR(i  , 1 , sz(black) - 1) cout << black[i] << " ";
	cout << "\n";

	FOR(i  , 1 , sz(white) - 1) cout << white[i] << " ";
	cout << "\n";
	cout << "\n";
}
void solve(){
    ll n;
    cin >> n;
    ll a[n + 11] = {0};
    rep(i , n) cin >> a[i];

    ll ans = 0;
    ll store = 0;
    rep(i , (1ll<<n)){
    	ll x =  check(a , n , i);
    	ans = max(ans , x);
    	if(ans == x) store = i;
    } 

    print(a , n , store);
    cout << ans << "\n";
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    ll NTC=1;
    // cin>>NTC;
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
