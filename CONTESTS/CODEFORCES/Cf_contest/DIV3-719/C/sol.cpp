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

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5+11;

ll dx[4]={1,-1,0,0};
ll dy[4]={0,0,1,-1};
void solve(){
    ll n;
    cin >> n;


    vvll ans(n + 1 , vll(n + 1 , 0));
    ll x = 1;

    FOR(i ,1 , n){
        if(i&1) for(ll j = 1 ; j <= n ; j += 2) ans[i][j] = x++;
        else for(ll j = 2 ; j <= n ; j += 2) ans[i][j] = x++;
    }


    FOR(i ,1 , n){
        if(i%2 == 0) for(ll j = 1 ; j <= n ; j += 2) ans[i][j] = x++;
        else for(ll j = 2 ; j <= n ; j += 2) ans[i][j] = x++;
    }

    bool ok = 1;
    FOR(i ,1 ,n){
        FOR(j ,1 , n){
            rep(k , 4){
                ll xx = i + dx[k];
                ll yy = j + dy[k];

                if(xx <= n && yy <= n && xx >= 1 && yy >= 1){
                    if(abs(ans[xx][yy] - ans[i][j]) == 1) ok = 0 ;
                }
            }
        }
    }

    if(ok){
        rep(i , n){
            rep(j , n) cout << ans[i + 1][j + 1] << " ";
            cout << "\n";
        }
        cout << "\n";
    }
    else cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
   
    ll NTC=1;
    cin>>NTC;

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
