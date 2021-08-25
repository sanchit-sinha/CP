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
ll k , n ; string s;
ll dp[N];// dp[i] - number of segments ending at i
ll pfx[N];

void solve(){
    cin >> k >> s;
    n = s.size();
    if(k == 0){
        ll ans = 0 , ct = 0;
        rep(i ,n ) {
            if(s[i] == '0') ct++;
            else{
                ans += (ct*(ct + 1))/2;
                ct = 0;
            }
        }
        if(ct) ans += ((ct)*(ct + 1))/2;
        cout << ans << endl;
        return;
    }
    map<ll , ll> cnt;
    cnt[0] = 1;
    for(ll i = 0 ; i < n ; i++){
        if(i == 0){
            if(s[i] - '0') pfx[i] = 1;
        }
        else{
            if(s[i] - '0') pfx[i] = pfx[i - 1] + 1;
            else pfx[i] = pfx[i - 1];
        }
        cnt[pfx[i]]++;
    }
    for(ll i = 0 ; i < n ; i++){
        if(pfx[i] >= k){
            dp[i] = cnt[pfx[i] - k];
        }
    } 
    ll ans = 0;
    // for(ll i = 0; i  <n ; i++) cout << i << " : " << dp[i] << endl;
    for(ll i =0 ; i < n ; i++) ans += dp[i];
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
