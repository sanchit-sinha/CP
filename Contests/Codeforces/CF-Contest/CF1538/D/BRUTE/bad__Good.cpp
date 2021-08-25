#include<bits/stdc++.h>
using namespace std;
/*-----------------------------------------------------------------------------------------*/
#define ll long long
#define ld long double
#define pb push_back
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define ub upper_bound
#define lb lower_bound
#define all(v) ((v).begin()),((v).end())
#define allr(v) ((v).rbegin()),((v).rend())
#define ff first
#define ss second
#define mp make_pair
#define pll pair<ll,ll> 
#define fo(i,n) for(ll i=0;i<n;i++)
#define foa(i,s,e) for(ll i=(s);i<=e;i++)
#define fod(i,s,e) for(ll i= (s);i>=(e);i--)
#define deb(x) cerr<<#x<<' '<<'='<<' '<<x<<'\n'
#define sz(x) (ll)(x.size())
#define ANS cout<<ans<<'\n'
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define Yes cout<<"Yes\n"
#define No cout<<"No\n"
/*-----------------------------------------------------------------------------------------*/
#define fill(a,b) memset(a, b, sizeof(a))
#define setbits(x) __builtin_popcountll(x)
#define vout(v) for(auto &x : v){cout << x << " ";}cout << nl;
#define vin(v) for (auto &x : v){cin >> x;}
#define print2d(dp,n,m) fo(i, n){fo(j, m)cout<<dp[i][j]<<" ";cout<<"\n";}
/*-----------------------------------------------------------------------------------------*/
const ld pi = 3.14159265358979323846;
ll MOD = 1e9 + 7;
//ll MOD = 998244353;
const char nl = '\n';
const ll inf = 2000000000000000000;
/*-----------------------------------------------------------------------------------------*/
void kmax(ll &a, ll b){
    if(b > a)a = b;
}
void kmin(ll &a, ll b){
    if(b < a)a = b;
}
ll nxt(){ll x; cin >> x; return x;}
ll mul(ll x,ll y){
    return (1ll* (x%MOD)*(y%MOD));
}
ll modpow(ll x,ll y){ll z=1;while(y>0){if(y%2)z=mul(z,x);x =mul(x,x) ;y/=2;}return z;}
ll power(ll x,ll y){ll z=1;while(y>0){if(y%2)z=z*x;x =x*x ;y/=2;}return z;}
ll gcd(ll a,ll b){if(a<b) return gcd(b,a);if(b==0) return a;return gcd(b,a%b);} 
ll min(ll a,ll b){if(a<b)return a;return b;}
ll max(ll a,ll b){if(a>b)return a;return b;}
ll sq(ll a){
    ll ans = (1ll*a*a);
    return ans;
}
ll inv(ll n){
    return modpow(n,MOD-2);
    
}
ll divide(ll x,ll y){
    return mul(x,inv(y));
}
/*-----------------------------------------------------------------------------------------*/
// const ll N = 3e5 + 5;
// bitset<N> dp;
// void partition(vll &v){
//     ll n = sz(v);
//     fo(i, n){
//         dp |= dp << v[i];
//     } 
// }
/*-----------------------------------------------------------------------------------------*/
const int N = 40000;
int lp[N+1];
vector<int> pr;

void sieve() 
{ 
   
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }

} 
void solve(){
    ll a, b, k;
    cin >> a >> b >> k;
    ll na = a, nb = b;
    ll c = 0;

    cout << pr.size();
    for(ll x : pr){
        while(na % x == 0){
            c++;
            na/=x;
        }
        while(nb % x == 0){
            c++;
            nb/=x;
        }
    }
    if(na > 1)c++;
    if(nb > 1)c++;
    if(k == 1){
        if(max(a,b) % min(a, b) == 0 && a != b)YES;
        else NO;
    } else {
        cout << (c >= k? "YES":"NO") << nl;
    }
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    sieve();
    ll TC = 1;
    cin>>TC;
    fo(TT, TC){
        //cout << "Case #"<< TT + 1 << ": ";
        solve();
    }
}
