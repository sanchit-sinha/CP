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

const ll N = 1e5+11;
const ll pr1 = 31;
const ll pr2 = 97;
const ll mod_for_hash = 1e9 + 7;
string pattern , text;
k

set<ll> generate(string pattern , string text , ll pr){
    ll n = sz(text);
    ll m = sz(pattern);

    set<ll> ans;
    vll hash_power(n + 1 , 1);
    FOR(i , 1 , n) hash_power[i] = (hash_power[i - 1] * pr)%mod_for_hash;

    ll hash_patten = 0;
    rep(i , m) hash_patten += ((pattern[i] - 'a' + 1) * hash_power[i])%mod_for_hash;

    vll hash_pfx;
    ll hash_text = 0;
    rep(i , n){
        hash_text += ((text[i] - 'a' + 1) * hash_power[i])%mod_for_hash;
        hash_pfx.pb(hash_text);
    }

    for(ll i = 0 ; i + m - 1 <= n - 1 ; i++){
        ll cur_hash_text = 0;
        ll cur_hash_pattern = 0;

        cur_hash_pattern = hash_patten * hash_power[i];
        cur_hash_pattern %= mod_for_hash;
        
        if(i == 0){
            cur_hash_text = hash_pfx[i + m - 1];
        }
        else{
            cur_hash_text = (hash_pfx[i + m - 1] - hash_pfx[i - 1] + mod_for_hash)%mod_for_hash;
        }

        if(cur_hash_text == cur_hash_pattern) ans.insert(i); 
    }
    return ans;
}
void solve(){
    pattern.clear() , text.clear();

    cin >> text >> pattern;

    set<ll> ans1 = generate(pattern , text , pr1);
    set<ll> ans2 = generate(pattern , text , pr2);

    set<ll> ans;
    trav(it , ans1){
        auto itf = ans2.find(*it);
        if(itf != ans2.end()) ans.insert(*it);
    }

    if(sz(ans)){
        cout << sz(ans) << "\n";
        trav(it , ans) cout << *it + 1 << " ";
        cout << "\n";
    }
    else cout << "Not Found\n";
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
