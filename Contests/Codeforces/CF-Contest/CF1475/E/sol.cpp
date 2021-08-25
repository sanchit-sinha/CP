#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define mp make_pair
#define mt make_tuple
#define get(x,c) get<x>(c)
#define trav(a,x) for(auto a=x.begin();a!=x.end();a++)
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,b,a) for(int i=b;i>=a;i--)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define f first
#define s second

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e3+11;

ll fact[N],invfact[N];
void factorial(){
    fact[0]=invfact[0]=1;
    for(ll i=1;i<N;i++){
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
    }
    invfact[N-1]=powermod(fact[N-1],mod-2,mod);
    for(ll i=N-2;i>0;i--){
        invfact[i]=invfact[i+1]*(i+1);
        invfact[i]%=mod;
    }
}
ll ncr(ll n,ll r){
    if(r > n || n < 0 || r < 0)return 0;
    ll p=(fact[n]*invfact[r])%mod;
    p*=invfact[n-r];

    return p%mod;
}
void solve(){
    ll n ,k ;
    cin >> n >> k;
    vll a;

    rep(i , n){
        ll x;
        cin >> x;
        a.pb(x);
    }

    sort(all(a));
    reverse(all(a));
    map<ll,ll> ct;

    rep(i , n) ct[a[i]]++;

    ll ele = a[k - 1];
    
    ll num = 0;
    FORR(i , k - 1 , 0){
        if(a[i] == ele) num++;
    } 


    ll xx = ct[ele];

    // cout << xx <<" " << num << "\n";
    ll ans = ncr(xx , num);

    cout << ans << "\n";
}

int main(){
    IOS;
    factorial();
    cout<<fixed<<setprecision(20);
    ll NTC=1;
    cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

