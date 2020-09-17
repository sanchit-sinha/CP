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

const ll N = 3e5 + 11;
ll n , a[N] , pfx[N];
map<ll ,ll> m;
void solve(){
    cin >> n;
    ll s = 0;
    rep(i , n) {
        cin >> a[i];
        s += a[i];
    }
    rep(i , n){
        if(i == 0){
            if(a[i] > 0) pfx[i] = a[i];
        }
        else{
            if(a[i] > 0){
                pfx[i] =  pfx[i - 1] + a[i];
            }
            else pfx[i] = pfx[i - 1];
        }
    }
    ll mx = -inf , l1 = 0 , r1 = 0 , l = 0 , r = 0;
    for(ll r = 0 ; r < n; r++){
        if (m.find(a[r])==m.end()) {
            m[a[r]]=r;
        }
        else {
            l = m[a[r]];
            ll sum = pfx[r]- pfx[l-1];
            if(a[r]<0) sum+=a[r]*2LL;
            if (sum >= mx) {
                mx=sum;
                l1=l;
                r1=r;
            }
        }
    }
    l = l1 , r = r1;
    set<ll> del;
    for(ll i = l + 1 ; i < r ; i++){
        if(a[i] < 0){
            s -= a[i];
            del.insert(i);
        }
    }
    // cout << l << " " << r << endl;
    for(ll i = 0 ; i < l ; i++){
        s -= a[i];
        del.insert(i);
    }
    for(ll i = r + 1 ; i < n ; i++){
        s -= a[i];
        del.insert(i);
    }
    cout << s << " " << size(del) << endl;
    trav(it , del) cout << *it + 1<< " ";

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
