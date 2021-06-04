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

string to_string(string s) {return '"' + s + '"';}string to_string(const char* s) {return to_string((string) s);}string to_string(bool b) {return (b ? "true" : "false");}template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A>string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}void debug_out() { cerr << "\n"; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n";debug_out(T...);} 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

inline ll gcd(ll a,ll b) {if(b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a,ll b) {return((a > b) ? a : b);}
inline ll min(ll a,ll b) {return((a > b) ? b : a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e3 + 2;
bool vis[N][N] , g1[N][N], g2[N][N];
string s1[N] , s2[N];
ll n , index1[N][N];
ll ct[N + 11];
ll dx[4]={1,-1,0,0};
ll dy[4]={0,0,1,-1};
ll len = 0;
bool ok = 1;


void dfs(ll i , ll j, ll val){
    vis[i][j] = 1;
    index1[i][j] = val;
    len++;

    rep(k , 4){
        ll x = i + dx[k];
        ll y = j + dy[k];

        if(x >= 0 && x < n && y >= 0 && y < n){
            if(!vis[x][y] && g1[x][y]){
                dfs(x , y , val);
            }
        }
    }
}

void dfs2(ll i , ll j , ll index){
    len++;
    if(index1[i][j] != index) ok = 0;
    if(!g1[i][j]) ok = 0;

    vis[i][j] = 1;
    rep(k , 4){
        ll x = i + dx[k];
        ll y = j + dy[k];

        if(x >= 0 && x < n && y >= 0 && y < n){
            if(!vis[x][y] && g2[x][y]){
                dfs2(x , y , index);
            }
        }
    }
}
void solve(){
    cin >> n;

    rep(i , n) cin >> s1[i];    
    
    ll m;
    cin >> m;

    rep(i , n){
        cin >> s2[i];
    }

    rep(i , n){
        rep(j , n){
            if(s1[i][j] == '1') g1[i][j] = 1;
            if(s2[i][j] == '1') g2[i][j] = 1;
        }
    }


    ll index = 1;
    rep(i , n){
        rep(j , n){
            if(!vis[i][j] && g1[i][j]){
                len = 0;
                dfs(i , j , index);
                ct[index] = len;
                index++;
            }
        }
    }

    // rep(i , n){
    //     rep(j , n) cout << g1[i][j];
    //     cout << "\n";
    // }
    //     cout << "\n";
    // rep(i , n){
    //     rep(j , n) cout << g2[i][j];
    //     cout << "\n";
    // }
    //     cout << "\n";
    //     cout << "\n";
    // rep(i , n){
    //     rep(j , n) cout << vis[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
    // rep(i , n){
    //     rep(j , n) cout << index1[i][j] << " ";
    //     cout << "\n";
    // }


    ll ans = 0ll;
    rep(i , n) rep(j , n) vis[i][j] = 0;
    rep(i , n){
        rep(j , n){
            if(g2[i][j] && !vis[i][j]){
                ll val = index1[i][j];
                if(index1[i][j] == 0) val = -1;
                len = 0;
                ok = 1;
                dfs2(i , j , val);
                if(ok && len == ct[val]) ans++;
            }
        }
    } 

    cout << ans << "\n";
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
