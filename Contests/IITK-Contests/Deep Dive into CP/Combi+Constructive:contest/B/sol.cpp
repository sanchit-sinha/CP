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

const ll N = 2e6+11;

#define SIEVE
const ll mX = N;
bool prime[mX + 11]; 
void sieve(){ 
    memset(prime,true,sizeof(prime)); 
    for (ll p = 2 ; p*p <= mX ; p++){ 
        if (prime[p] == true) { 
            for (ll i = p*p ; i <= mX; i += p) prime[i] = false; 
        } 
    } 
}
void solve(){
    ll n;
    cin >> n;

    vll a(n);
    rep(i , n) cin >> a[i];
    
    vll b;
    rep(i , n) if(a[i] > 1) b.pb(a[i]);

    ll ans1 = 0 , ans2 = 0;
    ll ans = 0;
    vll pr1 , pr2;

    // odd , even => check
    rep(i , sz(b)){
        bool got = 0;
        rep(j , sz(b)){
            if(i != j && prime[b[i] + b[j]]){
                ans1 = 2;
                got = 1;
            
                pr1.pb(b[i]);
                pr1.pb(b[j]);
                break;
            }
        }
        if(got) break;
    }


    // can contain ones;
    ans2 = n - sz(b);
    if(ans2){
        rep(i , ans2) pr2.pb(1);

        // ones + odd & even
        rep(i , sz(b)){
            bool got = 1;
            rep(j , sz(b)){
                if(i != j){
                    if(prime[b[i] + 1] && prime[b[j] + 1] && prime[b[i] + b[j]]){
                        ans2 += 2;
                        pr2.pb(b[i]);
                        pr2.pb(b[j]);

                        ans = max(ans1 , ans2);

                        cout << ans << "\n";
                        if(ans == sz(pr1)) rep(k , sz(pr1)) cout << pr1[k] << " ";
                        else rep(k , sz(pr2)) cout << pr2[k] << " ";
                        cout << "\n"; 

                        return;
                    }
                }
            }
        }

        // ones + odd or even
        rep(i , sz(b)){
            if(prime[b[i] + 1]){
                ans2++;
                pr2.pb(b[i]);


                ans = max(ans1 , ans2);
                cout << ans << "\n";
                if(ans == sz(pr1)) rep(k , sz(pr1)) cout << pr1[k] << " ";
                else rep(k , sz(pr2)) cout << pr2[k] << " ";
                cout << "\n";   
                
                return;
            }
        }
    }

    ans = max(ans1 , ans2);
    if(ans == 0){
        cout << 1 << "\n" << a[0] << "\n";        
    }
    else{
        cout << ans << "\n";
        
        if(ans == sz(pr1)) rep(k , sz(pr1)) cout << pr1[k] << " ";
        else rep(k , sz(pr2)) cout << pr2[k] << " ";
        cout << "\n";
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
