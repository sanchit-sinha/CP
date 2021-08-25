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

const ll N = 5e4 + 11;


void solve(){
    ll n , m , k;
    vector<pair< pll , ll > > v;

    cin >> n;
    vll arrival(n , 0) , departure(n , 0) , profit(n , 0);
    rep(i , n) cin >> arrival[i];

    cin >> m;
    rep(i , m){
        cin >> departure[i];
        departure[i] += arrival[i];
    }

    cin >> k;
    rep(i , k) cin >> profit[i];

    rep(i , n){
        v.pb(mp(mp(departure[i] , arrival[i]) , -profit[i]));
    }

    sort(all(v));

    vector<pll> departure_store;
    rep(i , n){
        departure_store.pb(mp(v[i].f.f , i));
    }

    // rep(i , n) cout << v[i].f.s << " " << v[i].f.f << " " << v[i].s << " : " << pfx[i] << "\n";

    vll dp(n + 11 , 0); // dp[i] -> max profit till the end time of (sorted) job i 
    dp[0] = -v[0].s;

    FOR(i , 1 , n - 1){
         // take job i 
        ll profiti = -v[i].s;
        dp[i] = profiti; // only jobi

        ll endtime = v[i].f.f;
        ll starttime = v[i].f.s;
        auto it = lb(all(departure_store) , mp(starttime , inf));
        if(it != departure_store.begin()){
            it--;
            pll p = *it;
            dp[i] = max(dp[i] , dp[p.s] + profiti);
        } 

        // not take job i 
        dp[i] = max(dp[i] , dp[i - 1]);
    }

    cout << dp[n - 1] << "\n";
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
