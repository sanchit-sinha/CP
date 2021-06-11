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

    vvll a(n , vll(n , 0));
    rep(i , n){
        rep(j , n) cin >> a[i][j];
    }

    vvll dp(n , vll(n , -1)); // 0,0 to i,j max coins 
    vvll dpr(n , vll(n , -1)); //i , jto 0 , 0  max coins 
    vector<vpll> save(n , vpll(n , mp(-1 , -1))); // 0,0 to i,j max coins 

    dp[0][0] = a[0][0];
    for(ll i = 1 ; i < n ; i++){ // row 
        if(a[0][i] != -1){
            dp[0][i] = dp[0][i - 1];
            if(dp[0][i] > -1){
                save[0][i] = mp(0 , i - 1);
                dp[0][i] += a[0][i];
            }
        }
    }

    for(ll i = 1 ; i < n; i++){
        if(a[i][0] != -1){
            dp[i][0] = dp[i - 1][0];
            if(dp[i][0] > -1){
                save[i][0] = mp(i - 1 , 0);
                dp[i][0] += a[i][0];
            }
        }       
    }


    FOR(i , 1 , n - 1){
        FOR(j , 1 , n - 1){
            if(a[i][j] != -1){
                dp[i][j] = max({dp[i][j] , dp[i - 1][j] , dp[i][j - 1]});

                if(dp[i][j] > -1){
                    if(dp[i][j] == dp[i - 1][j]) save[i][j] = mp(i - 1 , j);
                    else if(dp[i][j] == dp[i][j - 1]) save[i][j] = mp(i , j - 1);
                    
                    dp[i][j] += a[i][j];
                }
            }
        }
    }

    if(dp[n - 1][n - 1] < 0) cout << 0 << "\n"; 
    else{
        ll l = n - 1 , r = n - 1;
        while(l >= 0 && r >= 0){
            a[l][r] = 0;
            ll indexl = save[l][r].f;
            ll indexr = save[l][r].s;

            l = indexl , r = indexr;
        }

        a[0][0] = a[n - 1][n - 1] = 0;


        // rep(i , n){
        //     rep(j , n) cout << a[i][j] << " ";
        //     cout << "\n";
        // }
        // cout << "\n";


        dpr[n - 1][n - 1] = a[n - 1][n - 1];

        FORR(i , n - 2 , 0){
            if(a[i][n - 1] != -1){
                dpr[i][n - 1] = dpr[i + 1][n - 1];
                if(dpr[i][n - 1] > -1){
                    dpr[i][n - 1] += a[i][n - 1];
                }
            }
        }

        FORR(i , n - 2 , 0){
            if(a[n - 1][i] != -1){
                dpr[n - 1][i] = dpr[n - 1][i + 1];
                if(dpr[n - 1][i] > -1){
                    dpr[n - 1][i] += a[n - 1][i];
                }
            }
        }

        FORR(i , n - 2 , 0){
            FORR(j , n - 2 , 0){
                if(a[i][j] != -1){
                    dpr[i][j] = max({dpr[i][j] , dpr[i + 1][j] , dpr[i][j + 1]});

                    if(dpr[i][j] > -1){
                        dpr[i][j] += a[i][j];
                    }
                }
            }
        }


        cout << dp[n - 1][n - 1] + dpr[0][0] << "\n";

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
