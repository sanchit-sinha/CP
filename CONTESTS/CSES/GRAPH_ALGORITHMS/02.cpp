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

const ll N = 1e3+11;
ll n,m;
string s[N];
pll start , endd;
ll dis[N][N];
ll movement[N][N];
bool found = 0;
		// left right up down
ll dx[4] = {1 , -1 , 0 , 0};
ll dy[4] = {0 , 0 , 1 , -1};
bool vis[N][N];
void dfs(ll i , ll j){
    vis[i][j] = 1;
    pll p = mp(i,j);
    if(p==endd) found=1;
    for(ll k=0;k<4;k++){
        ll x = i - dx[k];
        ll y = j - dy[k];
        if(x >= 0 && y >= 0 && x < n && y < m && vis[x][y] == 0){
        	if(s[x][y]=='.' || s[x][y] == 'A' || s[x][y] == 'B'){
        		dis[x][y] = dis[i][j] + 1;

        		movement[x][y] = k;  

        		dfs(x,y);
        	}
        }
    }
}
ll dist[N];
vector<pair<ll,ll>> v[N];
void dij(ll node){
    set<pair<ll,ll>> s;
    for(ll i=0;i<n;i++){
        dist[i+1]=LLONG_MAX;
        if(i!=node-1) s.insert({dist[i+1],i+1});
    }
    dist[node]=0;
    s.insert({dist[node],node});
    while(!s.empty()){
        ll from=s.begin()->second;
        s.erase(s.begin());
        for(auto child:v[from]){
            ll len=child.second;
            ll to=child.first;
            if(dist[from]+len < dist[to]){
                s.erase(make_pair(dist[to],to));
                dist[to]=dist[from]+len;
                s.insert({dist[to] , to});
        	}
        }
    }
}
void solve(){
    cin>>n>>m;
    rep(i,n ){
    	cin>>s[i];
    }

    rep(i,n){
    	rep(j,m){
    		if(s[i][j] == 'A') start.f = i - 1 ,start.s = j - 1;
    		if(s[i][j] == 'B') endd.f = i - 1 , endd.s = j - 1;
    	}
    }

    memset(movement , -1 , sizeof(movement));
    dfs(start.f , start.s);

    if(found) cout<<"YES\n";
    else cout<<"NO\n";

    if(found){
    	cout<<dis[endd.f][endd.s]<<"\n";
    	string path;
    	ll x = endd.f , y = endd.s;
    	while(mp(x,y) != start){
    		ll move = movement[x][y];	
    		if(move == 0) path.pb('R');
    		else if(move == 1) path.pb('L');
    		else if(move == 2) path.pb('D');
    		else if(move == 3) path.pb('U');
    		x += dx[move];
    		y += dy[move];
    	} 
   		cout << path <<"\n";
    	reverse(all(path));
    	cout<<path<<"\n";
    }
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll NTC=1;
    // cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
