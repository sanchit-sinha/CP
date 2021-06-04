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
#define rep(i, n)           for(int i = 0 ; i < n ; i++)
#define FOR(i, a, b)        for(int i = a ; i <= b; i++)
#define FORR(i, b, a)       for(int i = b ; i >= a; i--)

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


void solve(){
    ll n;
    cin >> n;

    ll sum = (n*(n + 1))/2;
    if(sum&1){
        cout << "NO\n";
        return;
    }

    ll present_sum = 0;
    bool vis[n + 1] = {0};

    bool got = 0;
    FORR(i , n , 1){
        vis[i] = 1;
        present_sum += i;
        if(present_sum == sum/2){
            got = 1;
            break;
        }
        else if(present_sum > sum/2){
            vis[i] = 0;
            present_sum -= i;
            
            if((sum/2) - present_sum < i){
                vis[(sum/2) - present_sum] = 1;
                got = 1;
            }
            break;
        }
    }

    if(!got){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    ll ct = 0;
    rep(i , n) ct += (vis[i + 1] == 1);

    cout << ct << "\n";
    FOR(i , 1 , n) if(vis[i]) cout << i << " ";
    cout << "\n";

    cout << (n - ct) << "\n";
    FOR(i , 1 , n) if(!vis[i]) cout << i << " ";
    cout << "\n";
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
                                