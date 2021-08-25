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
    ll n;
    cin >> n;

    vector<string> v;
    ll mx = 0 ;
    rep(i , n){
        string s;
        cin >> s;

        v.pb(s);
        mx = max(mx , sz(v[i]));
    }

    string t;
    cin >> t;

    vvll ct(26 , vll(mx ,  0));
    vvll pfx(26 , vll(mx ,  0));
    rep(i , n){
        rep(j , sz(v[i])){
            ct[v[i][j] - 'a'][j]++;
        }
    }

    rep(i , 26){
        FOR(j , 1 , mx - 1){
            pfx[i][j] += (pfx[i][j - 1] + ct[i][j]);
        }
    }

    ll len = sz(t);
    vvll dp(len + 1 , vll (mx + 1 , 0));

    // base 
    ll d = t[0] - 'a';
    rep(j , mx) dp[0][j] = ct[d][j];
    vll pfxx(mx + 1 , 0);
    rep(j , mx){
        (j == 0) ? (pfxx[0] = dp[0][j]) : (pfxx[j] = pfxx[j - 1] + dp[0][j]);
        pfxx[j] %= mod;
    }


    FOR(i , 1 , len - 1){
        ll x = t[i] - 'a';
        ll y = t[i - 1] - 'a';

        FOR(j , 1 , mx - 1){
            dp[i][j] = (ct[x][j] * pfxx[j - 1]);
            dp[i][j] %= mod;
        }

        pfxx[0] = dp[i][0];
        FOR(j , 1 , mx - 1){
            pfxx[j] = pfxx[j - 1] + dp[i][j];
            pfxx[j] %= mod;
        }
    }    
    cout << pfxx[mx - 1] << "\n";

    // FOR(i , 1 , len - 1){
    //     ll x = t[i] - 'a';
    //     ll y = t[i - 1] - 'a';

    //     trav(it1 , ct[x]){
    //         trav(it2 , ct[y]){
    //             ll xx = it1->f;
    //             ll yy = it2->f;
            
    //             if(xx > yy) dp[i][xx] += (dp[i - 1][yy] * it1->s);
    //             dp[i][xx] %= mod;
    //         }
    //     }

    // }


    // ll ans = 0ll;
    // d = t[len - 1] - 'a';
    // trav(it , ct[d]){
    //     ans += dp[len - 1][it->f];
    //     ans %= mod;
    // }

    // cout << ans << "\n";
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
