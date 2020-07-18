#include "bits/stdc++.h"
using namespace std;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define trav(a,x) for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define f first
#define s second

inline ll max(ll a,ll b) {return ((a>b)?a:b);}
inline ll min(ll a,ll b) {return ((a>b)?b:a);}
inline ll gcd(ll a ,ll b) {if(b==0) return a; a%=b;return gcd(b,a);}
ll power(ll x, ll y){if(y == 0) return 1; ll a = power(x,y/2);if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex , ll md) {ll ans = 1ll;while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll;x = (x * x) % md;}return ans;}

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e6 + 1;
ll n , m ;
ll tree[4*N] , a[N];
bool type[4*N];
void build(ll node ,ll l , ll r ){
    if(l == r) tree[node] = a[l];
    else{
        ll mid = l + (r - l)/2;
        build(2*node , l , mid );
        build(2*node + 1 , mid + 1 , r);
        if(!type[node*2]) tree[node] = (tree[node*2]|tree[node*2 + 1]) , type[node] = !type[node*2] ;// operation
        else tree[node] = (tree[node*2]^tree[node*2 + 1]) , type[node] = !type[node*2] ;
    }
}
void update(ll node , ll l , ll r , ll index, ll val){
    if(index > r || index < l) return ;
    if(l == r) a[index] = val , tree[node] = val; //update operation
    else{
        ll mid = l + (r - l)/2;
        update(node*2 , l , mid , index , val);
        update(node*2 + 1 , mid + 1 , r , index , val);
        if(!type[node*2]) tree[node] = (tree[node*2]|tree[node*2 + 1]) ;// operation
        else tree[node] = (tree[node*2]^tree[node*2 + 1])  ;
    }
}

void solve(){
    cin >> n >> m;
    n = power(2 , n);
    rep(i , n ) cin >> a[i];
    // for(ll i = 1; i <= 4*n ; i++) cout << i <<" : " << tree[i] << " : " <<  type[i] <<" \n";
    // nl;
    build(1 , 0 , n - 1);
    while(m--){
        ll x , y;
        cin >> x >> y;
        x--;
        update(1 , 0 , n - 1 , x , y);
        cout << tree[1] << endl;
    }
}
int main(){
    IOS;
    cout << fixed << setprecision(20);
    ll NTC=1;
    // cin>>NTC;
    ll PTC=0;
    while(PTC++<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
