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

vll v[N];
ll n , q;
ll prnt[N];
ll A[N][N] , B[N][N];

void dfs (ll node , ll parent){
    prnt[node] = parent;
 
    for(auto child:v[node]){
    if(child!=parent){
            dfs(child,node);
        }
    }
}
vll find_path(ll node){
    vll path;
    path.pb(node);
    while(node){
        node = prnt[node];
        if(node) path.pb(node);
    }

    return path;
}
void solve(){
    rep(i , n + 2) v[i].clear();
    rep(i , n + 2){
        prnt[i] = 0;
    }
    rep(i , n + 2){
        rep(j ,n  + 2){
            A[i][j] = B[i][j] = 0; 
        }
    }

    cin >> n >> q;
    rep(i , n - 1){
        ll x , y , l , t;
        cin >> x >> y >> l >> t;

        v[x].pb(y);
        v[y].pb(x);

        A[x][y] = A[y][x] = l;
        B[x][y] = B[y][x] = t;
    }


    dfs(1 , 0);

    // rep(i , n) cout << prnt[i + 1] << " ";
    // cout << "\n";


    while(q--){
        ll node , weight;
        cin >> node >> weight;

        vll path = find_path(node);
        ll len = sz(path);

        // cout << node << " : ";
        // rep(j , len) cout << path[j] << " ";
        // cout << "\n";

        ll g = 0;
        FORR(j , len - 1 , 1){
            ll x = path[j];
            ll y = path[j - 1];

            if(A[x][y] <= weight){
                g = gcd(g , B[x][y]);
            }
        }
        cout << g << " ";
    } 
    cout << "\n";
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    
    ll NTC=1;
    cin>>NTC;

    #ifdef PREPROCESS
        preprocess();
    #endif
    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        factorial();
    #endif 
        
    ll PTC=0;
    while((PTC++)<NTC){
        cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
