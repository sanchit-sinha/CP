#include "bits/stdc++.h"
using namespace std;
#define f                   first
#define s                   second
#define pb                  push_back
#define ll                  long long
#define ld                  long double
#define lb                  lower_bound
#define ub                  upper_bound
#define mp                  make_pair
#define mt                  make_tuple
#define pll                 pair<ll , ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (int)(c.size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

inline ll gcd(ll a,ll b) {if(b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a,ll b) {return((a > b) ? a : b);}
inline ll min(ll a,ll b) {return((a > b) ? b : a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5+11;
ll n , l[N] , r[N], dp[N][4]; // 0 - l , 1 - floor , 2 - ceil , 3 - r
vll v[N];
bool vis[N];
ll a[N][4];
void dfs(ll node){
    vis[node] = 1;
    for(auto child : v[node]){
        if(!vis[child]){
            dfs(child);

            // completed childs task 
            rep(j , 4){ // for node 
                ll val = 0;
                rep(k , 4){ // for child 
                    val = max(val , dp[child][k] + abs(a[node][j] - a[child][k]));
                }
                dp[node][j] += val;
            }            
        }
    }
}
void solve(){
    // clear
    rep(i , n + 1){
        v[i].clear();
        l[i] = r[i] = 0;
        vis[i] = 0;
        rep(j , 4) dp[i][j] = a[i][j] = 0;
    }

    cin >> n;
    rep(i , n) cin >> l[i + 1] >> r[i + 1];

    FOR(i , 1 , n){
        ll x = l[i] , y = r[i];
        ll flr = (x + y)/2 , cil = (x + y + 1)/2;

        a[i][0] = x;
        a[i][1] = flr;
        a[i][2] = cil;
        a[i][3] = y;
    }
    rep(i , n - 1){
        ll x , y;
        cin >> x >> y;

        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1);

    // debug
    // cout << "DIS\n";
    // FOR(i , 1 , n){
    //     v[i].clear();
    //     cout << i << ":  ";
    //     rep(j , 4) cout << a[i][j] << " ";
    //     cout << "\n";
    // }

    // cout << "DP\n";
    // FOR(i , 1 , n){
    //     cout << i << ":  ";
    //     rep(j , 4) cout << dp[i][j] << " ";
    //     cout << "\n";
    // }

    ll ans = 0;
    rep(j , 4) ans = max(ans , dp[1][j]);

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
   
    ll NTC=1;
    cin >> NTC;

    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        factorial();
    #endif 
    #ifdef PREPROCESS
        preprocess();
    #endif
    
    ll PTC=0;
    while((PTC++)<NTC){
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
