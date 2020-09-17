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

const ll N = 2e5 + 11;
ll n , k , pfx1[N] , pfx2[N] , pfx3[N];
vll book1 , book2 , both;
void solve(){
    cin >> n >> k;
    ll l1 = 0 , l2 = 0 , l3 = 0;
    rep(i , n){
        ll x , y , z;
        cin >> x >> y >> z;
        if(y == z && y == 1 && z == 1) both.pb(x);    
        if(y == 1 && z == 0) book1.pb(x);
        if(z == 1 && y == 0) book2.pb(x); 
        l1 += (y == 1);
        l2 += (z == 1);
    }
    sort(all(book1));
    sort(all(book2));
    sort(all(both));

    if(l1 < k || l2 < k){
        cout << -1 << endl;
        return;
    } 
    l1 = book1.size() , l2 = book2.size() , l3 = both.size();
    for(ll i = 0 ; i < l1 ; i++){
        pfx1[i + 1] = pfx1[i] + book1[i];
    }
    for(ll i = 0 ; i < l2 ; i++){
        pfx2[i + 1] = pfx2[i] + book2[i];
    }
    for(ll i = 0 ; i < l3 ; i++){
        pfx3[i + 1] = pfx3[i] + both[i];
    } 

    ll ans = inf;
    for(ll i = 0 ; i <= l3 ; i++){
        if(k - i <= l1 && k - i <= l2) ans = min(ans , pfx3[i] + pfx1[k - i] + pfx2[k - i]);
    }
    cout << ans << endl;
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
