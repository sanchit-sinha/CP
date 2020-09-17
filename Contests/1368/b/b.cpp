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
ll k;
void solve(){
    cin >> k;
    string s = "codeforces";
    ll l = 1 , r = 60 , mid = 0;
    ll ans = 0;
    while(l <= r){
        mid = l + (r - l)/2;
        if(power(mid , 10) <= k){
            ans = mid;
            l = mid + 1;
        } 
        else r = mid - 1;
    }
    ll ct[11] = {0};
    rep(i , 10) ct[i + 1] = ans;
    ll num = power(ans , 10);
    for(ll i = 1 ; i <= 10 ; i++){
        if(num >= k) break;
        else{
            num /= ans;
            num *= (ans + 1);
            ct[i] = ans + 1;
        }
    }
    for(ll i = 0 ; i < 10 ; i++){
        for(ll j = 0 ; j < ct[i + 1] ; j++ ) cout << s[i];  
    }
    nl;
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
