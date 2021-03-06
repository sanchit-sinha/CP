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
ll n;
bool dp[N][6]; //placing jth finger on the ith place 
ll a[N];
ll save[N][6];
vll ans;
bool check(ll x){
    ans.clear();
    ll i = n - 1;
    ans.pb(x);
    while(save[i][x] != -1){
        ans.pb(save[i][x]);
        x = save[i][x];
        i--;
    }
    bool crct = 1;
    reverse(all(ans));
    ll len = ans.size();
    if(len != n) return false;
    else{
        for(ll i =1 ; i < n ; i++){
            if(a[i] > a[i - 1]){
                if(ans[i] <= ans[i - 1]){
                    crct = 0;
                    break;
                }
            }
            else if(a[i] < a[i - 1]){
                if(ans[i] >= ans[i - 1]){
                    crct = 0;
                    break;
                }
            }
            else if(a[i] == a[i -1]){
                if(ans[i] == ans[i - 1]){
                    crct = 0;
                    break;
                }
            }
        }
    }
    return crct;
}
void solve(){
    cin >> n;
    rep(i , n) cin >> a[i];
    rep(i , n) {
        rep(j , 5) save[i][j + 1] = -1;
    }
    for(ll i = 1 ; i < 6 ;i++) dp[0][i] = 1;
    for(ll i = 1 ; i < n ; i++){
        for(ll j = 1 ; j <= 5 ; j++){
            // dp[i][j];
            if(a[i] > a[i - 1]){
                for(ll l = 1 ; l < j ; l++){
                    if(dp[i - 1][l] == 1){
                        dp[i][j] = 1;
                        save[i][j] = l;
                    }
                }
            }
            else if(a[i] < a[i - 1]){
                for(ll l = j + 1 ; l <= 5 ; l++){
                    if(dp[i - 1][l] == 1){
                        dp[i][j] = 1;
                        save[i][j] = l;
                    }
                }
            }
            else if(a[i] == a[i - 1]){
                for(ll l = 1 ; l <= 5 ; l++){
                    if(l != j && dp[i - 1][l] == 1){
                        dp[i][j] = 1;
                        save[i][j] = l;
                    }
                }
            }
        }
    }
    for(ll j = 1 ; j <= 5 ; j++){
        if(dp[n - 1][j] == 1){
            if(check(j)){
                trav(it , ans) cout << *it <<" ";
                return;
            }
        }
    }
    cout << -1 << endl;
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