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
const ll N = 3e5 + 11;
ll q , a0 , c0;
ll up[N][21];
ll a[N] , c[N] , dis[N];

void update(ll pr , ll node){
    dis[node] = dis[pr] + 1;

    up[node][0] = pr;
    FOR(j , 1 , 20){
        ll upper = up[node][j - 1];
        up[node][j] = up[upper][j - 1];
    }
}

ll ancestor(ll node){
    FORR(j , 20 , 0){
        ll pr = up[node][j];
        if(a[pr] > 0) node = pr;
    }
    return node;
}
ll climb(ll node , ll d){
    FORR(j , 20 , 0){
        if(d & (1ll << j)){
            node = up[node][j];
        }
    }

    return node;
}
void solve(){
    cin >> q >> a0 >> c0;

    a[0] = a0 , c[0] = c0;
    up[0][0] = 0;
    FOR(i , 1 , q){
        ll t;
        cin >> t;

        if(t == 1){
            ll p , anode , coin;
            cin >> p >> anode >> coin;
        
            ll node = i;
            a[node] = anode;
            c[node] = coin;
        
            update(p , node); // update up
        }
        else{
            ll node , wt;
            cin >> node >> wt;

            ll top = ancestor(node);
            ll dd = dis[node] - dis[top];

            ll ans = 0ll;
            ll gold = 0ll;
            FORR(j , dd , 0){
                ll top = climb(node , j);
                if(a[top] <= wt){
                    ans += (a[top] * c[top]);
                    gold += a[top];
                    wt -= a[top];
                    a[top] = 0;
                }
                else{ // atop > w
                    ans += (wt * c[top]);
                    gold += wt;
                    a[top] -= wt;
                    wt = 0;
                    break;
                }
            }


            cout << gold << " " << ans << "\n";
            cout.flush();
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
