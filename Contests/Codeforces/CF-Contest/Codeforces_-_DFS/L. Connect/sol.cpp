/**
 *    Author:  Sanchit Sinha
 *    Created: 29.10.2020 02:06:28       
**/
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

const ll N = 60;
ll n,m;
ll sx,sy,ex,ey;
string A[N];
ll dx[4] = {1 , -1 , 0 , 0};
ll dy[4] = {0 , 0 , 1 , -1};
bool vis[N][N];
void dfs(vpll &v,ll i , ll j){
    vis[i][j] = 1;
    v.pb(mp(i,j));
    for(ll k=0;k<4;k++){
        ll x = i - dx[k];
        ll y = j - dy[k];
        if(x >= 0 && y >= 0 && x < n && y < n && vis[x][y] == 0 && A[x][y]=='0'){
            dfs(v,x,y);
        }
    }
}
void solve(){
    cin>>n;
    cin>>sx>>sy>>ex>>ey;
    sx--;sy--,ex--,ey--;
    
    rep(i,n){
        cin>>A[i];
    }
    
    vpll path1;
    dfs(path1,sx,sy);


    vpll path2;
    dfs(path2,ex,ey);

    // cout<<"PATH1\n";
    // rep(i,sz(path1)) cout<<path1[i].first <<" " << path1[i].second<<"\n";
    // cout<<"\n\n";
    // cout<<"PATH2\n";
    // rep(j,sz(path2)) cout<<path2[j].first<<" "<<path2[j].second<<"\n";
    // cout<<"\n";

    ll ans=LLONG_MAX;
    rep(i,sz(path1)){
        rep(j,sz(path2)){
            ll x1=path1[i].first,y1=path1[i].second;
            ll x2=path2[j].first,y2=path2[j].second;

            ll cost=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
            ans=min(ans,cost);
        }
    }
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
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
