#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define nl cout << "\n"
#define endl "\n"
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define mp make_pair
#define mt make_tuple
#define get(x,c) get<x>(c)
#define trav(a,x) for(auto a=x.begin() ; a!=x.end() ; a++)
#define rep(i,n) for(int i=0 ; i<n ; i++)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define f first
#define s second

inline ll max(ll a,ll b) {return ((a>b)?a:b);}
inline ll min(ll a,ll b) {return ((a>b)?b:a);}
inline ll gcd(ll a ,ll b) {if(b==0) return a; a%=b;return gcd(b,a);}
ll power(ll x,ll y){if(y == 0) return 1; ll a = power(x,y/2);if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x,ll ex ,ll md) {ll ans = 1ll;while(ex > 0){if(ex & 1ll) ans = (ans*x)%md; ex >>= 1ll;x=(x*x)%md;}return ans;}

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5 + 11;
ll n;
ll lcm(ll x , ll y){
    if(x == 0 || y == 0) return inf;
    return (x*y)/gcd(x,y);
}
void solve(){
    cin>>n;
    ll ans = inf;
    ll x , y;
    for(ll i = 1 ; i*i<= n ; i++){
        if(n%i == 0){
            ll div1 = i , div2 = n/i;
            ll b1 = n - div1 , b2 = n - div2;
            // cout << div1 <<" " << b1 <<" " << div2 <<" " << b2 << endl;
            ans = min(ans , lcm(div1,b1));
            if(ans == lcm(div1,b1)){
                x = div1,y = b1;
            }
            ans = min(ans , lcm(b2,div2));
            if(ans == lcm(div2 , b2)){
                x = div2 , y = b2;
            }
        }
    }
    cout << x << " " << y <<endl;
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
        cout << "\n";
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
