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

const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 2e5 + 1;
vll v[201];
ll n , a[N];
ll ans = 0;
void construct_three_block(vll b){
    ll l = 0 , r = b.size() - 1 , x = 0 , y = 0;
    ll n = b.size();
    trav(it , b) y += *it;
    ans = max(ans , y);
    for( ; l < r ; l++){
        if(b[l] == 0){
            x++;
            for( ; r > l ; r--){
                if(b[r] == 0){ 
                    ans = max(ans , x + y + x);
                    r--;
                    break;
                }
                else --y;

            }
        }
        else --y;
    }
}
void solve(){
    cin >> n;
    rep(i , n){
        cin >> a[i];
        v[a[i]].pb(i);
    }
    for(ll i = 1 ;  i <= 200 ; i++){
        for(ll j = 1 ; j <= 200 ; j++){
            ll l1 = v[i].size() , l2 = v[j].size();
            if(l1 > 0 && l2 > 0){
                if(i == j) ans = max(ans , l1);
                else{
                    vll b;
                    ll x , y;
                    for(x = 0 , y = 0 ; x < l1 && y < l2 ;){
                        if(v[i][x] < v[j][y]) {
                            b.pb(0);
                            x++;
                        }
                        else {
                            b.pb(1) ;
                            y++;
                        }
                    }
                    if(l1 == 0) for( ; y < l2 ; y++) b.pb(1);
                    else for( ; x < l1 ; x++) b.pb(0);
                    construct_three_block(b);
                }
            }
        }
    }
    cout << ans << endl;
    // cout <<" ----------------- \n";
    rep(i , 201) v[i].clear() ;
    rep(i , n) a[i] = 0;
    n =0 , ans = 0;
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
