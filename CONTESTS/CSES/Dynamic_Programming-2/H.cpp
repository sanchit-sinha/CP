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



void solve(){
	ll n,m;
	cin>>n>>m;
	ll a[n];
	rep(i,n) cin>>a[i];
	vector<vll> dp(n+11 , vll(m+11,0));
	// dp[i][j] = max number of ways of building an array with last number as j;
	if(a[0]==0){
		FOR(i,1,m) dp[0][i]=1;
	}
	else dp[0][a[0]]=1;

	
	bool poss=1;
	FOR(i,1,n-1){
		if(a[i]){
			if(a[i-1]) {
				if(abs(a[i]-a[i-1])>1) poss=0;
				dp[i][a[i]] = dp[i-1][a[i-1]]%mod;
			}
			else{
				FOR(k,-1,1){
					ll val=a[i]+k;
					if(val>=1 && val<=m){
						dp[i][a[i]]+=dp[i-1][val];
						dp[i][a[i]]%=mod;
					}
				}
				// dp[i][a[i]] = ((dp[i-1][a[i]-1] + dp[i-1][a[i]])%mod + dp[i-1][a[i]+1])%mod;
			}
		}
		else{
			// ai == 0
			if(a[i-1]==0){
				FOR(j,1,m){
					FOR(k,-1,1){
						ll val=j+k;
						if(val>=1 && val<=m){
							dp[i][val] += dp[i-1][j];
							dp[i][val]%=mod;
						}
					}
				}
			}
			else{
				FOR(k,-1,1){
					ll val=a[i-1]+k;
					if(val>=1 && val<=m){
						dp[i][val]+=dp[i-1][a[i-1]];
						dp[i][val]%=mod;
					}
				}
			}
		}
	}
	
	// cout << "i ai" << ": ";
	// FOR(i,1,m) cout<<i << " ";
	// cout<<"\n";
	// rep(i,n){
	// 	cout << i <<" " << a[i]<< ": ";
	// 	FOR(j,1,m){
	// 		cout<<dp[i][j] <<" ";
	// 	}
	// 	cout<<"\n";
	// }

	if(poss){
		if(a[n-1]) cout<<dp[n-1][a[n-1]]<<"\n";
		else{
			ll answer=0;
			FOR(i,1,m){
				answer += dp[n-1][i];
				answer%=mod;
			}
			cout<<answer<<"\n";
		}
	}
	else cout<<"0\n";
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
													