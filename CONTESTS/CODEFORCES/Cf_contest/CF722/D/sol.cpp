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

const ll N = 1e6+11;

// saw the editorial
// it may not be good to solve the complementary problem for each counting problem 

ll n;
ll dp[N];
ll dpsum[N];
/* 
Let dp[i] be the answer for 2i points 
    Here, we have two case :
    Let, x be the ending point of the segment starting at 1 
        1) x <= i 
            In this case, all the segment has to be of equal length, otherwise we can find "any" two segment not satisying the given criteria.
            This boils down to the fact that the number of possible cases(having x <= i) will be a factor of i       
            Ans for this case will be the total factors of i

        2) x > i
            In this case, [1 , 2 , ,, ,, (2i + 1 - x)] will be paired with [x, x + 1 , , , 2i]
            This boils down to the fact that now we have a subcase of length 2( x - i - 1) that is the segment [(2i + 1 - x + 1) ... (x - 1)] 
            Ans for this case will be summation of dp[x - i - 1] for x = [i + 1 , 2i] 
                                      = summation of dp[r] for r = 0 to i - 1   

    Therefore, dp[i] = (total factors of i) + (summation of dp[r] for r = 0 to i - 1)
*/
ll factors[N];
void solve(){
    cin >> n;
    
    ll mX = n + 1;
    factors[1] = 1;
    for(ll i = 2 ; i < mX ; i++){
        factors[i]++;
        for (ll j = 1ll * i ; j < mX ; j += i){
            factors[j]++;
        }
    }

    FOR(i , 1 , n){
        dp[i] = factors[i] + dpsum[i - 1];
        dp[i] %= mod;

        dpsum[i] = dpsum[i - 1] + dp[i];
        dpsum[i] %= mod;
    }

    cout << dp[n] << "\n";
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
