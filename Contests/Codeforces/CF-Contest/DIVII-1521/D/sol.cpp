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
ll n;
multiset<ll> v[N];
vll leaf;
map<ll , set<ll>> removed;
vpll deleted;
bool vis[N];

void dfs(ll node , ll pr){
    // top - down part => parent to child 

    for(auto child : v[node]){
        if(child != pr){
            dfs(child , node);
        }
    }

    // bottom up part : work of all child is done => now we move to the parent
    ll cv = sz(v[node]) - sz(removed[node]);
    if(cv >= 3){
        // remove pr to node
        if(pr != -1){
            cv--;

            removed[pr].insert(node);
            removed[node].insert(pr);
            deleted.pb(mp(pr , node));
        }

        for(auto child : v[node]){
            if(cv == 2) break;
            else{
                auto it = removed[node].find(child);
                if(it == removed[node].end()){
                    cv--;

                    removed[child].insert(node);
                    removed[node].insert(child);
                    deleted.pb(mp(child , node));
                }
            }
        }
    }
}
void dfs2(ll node){
    vis[node] = 1;

    bool got = 0;
    for(auto child : v[node]){
        if(!vis[child]){
            got = 1;
            dfs2(child);
        }
    }

    if(!got) leaf.pb(node);
}
void solve(){
    // clear
    rep(i , n + 1){
        v[i].clear();
        vis[i] = 0;
    } 
    leaf.clear();
    removed.clear();
    deleted.clear();

    cin >> n;
    rep(i , n - 1){
        ll x , y;
        cin >> x >> y;

        v[x].insert(y);
        v[y].insert(x);
    }

    dfs(1 , -1);

    rep(i , sz(deleted)){
        ll node = deleted[i].f;
        ll child = deleted[i].s;

        auto itc = v[child].find(node);
        if(itc != v[child].end()) v[child].erase(itc);

        auto itn = v[node].find(child);
        if(itn != v[node].end()) v[node].erase(itn);
    }
 
    vpll add;
    rep(i , n){
        ll node = i + 1;
        if(!vis[node]){
            leaf.clear();

            dfs2(node);

            if(sz(v[node]) == 1) leaf.pb(node); 

            ll n1 = leaf[0];
            ll n2 = leaf[0];

            if(sz(leaf) > 1) n2 = leaf[1]; 
            add.pb(mp(n1 , n2));
        }
    }

    vpll added;
    rep(i , sz(add) - 1){
        ll u1 = add[i].f;
        ll d1 = add[i].s;

        ll u2 = add[i + 1].f;
        ll d2 = add[i + 1].s;

        added.pb({u1 , u2});
        add[i + 1].f = d1;
        add[i + 1].s = d2;
    }

    ll lenr = sz(deleted);
    ll lena = sz(added);
    assert(lena == lenr);

    // rep(i , lena) cout << add[i] << " ";
    // cout << "\n";

    cout << lenr << "\n";
    rep(i , lenr){
        cout << deleted[i].f << " " << deleted[i].s << " " << added[i].f << " " << added[i].s << "\n";
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
