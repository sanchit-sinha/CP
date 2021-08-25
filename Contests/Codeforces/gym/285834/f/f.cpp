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

const ll N = 2750131 + 1;
ll n ;
multiset<ll> s;
vll ans , pr(N);
vector<bool> prime(N , true);
ll spf[N];
void sieve(ll n){
    spf[1] = 1;
    ll index = 1;
    for(ll i = 2 ; i < n ; i++){
        if(prime[i]){
            pr[i] = index++;
            for(ll j = i * i ; j < n ; j += i) prime[j] = 0;
        }
    }
    for(ll i = 2 ; i < n; i++){
        if(!spf[i]){
            for(ll j = i * i ; j < n; j += i) if(!spf[j]) spf[j] = i;
        }
    }
}
void solve(){
    sieve(N);
    cin >> n;
    rep(i , n + n){
        ll x;
        cin >> x;
        s.insert(x);
    }
    while(!s.empty()){
        auto it = --s.end();
        ll ele = *it;
        s.erase(s.find(ele));
        if(prime[ele]) s.erase(s.find(pr[ele])) , ans.pb(pr[ele]);
        else s.erase(s.find(ele/spf[ele])) , ans.pb(ele);
    }
    trav(it , ans) cout << *it <<" ";
    nl;
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
