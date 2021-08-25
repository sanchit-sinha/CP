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

const ll N = 1e5+11;

ll bs(ll start , ll &x){
    ll lo = 0 , hi = 1e9 , n = 0;
    while(lo <= hi){
        ll mid = lo + (hi - lo)/2;
        ll sum = (mid)*(start + mid - 1);
        if(sum <= x) n = mid , lo = mid + 1;
        else hi = mid - 1;
    }

    ll sum = (n)*(start + (n - 1));
    x -= sum;
    return start + (n - 1)*2;
}
void solve(){
    ll l , r;
    cin >> l >> r;

    ll mx = max(l , r);
    ll mn = min(l , r);

    ll lo = 0 , hi = 2e9 , ans = 0;
    while(lo <= hi){
        ll mid = lo + (hi - lo)/2;
        if((mid*(mid + 1))/2 <= mx - mn) ans = mid , lo = mid + 1;
        else hi = mid - 1;
    }

    if(l >= r) l -= (ans*(ans + 1))/2 ;
    else r -= (ans*(ans + 1))/2;

    bool first = 0;
    if(l >= r) first = 0;
    else first = 1;

    ll ans1 = 0 , ans2 = 0;
    if(first == 0){
        if(ans + 1 > l) ans1 = ans;
        else ans1 = bs(ans + 1 , l);
        
        if(ans + 2 > r) ans2 = ans;
        else ans2 = bs(ans + 2 , r);
    }
    else{
        if(ans + 1 > r) ans1 = ans;
        else ans1 = bs(ans + 1 , r);
        
        if(ans + 2 > l) ans2 = ans;
        else ans2 = bs(ans + 2 , l);
    }

    cout << max(ans1 , ans2) << " " << l << " " << r << "\n";

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
        cout << "Case #" << PTC << ":" << ' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
