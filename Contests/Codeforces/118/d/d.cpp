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
const ll mod = 1e8;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 110;
ll dp[N + N][N][2]; // dp[i][j][0 or 1] number of ways to place footman(0) or horseman(1) at the ith place such that the total number of footmen placed till i will become j
ll n1 , n2 , k1 , k2;

void solve(){
    cin >> n1 >> n2 >> k1 >> k2;
    dp[0][0][0] = dp[0][0][1] = dp[1][0][1] = dp[1][1][0] = 1;
    for(ll i = 2 ; i <= n1 + n2 ; i++){
        for(ll nf = 1 ; nf <= i ; nf++){
            for(ll j = 1 ; j <= k1 ; j++){
                if(i - j >= 0 && nf - j >= 0){
                    dp[i][nf][0] += dp[i - j][nf - j][1];
                    dp[i][nf][0] %= mod;
                }
            }
        }
        for(ll nh = 1 ; nh <= i ; nh++){
            ll nf = i - nh;
            if(nf >= 0){
                for(ll j = 1 ; j <= k2 ; j++){
                    if(i - j >= 0){
                        dp[i][nf][1] += dp[i - j][nf][0];
                        dp[i][nf][1] %= mod;
                    }
                }
            }
        }
    }    
    cout << ((dp[n1 + n2][n1][0]%mod + dp[n1 + n2][n1][1]%mod ))%mod << endl;
    rep(i , n1 + n2 + 8){
        rep(j , n1 + 8) dp[i][j][0] = dp[i][j][1] = 0;
    } 
    n1 = n2 = k1 = k2 = 0;
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
