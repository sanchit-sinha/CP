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

#define SIEVE
// finding shortest prime factor in O(nlog(n))
const ll mX = N;
ll spf[mX];
void sieve (){
    spf[1] = 1;
    for(ll i = 2 ; i < mX ; i++){
         if(spf[i] == 0){
            spf[i] = i;
            for (ll j = 1ll * i * i; j < mX; j += i){
                if(spf[j] == 0) spf[j] = i;
            }
        }
    }
} 
void solve(){
    ll n , q;
    cin >> n >> q;

    vll a(n);
    rep(i , n) cin >> a[i];

    map<ll , vll> factorsPos;
    vvll pr(n);
    rep(i , n){
        ll x = a[i];
        while(x > 1){
            ll div = spf[x];
            while(x%div == 0) x /= div;
            factorsPos[div].pb(i);
            pr[i].pb(div);
        }
    }

    // go[i] => next nearest starting index of next segment from i
    vll go(n);
    FORR(i, n - 1, 0){
        if(i == n - 1) go[i] = n;
        else{
            ll len = sz(pr[i]);
            go[i] = go[i + 1];
            rep(j, len){
                ll factor = pr[i][j];
                auto it = ub(all(factorsPos[factor]), i);
                if(it != factorsPos[factor].end()) go[i] = min(go[i], *it);
            }
        }
    }

    vvll dp(n + 11 , vll(21 , 0));
    // dp[i][j] => replacing i with go[i] 2^j times
    rep(i , n) dp[i][0] = go[i];
    FOR(j, 1, 20) {
        rep(i, n){
            ll index = dp[i][j - 1];
            if(index < n) dp[i][j] = dp[index][j - 1];
            else dp[i][j] = n;
        }
    }

    while(q--){
        ll l , r;
        cin >> l >> r;

        l-- , r--;
        ll ans = 0ll;
        FORR(i, 20, 0){
            ll next = dp[l][i];
            if(next <= r) ans += (1ll << i), l = next;
        }
        if(l <= r) ans++;
        cout << ans << "\n";

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
