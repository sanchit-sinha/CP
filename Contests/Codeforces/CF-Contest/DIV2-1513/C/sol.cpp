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

const ll N = 2e5 + 1;
// len starting from i in j moves
ll dp[10][N + 11];

void solve(){
	string s;
	cin >> s;

	ll m;
	cin >> m;

	ll n = sz(s);
	ll ans = 0;
	rep(i , n){
		ans += dp[s[i] - '0'][m];
		ans %= mod;
	}

	cout << ans << "\n";
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);

    rep(i , 10){
        ll ct[10] = {0};
        ct[i]++;
        dp[i][0] = 1;
        FOR(j , 1 , N){
            ll newct[10] = {0};
            rep(k , 10){
                if(k == 9){
                    newct[0] += ct[k]; 
                    newct[1] += ct[k];

                    newct[0] %= mod;
                    newct[1] %= mod;
                }
                else{
                    newct[k + 1] += ct[k];
                    newct[k + 1] %= mod;
                }
            }
            rep(k , 10){
            	ct[k] = newct[k];
           		dp[i][j] += ct[k];
           		dp[i][j] %= mod;
           	}
        }   
    }  


    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        factorial();
    #endif
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
