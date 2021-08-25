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

const ll N = 3e2 + 11;
string s[N];
ll n,ans;
ll a[N][N];


bool construct(ll index1 , ll index2){
	ll ct = 0 ;
	rep(i,3){
		rep(j,3) a[index1+i][index2+i] = 0;
	}
	rep(j,3){
		ct = 0;
		rep(i,3) if(s[index1 + j][index2 + i] == 'X') ct++;
		if(ct == 3) {
			rep(i,3) a[index1 + j][index2 + i]++;
		}
		
		ct = 0;
		rep(i,3) if(s[index1 + i][index2 + j] == 'X') ct++;
		if(ct == 3){
			rep(i , 3) a[index1 + i][index2 + j]++;
		} 
	}


	ct = 0;
	rep(i, 3){
		rep(j , 3){
			if(a[index1 + i][index2 + j] == 2) ct++;
		}
	}

	if(ct == 6) return true;
	else return false;

}
void solve(){
	rep(i,n) s[i].clear();
	rep(i,n){
		rep(j,n) a[i][j] = 0;
	}
	ans = 0;

    cin >> n;

    rep(i, n){
    	cin >> s[i];
    } 


    for(ll i = 0 ; i<= n - 1 - (n%3) ; i+=1){
    	for(ll j = 0 ; j <= n - 1 -(n%3) ; j += 1)	{
    		// cout << " in \n";
    		ll  index1 = i;
    		ll index2 = j;
    		
    		bool good = construct(index1 , index2);
    		if(good){
    			cout << index1 <<" " << index2 <<"\n";
    			s[index1][index2 + 2] = 'O';
    			s[index1 + 1][index2 + 1] = 'O';
    			s[index1 + 2][index2] = 'O';
    			ans += 3;

    			i += 3;
    			j += 3;
    		}
    		else{
    			rep(i , 3){
    				rep(j , 3){
    					if(a[index1 + i][index2 + 2 - j] == 2) {
    						s[index1 + i][index2 + 2 - j] = 'O';
    						ans++ ;
    						break;
    					}
    				}
    			}
    		}
    	}
    }

    for(ll j = n - (n%3) ; j <= n - 1 ;j++){
    	for(ll i = 0 ; i <= n - 1 ; i++){
    		ll ct = 0 ;
    		rep(k , 3) if(i + k <= n - 1 && s[i + k][j] == 'X') ct++;
    		if(ct == 3) {
    			s[i + 2][j] = 'O';
    			ans++;
    		}
    	}
    }

    for(ll i = n - (n%3) ; i <= n - 1 ;i++){
    	for(ll j = 0 ; j <= n - 1; j++){
    		ll ct = 0 ;
    		rep(k , 3) if(j + k <= n - 1 && s[i][j+k] == 'X') ct++;
    		if(ct == 3) {
    			s[i][j+2] = 'O';
    			ans++;
    		}
    	}
    }

    cout << "------------\n";
    cout << ans << "\n";
    rep(i , n) cout << s[i] << "\n";
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
