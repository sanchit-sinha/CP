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

const ll N = 2e5 + 1;
ll n , k , a[N];
void solve(){
    cin  >> n >> k;
    vll rem;
    map <ll , ll > m;
    rep(i , n) cin >> a[i];
    for(ll i = 0 ; i < n ; i++){
        ll x= a[i]%k;
        if(x != 0){
            x = k - x;
            m[x]++;
        }
    } 
    trav(it , m){
        ll ct = it->s;
        ll x = it->f;
        for(ll i =0  ; i < ct ; i++){
            rem.pb(x + k*i);
        }
    }
    sort(all(rem));
    ll prev = 0;
    ll ans =0 ;
    ll len = rem.size();
    if(len) ans = *rem.rbegin();
    if(len)cout << ans + 1  << endl;
    else cout << ans << endl;
    rep(i , n) a[i] = 0;
    n = k = 0;
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
