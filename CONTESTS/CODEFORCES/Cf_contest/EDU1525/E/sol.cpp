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
const ll mod = 998244353;
const ld PI = acos(-1);
const ld eps = 1e-9;


// commented solution :) 
const ll N = 30;

#define NCR
const ll mX = N;
ll fact[mX] , invfact[mX];
void factorial(){
    fact[0] = invfact[0] = 1;
    for(ll i = 1 ; i < mX ; i++){
        fact[i] = i * fact[i - 1];
        fact[i] %= mod;
    }
    invfact[mX - 1] = powermod(fact[mX - 1] , mod - 2 , mod);
    for(ll i = mX - 2 ; i > 0 ; i--){
        invfact[i] = invfact[i + 1] * (i + 1);
        invfact[i] %= mod;
    }
}
ll ncr(ll n , ll r){
    if(r > n || n < 0 || r < 0)return 0;
    ll p = (fact[n] * invfact[r]) % mod;
    p *= invfact[n - r];
    return p%mod;
}

void solve(){
    ll n, m;
    cin >> n >> m;

    vvll dis(n , vll(m , 0));
    rep(i , n){
        rep(j , m) cin >> dis[i][j];
    }   

    ll ans = 0;
    rep(i , m){
        vll v; // stores req distances of monuments to conquer ith point 
        rep(j , n) v.pb(dis[j][i]); // jth monument must be atleast dis[j][i] away to conquer the ith point
    
        /* calculating no of times ith point is conquered in n! arrangements
            => no of arrangements such that 
                        (1st monument is atleast dis[1][i] distance away from ith point, 
                            or
                        2nd monument is atleast dis[2][i] distance away from ith point,
                            or
                            .
                            .
                        jth monument is atleast dis[j][i] distance away form ith point)
            
            => (n!) - no of arrangements st 
                        (1st monument's distance from point < dis[1][i]
                                and
                        2nd monument's distance from point < dis[2][i] ,
                                and
                                .
                                .
                        jth monument's distance from point < dis[j][i])

                        ---------------- calculated below (as x) -------
                                                                              */
        ll x = 1;
        sort(all(v));
        rep(i , n){
            x *= max(0 , v[i] - 1 - i);
            x %= mod;
        }

        ans += (fact[n] - x + mod)%mod;
        ans %= mod;
    }

    cout << (ans * invfact[n])%mod << "\n";
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
