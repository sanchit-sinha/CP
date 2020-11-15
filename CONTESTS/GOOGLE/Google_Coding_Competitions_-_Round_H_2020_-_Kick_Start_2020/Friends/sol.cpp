/**
 *    Author:  Sanchit Sinha
 *    Created: 15.11.2020 10:33:06       
**/
#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define mp make_pair
#define mt make_tuple
#define get(x,c) get<x>(c)
#define trav(a,x) for(auto a=x.begin();a!=x.end();a++)
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,b,a) for(int i=b;i>=a;i--)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define f first
#define s second

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll power(ll x,ll y);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 5e4 + 11;
class lca{
    public:
    ll MAX_D;
    ll dfs_timer;
    vector<vector<ll>> g;
    vector<vector<ll>> ancestor;
    vector<bool> visited;
    vector<ll> depth;
    vector<ll> en;
    vector<ll> ex;
    vector<ll> par;
    lca(ll n){
        g.resize(n + 1);
        visited.resize(n + 1 , 0);
        depth.resize(n + 1 , 0);
        en.resize(n + 1, 0);
        ex.resize(n + 1, 0);
        par.resize(n + 1, -1);
        dfs_timer = 0;
        MAX_D = ceil(log2(n));
        ancestor = vector<vector<ll>>(MAX_D + 1, vector<ll>(n + 1 , -1));
    }
    void addEdge(ll l, ll r){
        g[l].push_back(r);
    }
    void do_dfs(ll sr){
        visited[sr] = true;
        dfs_timer++;
        en[sr] = dfs_timer;
        for(auto child : g[sr]){
            if(!visited[child]){
                ancestor[0][child] = sr;
                depth[child] = depth[sr] + 1;
                par[child] = sr; 
                do_dfs(child);
            }
        }
        dfs_timer++;
        ex[sr] = dfs_timer;
    }
    void build_lca_table(){
        ll n = (ll) g.size() - 1;
        this->do_dfs(1);
        for(ll d = 1; d <= MAX_D; d++){
            for(ll i = 1; i <= n; i++){
                if(ancestor[d - 1][i] != -1){
                    ancestor[d][i] = ancestor[d - 1][ancestor[d - 1][i]];
                }
            }
        }
    }
    ll climb(ll l , ll d){
        ll i = l;
        for(ll dd = 0; (dd <= MAX_D && i != -1) ;dd++){
            if((1ll << dd) & d) i = ancestor[dd][i];
        }
        return i;
    }
    ll get_lca(ll i , ll j){
        if(depth[i] > depth[j]) i = climb(i , depth[i] - depth[j]);
        if(depth[j] > depth[i]) j = climb(j , depth[j] - depth[i]);
        assert(depth[j] == depth[i]);
        if(i == j) return i;
        for(ll d = MAX_D; d >= 0; --d){
            if(ancestor[d][i] != ancestor[d][j]){
                i = ancestor[d][i];
                j = ancestor[d][j];
            }
        }
        return ancestor[0][i];
    }
    ll isAncestor(ll u , ll v){
        return (en[u] <= en[v] && ex[v] <= ex[u]);
    }
};
bool found(string s,string t){
    ll n=sz(s);
    ll m=sz(t);
    rep(i,n){
        rep(j,m){
            if(t[j] == s[i]) return true;
        }
    }
    return false;
}
void solve(){
    ll n,q;
    cin>>n>>q;
    string s[n];
    lca LCA (n+100);
    rep(i,n) cin>>s[i];
    FOR(i,0,n-1){
        FOR(j,i+1,n-1){
            if(found(s[i],s[j])){
                LCA.addEdge (i+1 , j+1);
                LCA.addEdge (j+1 , i+1);
            }            
        }
    }
    LCA.build_lca_table();

    while(q--){
        ll x,y;
        cin>>x>>y;
        ll comman = LCA.get_lca (x,y);
        if(comman == -1) cout<<-1<<" ";
        else cout<<abs(LCA.depth[x] - LCA.depth[comman]) + abs(LCA.depth[y] - LCA.depth[comman])+ 1<<" ";
    }
    cout<<"\n";
}
int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    ll NTC=1;
    cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
