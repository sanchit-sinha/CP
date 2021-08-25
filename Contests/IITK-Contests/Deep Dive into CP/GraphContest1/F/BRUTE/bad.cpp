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

const ll N = 1e3+11;
ll n;   
set<ll> v[N];
map<ll , ll> m;  
void solve(){
    cin >> n;

    ll ct = 0;
    ll gr = 0;
    set<ll> remaining ;
    FOR(i , 1 , n - 1) remaining.insert(i);
   
    rep(i , n - 1){
        ll x  ,y;
        cin >> x >> y;   

        if(x < y) swap(x , y);
        if(x == n) ct++;
        
        m[y]++;
        auto it = remaining.find(y);
        if(it != remaining.end()) remaining.erase(it);
    }

    if(ct != n - 1){
        cout << "NO\n";
        return;
    }

    map<ll , set<ll>> dis;
    trav(it , m){
        dis[it->s].insert(it->f);
    }

    trav(it , dis){
        ll distance = it->f;
        ll len = sz(it->s);

        trav(it2 , it->s){
            ll node = *it2;
            if(node == n){
                cout << "NO\n";
                return;
            }

            ll ct = 0;
            ll parent = n;
            ll present_distance = distance;
            while(present_distance > 1){
                if(sz(remaining) == 0){
                    cout << "NO\n";
                    return;
                }

                auto itf = remaining.begin();
                if(itf != remaining.end()){
                    ll cur_node = *itf;
                    if(cur_node > node){
                        cout << "NO\n";
                        return;
                    }
                    v[parent].insert(cur_node);
                    parent = cur_node;

                    remaining.erase(itf);
                }
                else {
                    cout << "NO\n";
                    return;
                }
                present_distance--;
            }

            v[parent].insert(node);
        }   
    }

    ll cnt = 0;
    FOR(i , 1, n){
        cnt += (sz(v[i]));
    }

    if(cnt != n - 1) cout << "NO\n";
    else{
        cout << "YES\n";
        FOR(i , 1 , n){
            if(sz(v[i])){
                for(auto child : v[i]){
                    // cout << i << " " << child << "\n";
                }
            }
        }
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
