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
ll time_taken[2][N][N]; 
pll persons_loc , save[N][N];
vpll monsters_loc;
bool vis[N][N];

void bfs(ll index , vpll &monsters_loc){
    queue<pll> q;
    rep(k , sz(monsters_loc)){
        pll p = monsters_loc[k];
        vis[p.f][p.s] = 1;
        time_taken[index][p.f][p.s] = 0;
        q.push(p);
    }

    while(!q.empty()){
        pll cur = q.front();
        q.pop();
        rep(k , 4){
            ll i = cur.f + dx[k];
            ll j = cur.s + dy[k];

            if(i < n && j < m && i >= 0 && j >= 0){
                if(s[i][j] != '#' && !vis[i][j]){
                    vis[i][j] = 1;
                    time_taken[index][i][j] = time_taken[index][cur.f][cur.s] + 1;
                    if(index == 0) save[i][j] = cur;
                    q.push({i , j});
                }
            }
        }
    }
}
char convert(pll from , pll to){
    ll x1 = from.f , y1 = from.s;
    ll x2 = to.f , y2 = to.s;

    if(x2 == x1 + 1 && y1 == y2) return 'D';
    if(x2 == x1 - 1 && y1 == y2) return 'U';
    if(x2 == x1 && y1 + 1 == y2) return 'R';
    if(x2 == x1 && y1 - 1 == y2) return 'L';

    return '?';
}
void solve(){
    cin >> n >> m;
    rep(i , n) cin >> s[i];

    rep(i , n) rep(j , m) rep(k , 2) time_taken[k][i][j] = inf;

    rep(i , n){
        rep(j , m){
            if(s[i][j] == 'A') persons_loc = {i , j};
            else if(s[i][j] == 'M') monsters_loc.pb({i , j});
        }
    }

    vpll index;
    index.pb(persons_loc);
    bfs(0 , index);
    rep(i , n) rep(j , m) vis[i][j] = 0;
    bfs(1 , monsters_loc);

    bool got = 0;
    pll persons_final = {-1 , -1};
    rep(i , n){
        rep(j , m){
            if(i == 0 || i == n - 1){
                if(s[i][j] != '#'){
                    if(time_taken[0][i][j] < time_taken[1][i][j]){
                        persons_final = {i , j};
                        got = 1;
                        break;
                    }
                }
            }

            if(j == 0 || j == m - 1){
                if(s[i][j] != '#'){
                    if(time_taken[0][i][j] < time_taken[1][i][j]){
                        persons_final = {i , j};
                        got = 1;
                        break;
                    }
                }
            }
        }
        if(got) break;
    }

    if(!got) cout << "NO\n";
    else{
        cout << "YES\n";
        string ans;
        pll cur = persons_final;
        while(cur != persons_loc){
            ans.pb(convert(save[cur.f][cur.s] , cur));
            cur = save[cur.f][cur.s];
        }

        cout << sz(ans) << "\n";
        reverse(all(ans));
        cout << ans << "\n";
    }
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
