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

void print(vvll ans , ll n){
    FOR(i , 1 , n){
        FOR(j , 1 , i) cout << ans[i][j] << " ";
        cout << "\n";
    }
    cout << "\n\n";
}
void solve(){
    ll n;
    cin >> n;

    ll p[n + 1];
    rep(i , n) cin >> p[i + 1];

    vvll ans(n + 11 , vll(n + 11, 0));
    vll cnt(n + 1);
    rep(i , n) cnt[i + 1] = i;
    rep(i , n) ans[i + 1][i + 1] = p[i + 1];

    ll last = n;
    while(last >= 1){
        ll row = n;
        ll col = last;
        while(col >= 1){
            ll val = ans[row][col];
            if(cnt[val]){
                if(row + 1 <= n && ans[row + 1][col] == 0) {
                    ans[row + 1][col] = val;
                }
                else if(col - 1 >= 1) ans[row][col - 1] = val;
                cnt[val]--;
            }
            row--;
            col--;
        }
        last--;

        bool wait = 0;
        rep(i , n) if(cnt[i + 1]) wait = 1;
        if(!wait) break;
    }

    FOR(i , 1 , n){
        FOR(j , 1 , i) cout << ans[i][j] << " ";
        cout << "\n";
    }

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
