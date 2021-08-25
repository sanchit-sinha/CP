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
ll n , a[N] , c[N];
vll v[N];
bool vis[N];
void dfs(ll node , ll col){
    vis[node] = 1;
    c[node] = col;
    for(auto child : v[node]){
        if(!vis[child]) dfs(child , col^1);
    }
} 
bool check(){
    bool f = 0;
    if(a[0] != a[n - 1] && c[0] == c[n - 1]){
        f = 1;
        c[0] = 2;
    }
    for(ll i = 1 ; i < n ; i++){
        if(a[i] != a[i - 1] && c[i] == c[i - 1]){
            c[i] = 2;
            f = 1;
        }
    }
    return f;
}
bool eq(){
    ll ct =0 ;
    ll x =a[0];
    rep(i , n) if(a[i] == x) ct++;
    if(ct == n) return true;
    else return false;
} 
void solve(){
    cin >> n;    
    rep(i ,n) cin >> a[i];
    for(ll i= 0 ; i <n ; i++){
        if(i == 0){
            if(a[0] != a[n - 1]) v[0].pb(n - 1);
            if(a[1] != a[0]) v[0].pb(1);
        }
        else if(i == n - 1){
            if(a[n - 1] != a[0]) v[n - 1].pb(0);
            if(a[n - 2] != a[n - 1]) v[n - 1].pb(n - 2);
        }
        else{
            if(i - 1 >= 0 && a[i] != a[i - 1]) v[i].pb(i - 1);
            if(i + 1 < n && a[i] != a[i + 1]) v[i].pb(i + 1);
        }
    }
    if(eq()){
        cout <<1 << endl;
        rep(i , n ) cout << c[i] + 1 << " ";
        nl;
        return;
    }
    for(ll i = 0 ; i < n ; i++){
        if(!vis[i]) dfs(i , 0 );
    }
    if(check()){
        cout << 3 << endl;
        rep(i , n) cout << c[i] + 1 << " ";
        nl;
    }
    else{
        cout << 2 << endl;
        rep(i ,n ) cout << c[i] + 1 << " ";
        nl;
    }
    rep(i , n) v[i].clear() , a[i] = c[i] = 0;
    rep(i , n) vis[i] = 0;
    n = 0;
}
int main(){
    IOS;
    cout << fixed << setprecision(20);
    ll NTC=1;
    cin>>NTC;
    ll PTC=0;
    while(PTC++<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
