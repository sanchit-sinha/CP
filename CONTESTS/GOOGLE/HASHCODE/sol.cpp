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
    ll d , i , s , v , f;
    cin >> d >> i >> s >> v >> f;

    map<string , pair<pll , ll > > street;
    rep(i , s){
    	ll start , end;
    	cin >> start >> end;
    	
    	string street_name;
    	cin >> street_name;

    	ll time;
    	cin >> time;

    	street[street_name] = mp(mp(start , end) , time);
    }

    map<ll , vector<string>  > car;
    rep(i , v){
    	ll p;
    	cin >> p;

    	vector<string> street_name;
    	rep(j , p){
    		string x;
    		cin >> x;

    		street_name.pb(x);
    	}

    	car[i] = street_name;
    }

    ll mn = LLONG_MAX;
    ll index = -1;
    rep(i , v){
    	ll len = sz(car[i]);
    	ll time = 0;

    	rep(j , len){
    		string x = car[i][j];
    		pair<pll , ll >pr =  street[x];
    		
    		ll start = pr.f.f;
    		ll end = pr.f.s;
    		ll t1 = pr.s;

    		if(j == 0){
    			continue;
    		}
    		else{
    			time += 1;
    			time += t1;
    		}
    	}

    	if(time <= d){
    		mn = min(mn , time);
    		if(mn == time) index = i;
    	}
    }

    ll len = sz(car[index]);
    ll time = 0;

    vector<pair<ll,string>> path;
    rep(j , len){
		string x = car[index][j];
		pair<pll , ll >pr =  street[x];
		
		ll start = pr.f.f;
		ll end = pr.f.s;
		ll t1 = pr.s;

		if(j == 0){
			path.pb(mp(end , x));
		}
		else{
			time += 1;
			time += t1;
			path.pb(mp(end , x));
		}
    }	

    cout << sz(path) << "\n";
    rep(j , sz(path)){
  		cout << path[j].f << "\n";
   		cout << 1 << "\n";
    	cout << path[j].s << " " << 1 << "\n";
	}	


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
	