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

const ll N = 10;
// vll b(N + 1 , 0);
ll ask(ll t , ll i , ll j , ll x){
    cout << "? " << t << " " << i << " " << j << " " << x << "\n";
    cout.flush();

    ll val;
    cin >> val;

    return val;

    // if(t == 1) return max(min(x , b[i]) , min(x + 1 , b[j]));
    // else{
    //     return min(max(x , b[i]) , max(x + 1 , b[j]));
    // }
}

void solve(){
    // b.clear();
    ll n;
    cin >> n;

    // rep(i , n) cin >> b[i + 1];

    vll a(n + 1 , 0);
    vector<bool> vis(n + 1 , 0);

    ll mnindex = n;
    for(ll j = 2 ; j <= n ; j += 2){
        ll i = j - 1;

        ll val = ask(2 , i , j , 1);
        ll x = i , y = j;
        if(val == 2){
            ll val3 = ask(2 , j , i , 1);
            if(val3 == 1){
                swap(x , y);
                val = 1;
            }
        }
        if(val == 1){   
            // assume i as mnindex
            ll val2 = ask(1 , x , y , n - 1);
            if(val2 != 1){
                mnindex = x;
                a[mnindex] = 1;
                vis[mnindex] = 1;
            }
            else{
                mnindex = y;
                a[mnindex] = 1;
                vis[mnindex] = 1;
            }

            break;
        }
    }

    vis[mnindex] = 1;
    a[mnindex] = 1;
    // cout << mnindex << "\n\n";
    FOR(i , 1 , n){
        if(!vis[i]){
            ll val = ask(1 , mnindex , i , n - 1);
            vis[i] = 1;
            a[i] = val;
        }
    }

    cout << "! ";
    rep(i , n)  cout << a[i + 1] << " ";
    cout << "\n";
    cout.flush();
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
