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
ll n , k , t[N] , a[N] , b[N];
vll book1 , book2 , both;
void solve(){
    cin >> n >> k;
    ll l1 = 0 , l2 = 0;
    rep(i , n){
        cin >> t[i] >> a[i] >> b[i];
        if(a[i] == b[i] && a[i] == 1 && b[i] == 1) both.pb(t[i]);    
        if(a[i] == 1 && b[i] == 0) book1.pb(t[i]);
        if(b[i] == 1 && a[i] == 0) book2.pb(t[i]); 
        l1 += (a[i] == 1);
        l2 += (b[i] == 1);
    }
    sort(all(book1));
    sort(all(book2));
    sort(all(both));

    if(l1 < k || l2 < k){
        cout << -1 << endl;
        return;
    } 
    ll ans = 0;
    ll sz1 = book1.size();
    ll sz2 = book2.size();
    for(ll i = 0 ; i < min({sz1 , sz2 , k}) ; i++) ans += book1[i] + book2[i];
    ll ct = min({sz1 , sz2 , k});
    if(sz1 > ct){
        while(sz1 != ct){
            book1.pop_back();
            sz1--;
        }
    }
    if(sz2 > ct){
        while(sz2 != ct){
            book2.pop_back();
            sz2--;
        }
    }
    for(ll i = 0 ; i < (int)(both.size()) ; i++){
        if(ct < k){
            ans += both[i];
            ct++;
        }
        else{
            ll sz1 = book1.size();
            ll sz2 = book2.size();
            if(sz1 > 0 && sz2 > 0){
                ll lt1 = *book1.rbegin();
                ll lt2 = *book2.rbegin();
                if(lt1 + lt2 >= both[i]){
                    ans -= lt1 , ans -= lt2;
                    book1.pop_back() , book2.pop_back();
                    ans += both[i];
                }
            }
        }
    }
    cout << ans << endl;
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
