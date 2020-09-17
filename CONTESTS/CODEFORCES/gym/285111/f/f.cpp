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

const ll N = 3e2 + 11;
ll n , b[N];
ll dig(ll x){
    ll val = (x + 9 - 1)/9;
    return val;
}
bool poss(ll k , ll d , ll sum , ll pres , ll j){
    // if(d == 2) cout <<" k " << k <<" d " << d << " sum " << sum <<" pres " << pres <<" j " <<j << endl;
    ll rem = d - 1 - j;
    if(rem < 0) rem = 0;
    // if(d == 2) cout << " rem " << rem <<" vak " << pres + k + 9*rem << endl;nl;nl;
    if(rem == 0 && pres + k == sum) return true;

    ll mx = pres + k + 9*(rem);
    // cout <<" mx ::" << mx << endl;
    // nl;
    if(mx >= sum) return true;
    else return false;
}
ll ct(ll x){
    ll val =0 ;
    while(x > 0 ) x/=10 , val++;
    return val;
}
vll calc(ll d , ll sum){
    vll v;
    ll pres = 0;
    for(ll j = 0 ; j < d; j++){
        if( j== 0){
            for(ll k = 1 ; k <= 9 ; k++) {
                if(poss(k , d , sum , pres , j)){
                    v.pb(k);
                    pres += k;
                    break;
                }
            }
        }
        else{
            for(ll k= 0 ; k <= 9 ; k++){
                if(poss(k , d , sum , pres , j )){
                    v.pb(k);
                    pres += k;
                    break;
                }
            }
        }
    }
    return v;
}
vll calceq(ll d , ll prevele , ll sum){
    ll mx = 9*d , req = -1;
    for(ll i = prevele + 1 ; i <= mx ; i++){
        ll ans = 0 ;
        for(ll j = 1 ;j <= d ; j++){
            ll x = i%(power(10 , j))
            ans += x;
        }
        if(ans == sum){
            req = i;
            break;
        }
    }
    if(req == -1) return 0 ;
    else {

    }
}
ll check(vll v , ll prevele , ll sum){
    ll len = v.size();
    ll val = 0 ;
    for(ll i = 0 ; i < len ; i++){
        val += v[i] * power(10 , len - 1 - i);
    }
    cout << "-------------\n";
    cout << "in func " << val <<" " << prevele << " sum " << sum << endl;
    if(val <= prevele){ 
        if(calceq(len , prevele , sum)){
            val = calceq(len , prevele , sum);
            return val;
        }
        else calc()
    }
    else return val;
    len = v.size();
    val = 0;
    for(ll i = 0 ; i < len ; i++){
        val += v[i] * power(10 , len - 1 - i);
    }
    return val;
}
void solve(){
    cin >> n;
    rep(i , n) cin >> b[i];
    ll prev = -1 , prevele = -1;
    for(ll i = 0 ; i < n; i++){
        ll ele = b[i];
        ll d = dig(ele);
        vll v = calc(max(prev , d), ele);
        ll num = check(v , prevele , ele);
        // cout <<" +++++++++++++++++=\n";
        cout << num << endl;
        // cout <<"+++++++?++++++++++++\n";
        prev = ct(num) , prevele = num;
    }
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
