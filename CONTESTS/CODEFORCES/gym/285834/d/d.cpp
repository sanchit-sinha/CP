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

const ll N = 2e2 + 11;
ll n , m , a[N] , ans[N];
void solve(){
    set<ll> index;
    bool ok = 1;
    cin >> n >> m;
    rep(i , n) ans[i + 1] = -1 , index.insert(i + 1);
    rep(i , m) cin >> a[i + 1]; 
    ll prev = a[1];
    for(ll i = 2 ; i <= m ; i++){
        ll pres = a[i];
        ll x = -1 , y = -1;
        for(ll j = 1 ; j <= n + n ; j++){
            ll index = j ;
            if(index > n ) index -= n;
            if(x != -1 && index == pres) {
                y = j;
                break;
            }
            if(x == -1 &&  index == prev) x = j; 
        }
        prev = pres;
    /*
        cout << prev <<" " << pres << " " << x <<" " << y << " val " << y -x << endl;
        cout << " index " << a[i - 1] <<" val " << y - x << endl;
        nl;
      */
        if(ans[a[i - 1]] != -1 && ans[a[i - 1]] != y - x) ok = 0;
        ans[a[i - 1]] = (y - x);
    }
    /*
    rep(i , n) cout << ans[i + 1] <<" ";
    nl;
    */
    for(ll i = 1 ; i <= n ; i++){
        if(ans[i] != -1){
            auto it = index.find(ans[i]);
            if(it == index.end()) ok = 0;
            else index.erase(it); 
        }
    }
    for(ll i = 1 ; i <= n; i++){
        if(ans[i] == -1){
            ans[i] = *index.begin();
            index.erase(index.begin());
        }
    }
    map<ll ,ll> cnt;
    for(ll i = 1 ; i <= n ; i++) cnt[ans[i]]++;
    ll x = 1; 
    trav(it , cnt){
        if(it->f != x){
            ok = 0;
        } 
        else if(it->s != 1) ok = 0;
        x++;
    } 
    if(!ok) cout << -1 << endl;
    else{
        for(ll i = 1 ; i <= n ; ++i) cout << ans[i] <<" ";
        nl;
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
