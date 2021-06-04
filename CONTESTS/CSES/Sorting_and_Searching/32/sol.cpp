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

void transform(multiset<ll> &mn , multiset<ll> &mx , ll k){
    ll mnlen = (k + 1)/2;
    ll mxlen = k/2;

    if(sz(mn) < mnlen){
        // from mx to mn 
        while(sz(mx) != mxlen){
            ll ele = *mx.begin();
            mn.insert(ele);
            auto it = mx.find(ele);
            mx.erase(it);
        }
    }
    else if(sz(mn) > mnlen){
        // from mn to mx 
        while(sz(mn) != mnlen){
            ll ele = *mn.rbegin();
            mx.insert(ele);
            auto it = mn.find(ele);
            mn.erase(it);
        }
    }

    while(sz(mn) && sz(mx)){
        ll elemn = *mn.rbegin();
        ll elemx = *mx.begin();
        
        if(elemn > elemx){
            mx.insert(elemn);
            mn.insert(elemx);

            auto it1 = mn.find(elemn);
            if(it1 != mn.end()) mn.erase(it1);
        
            auto it2 = mx.find(elemx);
            if(it2 != mx.end()) mx.erase(it2);
        }
        else break;
    }
}
void solve(){
    ll n , k;
    cin >> n >> k;

    vll a(n);
    rep(i , n) cin >> a[i];

    multiset<ll> mx , mn;
    rep(i , k) mn.insert(a[i]);

    transform(mn , mx , k);
    cout << *mn.rbegin() << " ";

    FOR(i , k , n - 1){
        ll prev = a[i - k];
        auto it1 = mn.find(prev);
        if(it1 != mn.end()) mn.erase(it1);
        else{
            auto it2 = mx.find(prev);
            if(it2 != mx.end()) mx.erase(it2);
        }

        mn.insert(a[i]);
        transform(mn, mx, k);
        cout << *mn.rbegin() << " "; 
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
