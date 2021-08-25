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

const ll N = 1e5+11;

void print(vector<vll> a){
    ll n = sz(a);
    ll m = sz(a[0]);
    rep(i , n){
        rep(j , m) cout << a[i][j] << " ";
        cout << "\n";
    }
    cout << "\n\n";
}
ll val(ll x , ll y){
    ll ans = 0;

    ll mn = min(x , y);
    ll mx = max(x , y);
    mx = min(mx , 2*mn);
    if(mx != 2*mn){
        mn = mx/2;
        mx = 2*mn;
    }
    if(mn >= 2 && mx >= 2) ans += (mn - 1);

    mx = max(x , y);
    mn = min(x , y);
    mx = mn/2;
    mn = 2*mx;
    if(mx >= 2 && mn >= 2) ans += (mx - 1);

    return ans;
}
void solve(){
    ll n , m;
    cin >> n >> m;
    vector<vll> a(n , vll(m , 0));
    rep(i , n){
        rep(j , m) cin >> a[i][j];
    }

    vector<vll> u(n , vll(m , 0));
    vector<vll> l(n , vll(m , 0));
    vector<vll> r(n , vll(m , 0));
    vector<vll> d(n , vll(m , 0));
   
    rep(i , n){
        rep(j , m){
            u[i][j] = d[i][j] = r[i][j] = l[i][j] = a[i][j];
        }
    }

    FOR(i , 1 , n - 1){
        FOR(j , 0 , m - 1){
            if(a[i][j]) u[i][j] = u[i - 1][j] + 1;
        }
    } 
    FOR(i , 0 , n - 1){
        FOR(j , 1 , m - 1){
            if(a[i][j]) r[i][j] = r[i][j - 1] + 1;
        }
    }
    FORR(i , n - 2 , 0){
        FOR(j , 0 , m - 1){
            if(a[i][j]) d[i][j] = d[i + 1][j] + 1;
        }
    }
    FOR(i , 0 , n - 1){
        FORR(j , m - 2 , 0){
            if(a[i][j]) l[i][j] = l[i][j + 1] + 1;
        }
    }

    // print(u);
    // print(l);
    // print(r);
    // print(d);

    ll ans = 0;
    rep(i , n){
        rep(j , m){
            ll upper = u[i][j];
            ll left = l[i][j];
            ll right = r[i][j];
            ll lower = d[i][j];
        
            ans += val(upper , left);
            ans += val(upper , right);
            ans += val(lower , left);
            ans += val(lower , right);
        }
    }

    cout << ans << "\n";
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        factorial();
    #endif
    ll NTC=1;
    cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
