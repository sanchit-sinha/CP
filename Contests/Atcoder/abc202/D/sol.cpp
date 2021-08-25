#include "bits/stdc++.h"
using namespace std;
#define f                   first
#define s                   second
#define pb                  push_back
#define ll                  unsigned long long
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

const ll N = 62;
ll dp[N + 11][N + 11];

#define PREPROCESS
void preprocess(){ 
    dp[0][0] = dp[1][0] = 1;

    FOR(i , 1 , N - 1){
        dp[i][0] = 1;
        FOR(j , 1 , N - 1){
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
}
    
void solve(){
    ll a , b , k;
    cin >> a >> b >> k;

    string s;
    rep(i , a) s.pb('a');
    rep(i , b) s.pb('b');

    // rep(i , a){
    //     rep(j , b) cout << i << " " << j << " : " << dp[i][j] << "\n"; 
    // }

    if(k == 0){
        cout << s << "\n";
        return;
    }

    string ans(a + b , '?');
    ll ct = 0;
    FOR(i , 1 , a + b){
        if(ct == a) break; 
        ll mx = dp[a + b - i][a - (ct + 1)];
        if(k <= mx){
            ans[i - 1] = 'a';
            ct++;
        }
        else{
            ans[i - 1] = 'b';
            k -= mx;
        }
    }

    rep(i , a + b) if(ans[i] == '?') ans[i] = 'b';
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
