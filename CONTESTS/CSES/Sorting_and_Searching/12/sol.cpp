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

ll op(ll &ans, ll x , ll y , vll &a , map<ll,ll> &index){
    ll ele = a[x - 1];
    ll oldindex = x - 1;
    ll newindex = y - 1;

    ll small = a[x - 1] - 1;
    ll index_smaller = index[small];

    ll big = a[x - 1] + 1;
    ll index_bigger = index[big];

    ll n = sz(a);
    // rep(i , n) cout << a[i] << " ";
    // cout << "\n";
    // cout << oldindex << " : " << newindex << " : " << index_smaller << " : " << index_bigger << "\n"; 
    // cout << "before : " << ans << "\n";

    ll add = 0;
    if(newindex == index_smaller){
        if(oldindex > index_smaller){
            ans++;
            add += 1;
        }
        else{
            ans--;
            add -= 1;
        }

        // cout << "in " << add << "\n";
    }
    else if(oldindex > index_smaller && newindex < index_smaller) ans++;
    else if(oldindex < index_smaller && newindex > index_smaller) ans--; 

    // cout << "after1 : " << ans << "\n";

    if(newindex == index_bigger){
        if(oldindex > index_bigger){
            ans--;
            add -= 1;
        }
        else{
            ans++;
            add += 1;
        }
        // cout << "in " << add << "\n";
    }
    else if(oldindex > index_bigger && newindex < index_bigger) ans--;
    else if(oldindex < index_bigger && newindex > index_bigger) ans++;

    return add;
}
void solve(){
    ll n , m;
    cin >> n >> m;

    vll a(n);
    rep(i , n) cin >> a[i];

    map<ll , ll> index;
    rep(i , n) index[a[i]] = i;

    vll dp(n + 1 , 0);
    ll prev = index[1];
    dp[1] = 1;

    FOR(i , 2 , n){
        ll presindex = index[i];
        ll previndex = index[i - 1];
        if(presindex > previndex) dp[i] = dp[i - 1];
        else dp[i] = dp[i - 1] + 1;
    }

    index[n + 1] = inf;
    index[0] = 0; 

    ll ans = dp[n];
    while(m--){
        ll x , y;
        cin >> x >> y;

        ll add = 0;
        add += op(ans , x , y , a , index);
        add += op(ans , y , x , a , index);
        
        ans -= add/2;
        
        // cout << "in " << add << "\n";
        cout << ans << "\n";

        swap(index[a[x - 1]] , index[a[y - 1]]);
        swap(a[x - 1] , a[y - 1]);
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
