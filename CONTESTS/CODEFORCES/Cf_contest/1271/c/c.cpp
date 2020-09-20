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

const ll N = 2e5 + 11;
ll n , xs, ys;
ll cntu , cntd, cntr , cntl;
void solve(){
    cin >> n >>xs >>ys;
    rep(i,n){
        ll x , y;
        cin >> x >>y;
        if(x>xs) cntr++;
        else if(x<xs) cntl++; 

        if(y>ys) cntu++;
        else if(y<ys) cntd++;
    }   
    ll mx = -inf;
    mx = max(mx , cntu);
    mx = max(mx,cntd);
    mx = max(mx , cntr);
    mx = max(mx , cntl);
    if(mx == cntu){
        cout << cntu << endl;
        cout <<xs<<" " << ys+1 << endl;
    }
    else if(mx == cntd){
        cout << cntd <<endl;
        cout<<xs <<" " <<ys -1 << endl;
    }
    else if(mx == cntr){
        cout<< cntr <<endl;
        cout<<xs+1 << " "<<ys << endl;
    }
    else{
        cout << cntl << endl;
        cout <<xs-1<<" " <<ys <<endl;
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
        cout << "\n";
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}