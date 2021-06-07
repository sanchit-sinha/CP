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

string to_string(string s) {return '"' + s + '"';}string to_string(const char* s) {return to_string((string) s);}string to_string(bool b) {return (b ? "true" : "false");}template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A>string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}void debug_out() { cerr << "\n"; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n";debug_out(T...);} 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

inline ll gcd(ll a,ll b) {if(b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a,ll b) {return((a > b) ? a : b);}
inline ll min(ll a,ll b) {return((a > b) ? b : a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;
const ll N = 1.5e5;

ll tree[4*N],a[N];
ll pull(ll l,ll r , ll op){
    if(op&1) return (l ^ r);
    else return (l | r);
}
void build(ll node,ll l,ll r ,ll c){ // c is what to do with nodes on that layer 
    if(l==r) tree[node]=a[l];
    else{
        ll mid=l+(r-l)/2;
        build(2*node,l,mid , c^1);
        build(2*node+1,mid+1, r , c^1);
        
        tree[node] = pull(tree[node*2],tree[node*2+1] , c);
    }
}
void update(ll node,ll l,ll r,ll index,ll val , ll c){
    if(index>r || index<l) return ;
    if(l==r) a[index]=val , tree[node]=val; //update operation
    else{
        ll mid=l+(r-l)/2;
        update(node*2,l,mid,index,val , c^1);
        update(node*2+1,mid+1,r,index,val , c^1);
        
        tree[node] = pull(tree[node*2],tree[node*2+1] , c);
    }
}
ll query(ll node,ll l,ll r,ll start,ll end , ll c){
    if(end<l || start>r) return 0; //operation (inf , -inf , 0 ...)
    else if(start<=l && end>=r) return tree[node];
    else{
        ll mid=l+(r-l)/2;
        ll p1 = query(2*node,l,mid,start,end , c^1);
        ll p2 = query(2*node+1,mid+1,r,start,end , c^1);
        
        return pull(p1,p2 , c); //operation
    }
}
//build(1,0,n-1) .... query(1,0,n-1,l,r) .... update(1,0,n-1,x,a[x])
void solve(){
    ll k , m;
    cin >> k >> m;

    ll n = (1ll << k);
    rep(i , n) cin >> a[i];

    build(1 , 0 , n - 1 , (k + 1)&1);

    rep(i , m){
        ll x , y;
        cin >> x >> y;
        x--; a[x] = y;

        update(1 , 0 , n - 1 , x , a[x] , (k + 1)&1);
        ll ans = query(1, 0, n - 1, 0, n - 1, (k + 1)&1);

        cout << ans << "\n";
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

