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
#define ppll                pair<pll , pll>
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
ll n;
multiset<ppll> s[6];
pll p[6][2];
bool isinside(ppll x , ppll y , ppll z){
    ll ct = 0;
    if(min(x.f.f , y.f.f) <= z.f.f && z.f.f <= max(x.f.f , y.f.f)) ct++;
    if(min(x.f.s , y.f.s) <= z.f.s && z.f.s <= max(x.f.s , y.f.s)) ct++;
    if(min(x.s.f , y.s.f) <= z.s.f && z.s.f <= max(x.s.f , y.s.f)) ct++;

    return (ct == 3);
}
pll index(ppll x , ppll y){
    pll p = mp(x.s.s , y.s.s);
    return p;
}
void add2(vpll &ans, multiset<ppll> &m){
    // sz > 6
    vector<ppll> v;
    trav(it , m){
        if(sz(v) == 6) break;
        pair<pll , pll> p = *it;
        v.push_back(p);
    }

    sort(all(v));

    bool taken = 0;
    rep(i , sz(v)){
        rep(j , sz(v)){
            if(i != j){
                bool choose = 1;
                rep(k , sz(v)){
                    if(k != i && k != j){
                        if(isinside(v[i] , v[j] , v[k])){
                            choose = 0;
                        }
                    }
                }

                if(choose){
                    ans.pb(index(v[i] , v[j]));
                    taken = 1;
                    auto it1 = m.find(v[i]);
                    if(it1 != m.end()) m.erase(it1);

                    auto it2 = m.find(v[j]);
                    if(it2 != m.end()) m.erase(it2);

                    return;
                }
            }
        }
    }

    if(!taken){
        m.clear();
        return;
    }    
}

void addall(vpll &ans , multiset<ppll> m){
    vector<ppll> v;
    trav(it , m){
        if(sz(v) == sz(m)) break;
        pair<pll , pll> p = *it;
        v.push_back(p);
    }

    sort(all(v));

    ll len = sz(v);
    vector<bool> vis(len , 0);
    rep(i , sz(v)){
        rep(j , sz(v)){
            if(!vis[i] && !vis[j] && i != j){
                bool choose = 1;
                rep(k , sz(v)){
                    if(!vis[k] && k != i && k != j){
                        if(isinside(v[i] , v[j] , v[k])){
                            choose = 0;
                        }
                    }
                }

                if(choose){
                    ans.pb(index(v[i] , v[j]));
                    vis[i] = vis[j] = 1;

                    auto it1 = m.find(v[i]);
                    if(it1 != m.end()) m.erase(it1);

                    auto it2 = m.find(v[j]);
                    if(it2 != m.end()) m.erase(it2);

                    break;
                }
            }
        }
    }

    if(sz(m)){
        m.clear();
        return;
    }
}
void solve(){
    cin >> n;
    rep(i , n){
        ll x , y , z;
        cin >> x >> y >> z;

        p[0][0] = mp(x , y);
        p[0][1] = mp(z , i);

        p[1][0] = mp(x , z);
        p[1][1] = mp(y , i);

        p[2][0] = mp(y , x);
        p[2][1] = mp(z , i);

        p[3][0] = mp(y , z);
        p[3][1] = mp(x , i);

        p[4][0] = mp(z , x);
        p[4][1] = mp(y , i);

        p[5][0] = mp(z , y);
        p[5][1] = mp(x , i);

        rep(j , 6) s[j].insert(mp(p[j][0] , p[j][1]));
    }

    rep(j , 6){
        vpll ans;
        multiset<pair<pll , pll > > m = s[j];

        while(sz(m) > 6) add2(ans , m);
        if(sz(m) <= 6) addall(ans , m); 

        if(sz(ans) == n/2){
            cout << sz(ans) << "\n";
            // rep(i , sz(ans)) cout << ans[i].f + 1 << " " << ans[i].s + 1 << "\n";
            return;
        }
    }

    assert(1);
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
