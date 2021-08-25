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
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5+11;
const ll mX = N;
/* 
    FINDING INVERSE : 
    1) if mod is prime, then use fermat's little theorem
                                        => inverse = powermod(base , mod - 2 , mod);
    2) if mod is not prime but mod and base are co-prime, then use euler's totient function 
                                        => inverse = powermod(a , phi(mod) - 1 , mod);

*/ 
void solve(){
    ll n;
    cin >> n;

    vll a(n) , b(n);
    map<ll , ll> m , same;
    rep(i , n) cin >> a[i] , m[a[i]]++;
    rep(i , n) cin >> b[i] , m[b[i]]++;

    ll modd; cin >> modd;

    // here it is a special case to divide by 2!s only, which can be done by adjusting the factorials 
    rep(i , n){
        if(a[i] == b[i]){
            same[a[i]]++;
        }
    }

    ll ans = 1ll;

    // complexity O(2n logn)
    trav(it,  m){
        ll cnt = it->s;
        ll div = same[it->f];

        ll fact = 1ll;
        FORR(i , cnt , 1){
            ll mul = i;
            while(mul%2 == 0 && div) mul /= 2, div--;
            fact *= mul;
            fact %= modd;
        }

        ans *= fact;
        ans %= modd;
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
