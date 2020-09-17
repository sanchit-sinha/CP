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
#define mp(a , b) make_pair(a , b)
#define mt(a , b , c) make_tuple(a , b , c)
#define get(x , c) get<x>(c)
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
ll n,a[N];
void solve(){
    cin >> n;
    rep(i,n) cin >> a[i + 1];
    ll l = 1 , r = n ;
    string ans;
    ll prev = 0;
    while(l <= r){
        ll x , y;
        x = a[l] , y = a[r];
        if(x==y && x <= prev) break;
        if(l==r){
            if(x>prev) ans.pb('L');
            break;
        } 
        if(x!=y){
            if(x<=prev) x = inf;
            if(y<=prev) y = inf;
            if(x==y && x==inf) break;
            if(min(x,y) == x){
                ans.pb('L');
                l++;
                prev=x;
            }
            else{
                ans.pb('R');
                r--;
                prev=y;
            }
        }
        else{
            ll xnext , ynext;
            xnext=a[l+1];
            ynext=a[r-1];
            ll ctx = 1 ,cty=1;
            while(l+ctx <= r && a[l+ctx] > a[l+ctx - 1]) ctx++;
            while(l <= r-cty && a[r-cty] > a[r-cty + 1]) cty++;
            if(ctx>cty){
                rep(k,ctx) ans.pb('L');
                break;
            }
            else{
                rep(k,cty) ans.pb('R');
                break;
            }
        }
    }
    cout << sz(ans) << endl;
    cout << ans <<endl;
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
