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

const ll inf = 1e18 + 1;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 3e5 + 3;
ll n , m , ct[N][26] , dep[N] , t;
vll v[N] , topo;
bool vis[N];
char s[N];
void dfs(ll node){
    vis[node] = 1;
    for(auto child : v[node]){
        if(!vis[child]) dfs(child);
    }
    dep[node] = t++;
    topo.pb(node);
}
bool isdag(){
    ll n = topo.size();
    for(ll j = 0 ; j < n ; j++){
        ll i = topo[j];
        ll t1 = dep[i];
        for(auto child:v[i]){
            ll t2 = dep[child];
            if(t2 > t1) return false;
        }
    }
    return true;
}
ll dp(){
    ll n = topo.size();
    for(ll i = 0 ; i < n ; i++){
        ll node = topo[i];
        for(auto child : v[node]){
            for(ll j = 0 ; j < 26 ; j++) ct[child][j] = max(ct[child][j] , ct[node][j] + ((s[child] - 'a') == j));
        }
    }
    ll mx = -inf;
    for(ll i = 0 ; i < n ;i++){
        ll node = topo[i];
        for(ll j = 0 ; j  <26 ; j++) mx = max(mx , ct[node][j]);
    }
    return mx;
}
void solve(){
    cin >> n >> m;
    rep(i , n) cin >> s[i + 1] , ct[i + 1][s[i + 1] - 'a'] = 1;
    rep(i , m){
        ll x , y;
        cin >> x >> y;
        if(x == y){
            cout << -1 << endl;
            return ;
        }
        v[x].pb(y);
    }
    for(ll i = 1 ; i <= n ; i++){
        if(!vis[i]) dfs(i);
    }
    reverse(all(topo));
    if(!isdag()) cout << -1 << endl;
    else cout << dp() << endl;
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
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
