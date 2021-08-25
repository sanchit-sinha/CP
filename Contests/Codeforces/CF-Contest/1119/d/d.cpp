#include "bits/stdc++.h"
using namespace std;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
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
ll n , a[N] , pfx[N];
vll dif;
void solve(){
    cin >> n;
    rep(i , n) cin >> a[i];
    sort(a , a + n);
    vll ar ;
    ar.pb(a[0]);
    for(ll i = 1 ; i < n ; i++){
        if(a[i] != a[i - 1]) ar.pb(a[i]);
    }
    for(ll i = 1 ; i < sz(ar) ; i++) dif.pb(ar[i] - ar[i - 1]);
    sort(all(dif));
    for(ll i = 0 ; i < sz(dif) ; i++){
        pfx[i + 1] = pfx[i] + dif[i];
    }
    ll q;
    cin >> q;
    while(q--){
        ll l , r;
        cin >> l >> r;
        ll ans = r - l + 1;
        auto it = ub(all(dif) , r - l);
        if(it != dif.end()){
            ll len = sz(dif);
            ll len_start = it - dif.begin();
            ll rem = len - len_start;
            ans += pfx[len_start];
            ans += rem*(r - l + 1);
        }
        else ans += pfx[sz(dif)];
        cout << ans << " ";
    }
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
