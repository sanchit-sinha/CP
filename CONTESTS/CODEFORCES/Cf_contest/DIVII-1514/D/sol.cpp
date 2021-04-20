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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll range(ll l ,ll r){
    ll n = uniform_int_distribution<int> (l , r)(rng);
    return n;
}
void solve(){
    ll n , q;
    cin >> n >> q;     

    vll a(n + 1);
    vll m[n + 1];
    rep(i , n){
        ll x;
        cin >> x;
        a[i + 1] = x;
        m[x].pb(i + 1);
    }

    while(q--){
        ll l , r;
        cin >> l >> r;

        /* Randomised solution for finding mode 
            Probability of finding not_mode < 1/2
            Probability of finding not_mode in 40 iterations < (1/2)^(40) which is quite small
                    Hence, it is high chance that we would get a mode */

        ll f = 0;
        rep(j , 40){
            ll index = range(l , r);
            ll ele = a[index];
            
            auto itu = ub(all(m[ele]) , r);
            auto itl = lb(all(m[ele]) , l);
            
            f = max(f , itu - itl);
        }


        ll len = (r - l + 1);
        if(f <= (len + 1)/2) cout << 1 << "\n";
        else{
            /* mode mode mode (... ftimes)  not_mode not_mode not_mode ((len - f) times)
                put max modes with all not_modes in one partition => ct of mode remaining = f - (len - f + 1) = 2f - len - 1
                // remaining modes will occupy one partition each
            Total partitions = (1 + (2f - len - 1)) = 2f - len */
            cout << 2*f - len << "\n";
        }   
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
