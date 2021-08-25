#include "bits/stdc++.h"
using namespace std;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define size(c) (int)(c.size())
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

const ll N = 1e5 + 11;
ll x0 , y0 , ax , ay , bx , by , xs , ys , t ;
vpll v;
void solve(){
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >>xs >> ys >> t ;
    v.pb(xs , ys);
    ll x = xs , y = ys;
    for(ll i = 1 ;i <= 58 ; i++){
        ll nwx = ax*x + bx , nwy = ay*y + by;
        ll dis = abs(nwx - x ) + abs(nwy - y);
        if(dis > t) break;
        v.pb(nwx , nwy);
        x = nwx , y = nw;
    }
    // dij(xs , ys);
    ll ans = 0 ;
    ll len = size(v);
    vector<bool> vis(len , 0);
    ll time = 0 , dis = inf;
    pll prev; 
    while(1){
        for(ll j = 0 ; j < len ; j++){
            if(!vis[j]){
                ll x = v[j].f , y = v[j].s;
                if(x != prev.f && y != prev.s){
                    ll val = abs(v[j].f - prev.f) + ans(v[j].s -prev.s);
                    dis = min(dis , val);
                    if(dis == val) pick.f = i , pick.s = j;
                }
            }
            time += dis;
            if(time <= t){
                vis[pick.f] = vis[pick.s] = 1;
                prev.f = v[pick.f].f , prev.s = v[pick.s].s;
                ans++;
            }
            else break;
        }
    }
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
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
