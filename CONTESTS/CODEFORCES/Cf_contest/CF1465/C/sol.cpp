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
#define ub upper_bound1
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
set<pll> row , col, points;
pll point[9];
ll n , m;
vpll v;
ll ans = 0;


void ppppp(pll a){
	cerr <<"-----" << a.f <<" " << a.s <<"-----\n";
}
pair<pll , pll > got(ll xi, ll yi){
	pll index1= {-1 , -1};
	pll index2 = {-1 , -1};

	auto it1 = col.upper_bound(mp(xi , LLONG_MAX));
	if(it1 != col.begin()){
		it1--;
		ll index = it1->second;
		index1 = mp(v[index - 1].f , xi);
	}

	auto it2 = row.upper_bound(mp(yi , LLONG_MAX));
	if(it2 != row.begin()){

		it2--;
		ll index = it2->second;
		index2 = mp(yi , v[index - 1].s);
	}

	return mp(index1 , index2);

}
bool notminusone(pll a, pll b){
	if(a.f == -1) return false;
	if(a.s == -1) return false;
	if(b.f == -1) return false;
	if(b.s == -1) return false;

	return true;
}

bool alleq(){
	vpll v1, v2 ,v3;
	// 0 1 2 3 4 5 6 7 8
	// 0 =  3 =  6
	// 1 =  4 =  7
	// 2 =  5 =  8	
	v1.pb(point[0]);
	v1.pb(point[3]);
	v1.pb(point[6]);

	v2.pb(point[1]);
	v2.pb(point[4]);
	v2.pb(point[7]);

	v3.pb(point[2]);
	v3.pb(point[5]);
	v3.pb(point[8]);

	sort(all(v1));
	sort(all(v2));
	sort(all(v3));

	if(v1 == v2 && v2 == v3) return 1;
	else return 0;
}	

void assign(ll a , ll b , ll c){
	point[a].f = b;
	point[a].s = c;
}

void solve(){
	v.clear();
	points.clear();
	row.clear();
	col.clear();
	ans = 0;
	rep(i , 9) point[i].f = -1,  point[i].s = -1; 

	cin >> n >> m;

	rep(i , m){
		ll x , y;
		cin >> x >> y;
		v.pb(mp(x , y));
	}

	sort(all(v));

	rep(i , m){
		ll xi = v[i].f;
		ll yi = v[i].s;
		row.insert(mp(xi , i + 1));
		col.insert(mp(yi , i + 1));
	}
	rep(i , m) points.insert(v[i]);


	rep(i , m){
		ll xi = v[i].f;
		ll yi = v[i].s;

		auto it9 = points.find(mp(xi , yi));
		if(it9 == points.end()) continue;



		if(xi != yi){
			rep(j , 9) point[j] = mp(-1 , -1);
			assign(0 , xi , yi);

			pair<pll, pll> a = got(xi , yi);
			assign(1 , a.f.f , a.f.s);
			assign(2 , a.s.f , a.s.s);

			bool add = 0;

			// 0 1 2 3 4 5 6 7 8
			// 0 =  3 =  6
			// 1 =  4 =  7
			// 2 =  5 =  8
			if(notminusone(point[1] , point[2])){
				assign(3 , point[1].f , point[1].s);


				pair<pll , pll > b = got(point[1].f , point[1].s);
				assign(4 , b.f.f , b.f.s);
				assign(5 , b.s.f , b.s.s);

				if(notminusone(point[4] , point[5])){
					assign(6 , point[2].f , point[2].s);

					pair<pll ,pll> c = got(point[2].f , point[2].s);
					assign(7 , c.f.f , c.f.s);
					assign(8 , c.s.f , c.s.s);

					if(notminusone(point[8] , point[9])){
						if(alleq()) add = 1;
					}
				}
			}	

			if(add){
				ans++;
			}

			auto it = points.find(mp(xi , yi));
			if(it != points.end()) ans++, points.erase(it);

			it = points.find(point[1]);
			if(it != points.end()) ans++, points.erase(it);

			it = points.find(point[2]);
			if(it != points.end()) ans++, points.erase(it);
		}
		else{
			auto it = points.find(mp(xi , yi));
			if(it != points.end()) points.erase(it);
		}
	}

	cout << ans << "\n";

	cerr << "***************************\n";
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
			