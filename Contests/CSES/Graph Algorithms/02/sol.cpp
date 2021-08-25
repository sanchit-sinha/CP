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

const ll N = 1e3+11;
ll n , m;
ll dx[4]={1,-1,0,0};
ll dy[4]={0,0,1,-1};
string s[N];
pll path[N][N];
bool vis[N][N];
pll start , endi;

void bfs(ll x , ll y){
    queue<pll> q;
    q.push({x , y});
    vis[x][y] = 1;

    if(mp(x , y) == endi) return;
    while(!q.empty()){
        pll p = q.front();
        q.pop();

        rep(k , 4){
            ll i = p.f + dx[k];
            ll j = p.s + dy[k];

            if(i >= 0 && i < n && j >= 0 && j < m){
                if(s[i][j] != '#' && !vis[i][j]){
                    vis[i][j] = 1;
                    q.push({i , j});
                    path[i][j] = p;
                }
            }
        }
    }
}

char convert(pll from , pll to){
    ll fromx = from.f;
    ll fromy = from.s;

    ll tox = to.f;
    ll toy = to.s;

    // cout << "( " << from.f << " " << from.s << ") => (" << to.f << " " << to.s << " )\n";

    if(fromx  == tox - 1 && fromy == toy) return 'D';
    if(fromx  == tox + 1 && fromy == toy) return 'U';
    if(fromx == tox && fromy == toy + 1) return 'L';
    if(fromx == tox && fromy == toy - 1) return 'R';

    return '?';
}
void solve(){
    cin >> n >> m;
    rep(i , n) cin >> s[i];

    rep(i , n){
        rep(j , m){
            if(s[i][j] == 'A') start = {i , j};
            else if(s[i][j] == 'B') endi = {i , j};
        }
    }

    rep(i , n) rep(j , m) path[i][j] = {-1 , -1};
    bfs(start.f  , start.s);

   
    if(vis[endi.f][endi.s]){
        cout << "YES\n";
        
        string ans;
        pll child = endi;
        pll parent = path[child.f][child.s];
        while(parent.f != -1 && parent.s != -1){
            ans.pb(convert(parent , child));
            child = parent;
            parent = path[child.f][child.s];
            if(child == start) break;
        }

        cout << sz(ans) << "\n";
        reverse(all(ans));
        cout << ans << "\n";
    } 
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
   
    ll NTC=1;
    // cin>>NTC;

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
