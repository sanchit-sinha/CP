#include "bits/stdc++.h"
using namespace std;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define trav(a,x) for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define f first
#define s second

inline ll max(ll a,ll b) {return ((a>b)?a:b);}
inline ll min(ll a,ll b) {return ((a>b)?b:a);}
inline ll gcd(ll a ,ll b) {if(b==0) return a; a%=b;return gcd(b,a);}
ll power(ll x, ll y){if(y == 0) return 1; ll a = power(x,y/2);if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex , ll md) {ll ans = 1ll;while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll;x = (x * x) % md;}return ans;}

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e6 + 1;
ll n , m , dist[N];
vpll v[N];
map<ll ,ll > path;
void dij(ll node){
	set<pll> s;
	rep(i , n) {
		dist[i + 1] = inf;
		if(i != node - 1) s.insert({dist[i + 1] , i + 1});
	}
	dist[node] = 0;
	s.insert({dist[node] , node});
	while(!s.empty()){
		ll from = s.begin()->s;
		s.erase(s.begin());
		for(auto child : v[from]){
			ll len = child.s;
			ll to = child.f;
			if(dist[from] + len < dist[to]){
				s.erase(make_pair(dist[to] , to));
				dist[to] = dist[from] + len;
                path[to] = from; 
                s.insert({dist[to] , to});
			}
		}
	}
}
void solve(){
    cin >> n >> m;
    rep(i , m){
        ll a , b, c;
        cin >> a >> b >> c;
        v[a].pb({b , c});
        v[b].pb({a , c});
    }
    dij(1);
    if(dist[n] == inf ) {
        cout << -1 << endl;
        return ;
    }
    // trav(it , path) cout << it->f <<" " << it->s << endl;
    vll ans ;
    ll ele = n;
    while(ele != 1){
        ans.pb(ele);
        ele = path[ele];
    }
    reverse(all(ans));
    cout << 1 <<" ";
    trav(it , ans ) cout << *it <<" ";
}
int main(){
    IOS;
    cout << fixed << setprecision(20);
    ll NTC=1;
    // cin>>NTC;
    ll PTC=0;
    while(PTC++<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
