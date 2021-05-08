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
    ll u[n];
    rep(i , n) cin >> u[i];
    ll s[n];
    map<ll , vll> m;

    ll tot = 0;
    rep(i , n){
        cin >> s[i];
        m[u[i]].pb(s[i]);
        tot += s[i];
    }

    trav(it , m) sort(all(it->s) , greater<ll>());

    map<ll , vll > sfx;

    trav(it , m){
        ll university = it->f;
        ll len = sz(it->s);
        
        FORR(j , len - 1 , 0){
            sfx[university].pb(0);
        }
        FORR(j , len - 1 , 0){
            if(j == len - 1) sfx[university][j] = m[university][j];
            else{
                sfx[university][j] = sfx[university][j + 1] + m[university][j];
            }
        }
    }

    // cout << "TOT\n";
    // cout << tot << "\n\n";
    // trav(it , m){
    //     cout << it -> f << " : ";
    //     rep(j , sz(it->s)) cout << (it->s)[j] << " ";
    //     cout << "\n";
    // }

    FOR(i , 1 , n){
        ll k = i;
        ll remove = 0;

        vll erase;
        trav(it , m){
            ll len = sz(it->s);
            ll rem = len % k;

            if(len < k) erase.pb(it->f);
            else{ 

                // r - l + 1  = rem => l = r + 1 - rem;
                ll r = len - 1;
                ll l = r + 1 - rem;

                if(l < len) {
                    ll val = sfx[it->f][l];
                    remove += val;
                }
            }
        }

        ll len = sz(erase);
        rep(j , len){
            ll val = erase[j];
            ll len1 = sz(m[val]);

            auto it = m.find(val);
            if(it != m.end()){
                m.erase(it);
            }

            tot -= sfx[val][0];
        }
        cout << tot - remove << " ";
    }

    cout << "\n";
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
