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

string to_string(string s) {return '"' + s + '"';}string to_string(const char* s) {return to_string((string) s);}string to_string(bool b) {return (b ? "true" : "false");}template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A>string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}void debug_out() { cerr << "\n"; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n";debug_out(T...);} 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

inline ll gcd(ll a,ll b) {if(b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a,ll b) {return((a > b) ? a : b);}
inline ll min(ll a,ll b) {return((a > b) ? b : a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;


void solve(){
    string s;
    cin >> s;

    ll n = sz(s);

    vvll dp(n , vll(4 , n + 1)); // 0 : 0 , 2 ; 
    // 1 : 1 , 3
    if(s[0] == '?') dp[0][2] = dp[0][3] = 0;
    else dp[0][s[0] - '0'] = 0;

    FOR(i , 1 , n - 1){
        if(s[i] == '1'){
            dp[i][1] = i;
            if(s[i - 1] == '0') dp[i][1] = min(dp[i][1] , dp[i - 1][0]);
            else if(s[i - 1] == '?') dp[i][1] = min(dp[i][1] , dp[i - 1][2]);
        }
        else if(s[i] == '0'){
            dp[i][0] = i;
            if(s[i - 1] == '1') dp[i][0] = min(dp[i][0] , dp[i - 1][1]);
            else if(s[i - 1] == '?') dp[i][0] = min(dp[i][0] , dp[i - 1][3]);
        }
        else{
            dp[i][2] = dp[i][3] = i;
            // i = 2 , 0
            if(s[i - 1] == '1') dp[i][2] = min(dp[i][2] , dp[i - 1][1]);
            else if(s[i - 1] == '?') dp[i][2] = min(dp[i][2] , dp[i - 1][3]);

            // i = 3 , 1
            if(s[i - 1] == '0') dp[i][3] = min(dp[i][3] , dp[i - 1][0]);
            else if(s[i - 1] == '?') dp[i][3] = min(dp[i][3] , dp[i - 1][2]);

        }
    }

    ll ans = 0ll;

    rep(i , n){
        if(s[i] != '?') ans +=(i - dp[i][s[i] - '0'] + 1);
        else{
            ll mn = min(dp[i][3] , dp[i][2]);
            ans += (i - mn + 1);
        }
    }

    cout << ans << "\n";
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
