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

const ll N = 1e3 + 11;
ll n ,a[N];
ll mex(){
    map<ll,ll>cnt;
    rep(i , n + 1) cnt[i] = 0;
    for(ll i = 0 ; i < n; i++) cnt[a[i]]++;
    for(ll i = 0 ; i <= n; i++) if(cnt[i] == 0) return i;
    return 0;
}
bool ok(){
    ll x = a[0];
    for(ll i = 1 ; i <n; i++){
        if(a[i] < x) return false;
        x = a[i];
    }
    return true;
}
void solve(){
    cin >>  n;
    rep(i , n) cin >> a[i];
    nl;
    rep(i  , n) cout << i <<" ";
    nl;
    vll index;
    while(1){
        if(ok()) break;
        ll mx = mex();
        cout << " mx " << mx << endl;
        rep(i , n) cout << a[i] << " ";
        nl;
        if(mx != n){
            cout << " ele " << a[mx] << " " << mx << endl;
            a[mx] = mx;
            index.pb(mx + 1);
        }
        else{
            for(ll j = 0 ; j < n; j++){
                if(a[j] != j){
                    cout << " ele " << a[j] << " " << n << endl;
                    a[j] = n;
                    index.pb(j + 1);
                }
            } 
        }
    }
    cout <<" ARRAY \n";
    for(ll i = 0 ; i <n ; i++) cout << a[i] << " ";
    nl;
    cout << sz(index) << endl;
    for(ll i =0 ; i < sz(index) ; i++) cout << index[i] << " ";
    nl;

    rep(i , n) a[i] = 0;
}
int main(){
    IOS;
    cout << fixed << setprecision(20);
    ll NTC = 1;
    cin >> NTC;
    ll PTC = 0;
    while(PTC++ < NTC){
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
