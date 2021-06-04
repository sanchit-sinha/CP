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
void debugv(vll &ans){
    cout << "\n********************\n";
    rep(i , sz(ans)) cout << ans[i] << " ";
    cout << "\n********************\n";
}
void debugvv(vpll &ans){
    cout << "\n********************\n";
    rep(i , sz(ans)) cout << ans[i].f << " " << ans[i].s << "\n";
    cout << "\n********************\n";
}
void debugm(map<ll , vll> &ans){
    cout << "\n************MAP********\n";
    trav(it , ans){
        cout << it->f << " : ";
        rep(i , sz(it->s)) cout << (it->s)[i] << " ";
        cout << "\n" ;
    }    
    cout << "\n********************\n";
}
void add(vpll &ans , vector<bool> &removed , ll x , ll y){
    assert(!removed[x]);
    assert(!removed[y]);

    removed[x] = removed[y] = 1;
    ans.pb(mp(x + 1, y + 1));
}
void refresh(map<ll , vll> &m , vector<bool> &removed , vll &x){
    m.clear();
    ll n = sz(x);
    rep(i , n){
        if(!removed[i]) m[x[i]].pb(i);
    }
}
void solve(){
    ll n; cin >> n;

    vll x(n) , y(n) , z(n);
    rep(i , n) cin >> x[i] >> y[i] >> z[i];

    vpll ans;
    map<ll , vll> m;
    vector<bool> removed(n , 0);
   
    refresh(m , removed , x);

    trav(it , m){
        map<ll , vll> yy;

        vll indexx = it->s;
        ll len = sz(indexx);
        rep(i , len) yy[y[indexx[i]]].pb(indexx[i]); // grouping all y together 
        
        // cout << it->f << " ::\n";
        // cout << "INDEXX\n";
        // debugv(indexx);

        // debugm(yy);
        // cout << "\n\n";

        trav(it2 , yy){
            vll indexz = it2->s;
            ll len2 = sz(indexz);

            for(ll j = 0 ; j < len2 - (len2&1); j += 2) add(ans , removed , indexz[j] , indexz[j + 1]);
        }

        // if(it->f == 2) return;
    }

    // debugvv(ans);
    // return;

    refresh(m , removed , x);

    // m[x] contains diff ys ;
    trav(it , m){
        vll indexy = it->s;
        ll len = sz(indexy);

        for(ll i = 0 ; i < len - (len&1); i += 2) add(ans , removed , indexy[i] , indexy[i + 1]);
    }

    x.clear();
    rep(i , n) if(!removed[i]) x.pb(i);

    assert(sz(x)%2 == 0);
    for(ll i = 0 ; i < sz(x) ; i += 2) add(ans , removed , x[i] , x[i + 1]);

    rep(i , sz(ans)) cout << ans[i].f << " " << ans[i].s << "\n";
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
