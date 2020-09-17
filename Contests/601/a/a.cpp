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

const ll N = 500;
ll n , m;
set<ll> train[N];
set<ll> bus[N];

ll dij1(ll node){
    set<pll> s;
    ll dis[n + 1] = {0};
    for(ll i = 2 ; i<= n; i++) dis[i] = inf , s.insert({inf , i});
    s.insert({0 , 1});
    while(!s.empty()){
        ll from = (s.begin())->s;
        ll len = 1;
        s.erase(s.begin());
        for(auto to : train[from]){
            if(dis[from] + len  < dis[to]){
                s.erase({dis[to] , to});
                dis[to] = dis[from] + len;
                s.insert({dis[to] , to});
            }
        }
    }
    return dis[n];
}
ll dij2(ll node){
    set<pll> s;
    ll dis[n + 1] = {0};
    for(ll i = 2 ; i<= n; i++) dis[i] = inf , s.insert({inf , i});
    s.insert({0 , 1});
    while(!s.empty()){
        ll from = (s.begin())->s;
        ll len = 1;
        s.erase(s.begin());
        for(auto to : bus[from]){
            if(dis[from] + len  < dis[to]){
                s.erase({dis[to] , to});
                dis[to] = dis[from] + len;
                s.insert({dis[to] , to});
            }
        }
    }
    return dis[n];
}
void solve(){
    cin >> n >> m;
    rep(i , m){
        ll a  ,b ;
        cin >> a >> b;
        train[a].insert(b);
        train[b].insert(a); 
    }
    for(ll i = 1 ; i <= n; i++){
        for(ll j = 1 ; j <=  n; j++){
            if(i != j){
                auto it = train[i].find(j);
                if(it == train[i].end()){
                    bus[i].insert(j);
                    bus[j].insert(i);
                }
            }
        }
    }
    ll t1 = dij1(1);
    ll t2  = dij2(1);
    // cout << t1 << " " << t2 << endl;
    if(t1 == inf || t2 == inf) cout << -1 << endl;
    else cout << max(t1 , t2) << endl;
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
