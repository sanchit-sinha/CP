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

void solve(){
    ll n , k;
    cin >> n >> k;
    bool vis[k] = {0};
    ll a[n];
    ll mark = -1;
    rep(i , n){
        cin >> a[i];
        a[i] %= k;
        if(a[i] == 1) mark = 1;
        else if(a[i] == 0) vis[0] = 1;
    }
    if(mark == 1) {
        cout << k << endl;
        rep(i , k) cout << i <<" ";
        nl;
    }
    else{
        for(ll i = 0 ; i< n ; i++){
            if(!vis[a[i]] && a[i] != 0){
                // cout << i << " : " << a[i] << endl;
                for(ll j = a[i] ; j <= k ; j += a[i]){
                    // cout << j <<" ";
                    vis[j%k] = 1;
                }
                // nl;
            }
        }
        ll ans =0 ;
        for(ll i = 0 ; i < k ; i++) if(vis[i] == 1) ans++;
        cout << ans << endl;
        for(ll i = 0 ; i < k ; i++) if(vis[i]) cout <<i << " ";
        nl;
    }
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
