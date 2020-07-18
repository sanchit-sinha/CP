#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define nl cout << "\n"
#define endl "\n"
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define mp make_pair
#define mt make_tuple
#define get(x,c) get<x>(c)
#define trav(a,x) for(auto a=x.begin() ; a!=x.end() ; a++)
#define rep(i,n) for(int i=0 ; i<n ; i++)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define f first
#define s second

inline ll max(ll a,ll b) {return ((a>b)?a:b);}
inline ll min(ll a,ll b) {return ((a>b)?b:a);}
inline ll gcd(ll a ,ll b) {if(b==0) return a; a%=b;return gcd(b,a);}
ll power(ll x,ll y){if(y == 0) return 1; ll a = power(x,y/2);if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x,ll ex ,ll md) {ll ans = 1ll;while(ex > 0){if(ex & 1ll) ans = (ans*x)%md; ex >>= 1ll;x=(x*x)%md;}return ans;}

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 2e5 + 11;
ll n;
ll tree[4*N] , a[N];
map<ll ,set<ll>> m;
void build(ll node ,ll l , ll r){
    if(l == r) tree[node] = a[l];
    else{
        ll mid = l + (r - l)/2;
        build(2*node , l , mid);
        build(2*node + 1 , mid + 1 , r);
        tree[node] = min(tree[node*2] , tree[node*2 + 1]);// operation
    }
}
void update(ll node , ll l , ll r , ll index, ll val){
    if(index > r || index < l) return ;
    if(l == r) a[index] = val , tree[node] = val; //update operation
    else{
        ll mid = l + (r - l)/2;
        update(node*2 , l , mid , index , val);
        update(node*2 + 1 , mid + 1 , r , index , val);
        tree[node] = min(tree[node*2] , tree[node*2 + 1]); // operation
    }
}
ll query(ll node , ll l , ll r , ll start , ll end){
    if(end < l || start > r) return inf; // operation (inf , -inf , 0 ...)
    else if(start <= l && end >= r) return tree[node];
    else{
        ll mid = l + (r - l)/2;
        ll p1 = query(2*node , l , mid , start , end);
        ll p2 = query(2*node + 1 , mid + 1 , r , start , end);
        return min(p1,p2); // operation
    }
}
void solve(){
    cin >> n;
    rep(i,n){
        cin >> a[i];
        m[a[i]].insert(i);
    }
    set<ll> index;
    rep(i,n) index.insert(i);
    build(1,0,n-1);
    while(1){
        ll x = -1, y = -1;
        ll val = query(1,0,n-1,0,n-1);
        ll id = *m[val].begin();
        auto it = index.ub(id);
        if(it == index.end()){
            x = *index.begin();
        }
        
        auto it1= index.lb(id);
        if(it1 != index.begin()){
            it1--;
            y = *it1;
        }
        else y = *index.rbegin();

        // cout << id <<" : " << val << endl;
        // cout << x <<" : " << a[x] << endl;
        // cout << y << " : " << a[y] << endl;

        if(x == id || y == id) break;
        else if(x == -1 || y ==-1) break;
        else{
            update(1,0,n-1,id,a[x]+a[y]);
            m[a[x]+a[y]].insert(id);
            update(1,0,n-1,x,inf);
            update(1,0,n-1,y,inf);
            m[val].erase(m[val].find(id));
            if(sz(m[val]) == 0) m.erase(m.find(val));
            index.erase(index.find(x));
            index.erase(index.find(y));
        }
    }
    ll ans = 0;
    rep(i,n) if(a[i] != inf) ans= a[i];
    cout << ans << endl;
}
int main(){
    IOS;
    cout << fixed << setprecision(20);
    ll NTC = 1;
    // cin >> NTC;
    ll PTC = 0;
    while(PTC++ < NTC){
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        // cout << "\n";
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
