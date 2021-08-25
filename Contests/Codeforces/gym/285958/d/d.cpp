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

const ll N = 1e5 + 1;
ll x1, x2 , x3 , x4 , y11,y2,y3,y4,tx1,tx2,tx3,tx4,ty1,ty2,ty3,ty4;

bool line12(ll x1 , ll y1 , ll x2 , ll y2){
    ll ans1 = (y1 - ty1)*(tx1 - tx2) - (x1 - tx1)*(ty1 - ty2);
    ll ans2 = (y2 - ty1)*(tx1 - tx2) - (x2 - tx1)*(ty1 - ty2);
    if(ans1*ans2 >= 0) return 1;
    else return 0;
}
bool line23(ll x1 , ll y1 , ll x2 , ll y2){
    ll ans1 = (y1 - ty2)*(tx2 - tx3) - (x1 - tx2)*(ty2 - ty3);
    ll ans2 = (y2 - ty2)*(tx2 - tx3) - (x2 - tx2)*(ty2 - ty3);
    if(ans1*ans2 >= 0) return 1;
    else return 0;
}
bool line34(ll x1 , ll y1 , ll x2 , ll y2){
    ll ans1 = (y1 - ty3)*(tx3 - tx4) - (x1 - tx3)*(ty3 - ty4);
    ll ans2 = (y2 - ty3)*(tx3 - tx4) - (x2 - tx3)*(ty3 - ty4);
    if(ans1*ans2 >= 0) return 1;
    else return 0;
}
bool line41(ll x1 , ll y1 , ll x2 , ll y2){
    ll ans1 = (y1 - ty4)*(tx4 - tx1) - (x1 - tx4)*(ty4 - ty1);
    ll ans2 = (y2 - ty4)*(tx4 - tx1) - (x2 - tx4)*(ty4 - ty1);
    if(ans1*ans2 >= 0) return 1;
    else return 0;
}
void solve(){
    cin >> x1 >> y11 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    cin >> tx1 >> ty1 >> tx2 >> ty2 >> tx3 >> ty3 >> tx4 >> ty4;

    ll bdr1 = inf, bdr2 = -inf, bdr3 = inf , bdr4 = -inf;
    bdr1 = min(bdr1 , x1);
    bdr1 = min(bdr1 , x2);
    bdr1 = min(bdr1 , x3);
    bdr1 = min(bdr1 , x4);
    
    bdr2 = max(bdr2 , x1);
    bdr2 = max(bdr2 , x2);
    bdr2 = max(bdr2 , x3);
    bdr2 = max(bdr2 , x4);
    
    bdr3 = min(bdr3 , y11);
    bdr3 = min(bdr3 , y2);
    bdr3 = min(bdr3 , y3);
    bdr3 = min(bdr3 , y4);

    bdr4 = max(bdr4 , y11);
    bdr4 = max(bdr4 , y2);
    bdr4 = max(bdr4 , y3);
    bdr4 = max(bdr4 , y4);

    pair<ll , ll >mp = {(tx1 + tx2 + tx3 + tx4)/4 , (ty1 + ty2 + ty3 + ty4)/4};
    for(ll i = bdr1 ; i <= bdr2 ; i++){
        for(ll j =  bdr3 ; j <= bdr4 ; j++){
            bool ok = 1 ;
            if(line12(i , j , mp.f , mp.s) && line23(i , j , mp.f , mp.s) && line34(i , j , mp.f , mp.s) && line41(i , j , mp.f , mp.s)) ok = 0;
            if(!ok){
                // cout << i << " : " << j << endl;
                cout <<"Yes\n";
                return ;
            }
        }
    }
    cout <<"No\n";
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
