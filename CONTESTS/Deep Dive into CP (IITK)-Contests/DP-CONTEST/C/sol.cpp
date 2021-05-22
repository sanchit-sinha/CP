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

const ll N = 2e3+11;
ll n , k;
string s[N];
pll mnmx_col[N] , mnmx_row[N]; // min , max index position in a row or col

/* check if it is possible to make a col/row completely white 
    from the bottom-most position for columns 
    and from rightmost position for rows */
bool check(pll p , ll x){
    ll mn = p.f;
    ll mx = p.s;

    if(mn == inf) return 0;
    ll dif = mx - mn + 1;
    if(dif > k) return 0;

    ll mnposition = mx;
    ll mxposition = mn + k - 1;

    if(x > mxposition || x < mnposition) return 0;
    return 1; // white line increases
}

vvll dpsolve(vpll &pos){
    vvll dp(n , vll(n , 0));

    FOR(j , 0 , n - k){
        //base 
        rep(i , k){
            dp[0][j] += 1ll * check(pos[i] , k + j - 1);
        }

        FOR(i , 1 , n - k){
            dp[i][j] = dp[i - 1][j];
            dp[i][j] -= 1ll * check(pos[i - 1] , k + j - 1);
            dp[i][j] += 1ll * check(pos[i + k - 1] , k + j - 1);
        }
    }

    return dp;
}
void solve(){
    cin >> n >> k;
    rep(i , n) cin >> s[i];

    // precomputation
    rep(i , n){
        mnmx_row[i] = {inf , -inf};
        mnmx_col[i] = {inf , -inf};
    }

    rep(i , n){
        rep(j , n){
            if(s[i][j] == 'B'){
                ll mnr = min(j , mnmx_row[i].f);
                ll mxr = max(j , mnmx_row[i].s);

                ll mnc = min(i , mnmx_col[j].f);
                ll mxc = max(i , mnmx_col[j].s);

                mnmx_row[i] = {mnr , mxr};
                mnmx_col[j] = {mnc , mxc};
            } 
        }
    }

    vpll pos1 , pos2;
    rep(i , n) pos1.pb(mnmx_row[i]);
    rep(i , n) pos2.pb(mnmx_col[i]);

    vvll dp1 = dpsolve(pos1);   
    vvll dp3 = dpsolve(pos2);   
       
    vvll dp2 = dp3;
    rep(i , n){
        rep(j , n) dp2[i][j] = dp3[j][i];
    }    

    // cout << " dp1 \n";
    // rep(i , n){
    //     rep(j , n) cout << dp1[i][j] << " ";
    //     cout << "\n";
    // }

    // cout << "dp2\n";
    // rep(i , n){
    //     rep(j , n) cout << dp2[i][j] << " ";
    //     cout << "\n";
    // }

    ll original = 0;
    rep(i , n) if(pos1[i].f == inf) original++;
    rep(i , n) if(pos2[i].f == inf) original++;
    // cout << " original " << original << "\n";

    ll ans = 0;
    rep(i , n){
        rep(j , n) ans = max(ans , original + dp1[i][j] + dp2[i][j]);
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
