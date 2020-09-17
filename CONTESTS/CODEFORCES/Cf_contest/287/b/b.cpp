#include "bits/stdc++.h"
using namespace std;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
#define ll unsigned long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define trav(a,x) for(auto a = x.begin() ; a != x.end() ; a++)
#define mp(a , b) make_pair(a , b)
#define mt(a , b , c) make_tuple(a , b , c)
#define get(x , c) get<x>(c)
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
ll n, k;
bool check(ll mid , ll k){
    mid = k - mid + 1;
    ll num = (k*(k+1))/2 - ((mid - 1)*mid)/2 - (k - mid);
    if(num <= n) return true;
    else return false;
}
void solve(){
    cin >> n >> k;
    ll l = 1 , r = k - 1, mid = 0 , ans = 0;
    if(n == 1 || n >= (k*(k+1))/2){
        if(n == 1) cout<< 0<<endl;
        elsecout <<-1 <<endl;
        return;
    }
    if(n <= k && n > 1){
        cout << 1 << endl;
        return; 
    }
    while(l<=r){
        mid = l+(r-l)/2;
        if(check(mid , k)) l = mid+1, ans = mid;
        else r = mid-1;
    }
    mid = k-ans+1;
    ll num = (k*(k+1))/2 - ((mid - 1)*mid)/2 - (k-mid+1);
    n -= num;
    if(n == 1) cout << ans << endl;
    else if(n > 1 && n < mid) cout <<ans + 1 << endl;
    else cout << -1 <<endl;
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
