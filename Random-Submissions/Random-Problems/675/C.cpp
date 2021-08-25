#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
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
ll power(ll x,ll y);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5 + 11;


ll mul(ll i){
	ll p=1;
	p*=i;p%=mod;
	p*=(i-1);p%=mod;

	p*=powermod(2,mod-2,mod);
	p%=mod;

	p=(p+i)%mod;

	return p%mod;
}
void solve(){
    string s;
    cin>>s;
    ll n=sz(s);

	ll ans=0;
	rep(i,n){
		ll p=((s[i] - '0')%mod * mul(i) )%mod;
		p%=mod;
		p*=powermod(10,n-i-1,mod);

		ans+=p;
		ans%=mod;
	}    

	FOR(i,0,n-2){
		ll p=((s[i] - '0'))%mod;

		ll a=(powermod(10,n-i-1,mod) * (n-i-2))%mod;
		a%=mod;
		a*=9;
		a%=mod;

		ll b=(powermod(2,n-i+2,mod) * powermod(5,n-i-1,mod))%mod;
		b%=mod;

		ll c=1;

		ll sum=a;
		sum+=b;sum%=mod	;
		sum+=c;sum%=mod;

		sum*=powermod(81,mod-2,mod);
		sum%=mod;

		p=(p%mod * sum%mod)%mod;


		ans=(ans%mod + p%mod)%mod;
		ans%=mod;

	}

	// FOR(i,0,n-i-2){
	// 	ll p=(s[i]-'0');
	// 	ll a=(powermod(10,n-i-2,mod) * (n-i-2))%mod;
	// 	a*=9;a%=mod;

	// 	ll b=powermod(10,n-i-2,mod);

	// 	ll c=1;

	// 	ll sum=(a-b)%mod;sum=(sum+mod)%mod;
	// 	sum+=c;sum%=mod;

	// 	p*=sum;
	// 	p%=mod;

	// 	p*=powermod(81,mod-2,mod);
	// 	p%=mod;

	// 	ans+=p;
	// 	ans%=mod;
	// }

    cout<<ans<<"\n";

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
	