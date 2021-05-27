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

// interesting implementation
const ll N = 3e5+11;
ll n , a[N] , b[N];
vll v[N] , g[N]; // graphs
ll timer, in[N] , out[N]; // in|out  time of nodes for second tree
set<pll> s; // set containing maximum non intersecting in-out intervals on a single path of tree (from root to node) 
            // => This will basically contain the answer if node is a leaf
ll ans; // final ans 
bool vis[N];

//add or not add new interval maintaining the non intersecting condition
void add(set<pll> &s , ll l , ll r , bool &already_non_intersecting , bool &contained , pll &container){
    auto it = s.lb({l , r});
    pll pl = *it;
   
    it--;
    pll pr = *it;

    if(pl.s < l && pr.f > r) already_non_intersecting = 1;
    else{
        if(pl.s > r && pl.f < l) contained = 1 , container = pl;
        if(pr.s > r && pr.f < l) contained = 1 , container = pr;
    }

    s.insert({l , r});
    if(contained){
        auto itf = s.find(container);
        if(itf != s.end()) s.erase(itf);
    }
}
void in_out(ll node){
    vis[node] = 1;
    in[node] = timer++;
    for(auto child : g[node]){
        if(!vis[child]){
            in_out(child);
        }
    }
    out[node] = timer++;
}

void dfs(ll node , set<pll> &s){
    vis[node] = 1;
    bool isleaf = 1;

    for(auto child : v[node]){
        if(!vis[child]){
            // s contains non overlapping intervals from all the prefix till node
            // ([ ] .. . [ ] . .[ ] )
            ll l = in[child] , r = out[child];
            bool already_non_intersecting = 0;
            bool contained = 0;
            pll container = {-1 , -1};

            add(s , l , r , already_non_intersecting , contained , container);

            dfs(child , s);
            isleaf = 0;
            
            // on returning to node, we need to mantain the set
            auto itf = s.find(mp(l , r));
            if(itf != s.end()) s.erase(itf);

            if(contained) s.insert(container);
        }
    }

    if(isleaf){
        ans = max(ans , sz(s) - 2ll);
        // cout << node << " : ";
        // trav(it , s) cout << "( " << it->f << " " << it->s << ") ";
        // cout << "\n";
    }
}
void solve(){
    // clear
    rep(i , n + 1){
        a[i] = b[i] = in[i] = out[i] = 0;
        v[i].clear();
        g[i].clear();
        vis[i] = 0;
    }
    timer = 0;
    s.clear();
    ans = 0; n = 0;

    cin >> n;
    
    // form tree
    FOR(i , 2 , n){
        cin >> a[i];
        v[a[i]].pb(i);
        v[i].pb(a[i]);
    }

    FOR(i , 2 , n){
        cin >> b[i];
        g[b[i]].pb(i);
        g[i].pb(b[i]);
    }

    // in- out time calculation
    in_out(1);
    rep(i , n + 1) vis[i] = 0;

    // FOR(i , 1 , n) cout << i << " : " << in[i] << " " << out[i] << "\n";

    pll pl = {-1 , -1};
    pll pr = {inf , inf};
    s.insert(mp(in[1] , out[1]));
    s.insert(pl);
    s.insert(pr);

    //calculate the ans 
    dfs(1 , s);

    cout << ans << "\n";     
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
