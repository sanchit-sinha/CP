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

const ll N = 1e2 + 1;
ll n;
vll a(N);
vpll rem;
void solve(){
    cin >> n;
    ll s= 0 ;
    rep(i , n) cin >> a[i] , s+= a[i]; 
    ll ans = 0;
    ll prty = a[0];
    if(prty > s/2){
        cout << 1 << endl;
        cout << 1 << endl;
        return ;
    }
    ll s1 = 0;
    rep(i , n){
        if(a[i]*2 <= a[0]){
            rem.pb({a[i] , i});
            s1 += a[i];
        }
    }
    if(s1 + prty > s/2){
        ll len = rem.size();
        cout << 1 + len << endl;
        cout << 1 <<" ";
        for(ll i =0 ; i < len ; i++) cout << rem[i].s + 1 <<" ";
        nl;
    }
    else cout << 0 << endl;
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
