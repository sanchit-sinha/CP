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

bool findPartiion(vll &arr){
    ll n = (ll)arr.size();
    ll sum = 0;
    ll i, j;
 
    for (i = 0; i < n; i++)
        sum += arr[i];
 
    if (sum % 2 != 0)
        return false;
 
    bool part[sum / 2 + 1];
    for (i = 0; i <= sum / 2; i++) {
        part[i] = 0;
    }
 
    for (i = 0; i < n; i++) {
        for (j = sum / 2; j >= arr[i];
             j--) { 
            if (part[j - arr[i]] == 1 || j == arr[i])
                part[j] = 1;
        }
    }
 
    return part[sum / 2];
}
void solve(){
    ll n;
    cin >> n;

    vll a(n);
    rep(i , n) cin >> a[i];

    ll odd = -1;
    rep(i , n) if(a[i]%2 == 1) odd = i;

    bool ok = 1;
    ll sum = 0;
    rep(i , n) sum += a[i];

    if(sum%2 == 1) ok = 0;
    if(!findPartiion(a)) ok = 0;

    if(ok){
        ll mn = LLONG_MAX;
        ll index = -1;
        vll powct(n , 0);
        rep(i , n) {
            ll temp = a[i];
            while(temp%2 == 0) temp/=2 , powct[i]++;
            mn = min(mn , powct[i]);
        }
        rep(i , n) if(powct[i] == mn) index = i;

        cout << 1 << "\n";
        (odd == -1) ? (cout << index + 1 << "\n") : (cout << odd + 1 << "\n");
    }
    else{
        cout << 0 << "\n";
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