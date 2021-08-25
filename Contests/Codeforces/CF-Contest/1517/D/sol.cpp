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
#define rep(i, n)           for(int i = 0 ; i < n ; i++)
#define FOR(i, a, b)        for(int i = a ; i <= b; i++)
#define FORR(i, b, a)       for(int i = b ; i >= a; i--)

inline ll gcd(ll a,ll b) {if(b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a,ll b) {return((a > b) ? a : b);}
inline ll min(ll a,ll b) {return((a > b) ? b : a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = INT_MAX;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 500+11;
ll n , m , k;
vector<pair<pll , ll>> v[N][N];
void solve(){
    cin >> n >> m >> k;

    FOR(i ,1,n){
        FOR(j , 1, m){
            ll index1 = i;
            ll index2 = j + 1;
            if(index2 <= m){
                ll x;
                cin >> x;

                v[i][j].pb(mp(mp(index1 , index2) , x));
                v[index1][index2].pb(mp(mp(i , j) , x));
            }            
        }
    }

    FOR(i ,1,n){
        FOR(j , 1, m){
            ll index1 = i + 1;
            ll index2 = j;
            if(index1 <= n){
                ll x;
                cin >> x;

                v[i][j].pb(mp(mp(index1 , index2) , x));
                v[index1][index2].pb(mp(mp(i , j) , x));
            }            
        }
    }

    vector<vvll> dp(n + 1 , vvll(m + 1 , vll(k/2 + 2 , inf)));
    FOR(i ,1 , n){
        FOR(j ,1 , m) dp[i][j][0] = 0ll;
    }
    // dp[i][j][k] => min boredon attained on moving exactly k moves from (i , j)
    FOR(p , 1 , k/2){
        FOR(i ,1 ,n){
            FOR(j ,1, m){
                for(auto child : v[i][j]){
                    ll xx = child.f.f;
                    ll yy = child.f.s;

                    ll wt = child.s;
                    dp[i][j][p] = min(dp[i][j][p] , dp[xx][yy][p - 1] + wt);
                }
            }
        }
    }

    FOR(i ,1, n){
        FOR(j, 1 , m){
            if(k&1) cout << -1 << " ";
            else if(dp[i][j][k/2] >= inf) cout << -1 << " ";
            else cout << 2*dp[i][j][k/2] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
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
