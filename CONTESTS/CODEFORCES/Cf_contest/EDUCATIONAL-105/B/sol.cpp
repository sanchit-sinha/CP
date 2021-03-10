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

const ll N = 1e2+11;
ll ans[17][N][N];
ll n , u , r ,d , l;

bool check(vector<vll> v , ll n ,ll u ,ll r ,ll d ,ll l){
    if(u < 0) return 0;
    if(r < 0) return 0;
    if(d < 0) return 0;
    if(l < 0) return 0;

    FOR(j , 1 , n - 2){
        if(u== 0) break;
        v[0][j] = 1;
        u -= 1;        
    }

    FOR(j , 1 , n - 2){
        if(d == 0) break;
        v[n - 1][j] = 1;
        d -= 1;        
    }

    FOR(i , 1 , n - 2){
        if(l == 0) break;
        v[i][0] = 1;
        l -= 1;
    }

    FOR(i , 1 , n - 2){
        if(r == 0) break;
        v[i][n - 1] = 1;
        r -= 1;
    }

    if(u != 0) return 0;
    if(r != 0) return 0;
    if(d != 0) return 0;
    if(l != 0) return 0;
    return 1;
}
void solve(){
    rep(i , 17){
        rep(j , n){
            rep(k , n){
                ans[i][j][k] = 0;
            }
        }
    }
    cin >> n >>  u >> r >> d >> l;

    ll upper[17] , left[17] , right[17] , down[17];
    rep(i , 17){
        upper[i] = u;
        left[i] = l;
        right[i] = r;
        down[i] = d;
    }

    // no corner 1 
    

    // ul = 1 
    // ll ans[2][n + 11][n + 11] = {0};
    ans[2][0][0] = 1;
    upper[2]--;
    left[2]--;

    // ur = 1
    // ll ans[3][n + 11][n + 11] = {0};
    ans[3][0][n - 1] = 1;
    upper[3]--;
    right[3]--;

    // dl = 1
    // ll ans[4][n + 11][n + 11] = {0};
    ans[4][n - 1][0] = 1;
    down[4]--;
    left[4]--;

    // rd = 1
    // ll ans[5][n + 11][n + 11] = {0};
    ans[5][n - 1][n - 1] = 1;
    right[5]--;
    down[5]--;

    // ul ur = 1
    // ll ans[6][n + 11][n + 11] = {0};
    ans[6][0][0] = 1;
    ans[6][0][n - 1] = 1;
    upper[6] -= 2;
    left[6] -= 1;
    right[6] -= 1;
    
    // ul = 1 , dl = 1;
    // ll ans[7][n + 11][n + 11] = {0};
    ans[7][0][0] = 1;
    ans[7][n - 1][0] = 1;
    upper[7] -= 1;
    left[7] -= 2;
    down[7] -= 1;

    // ul = 1 , dr = 1
    // ll ans[8][n + 11][n + 11] = {0};
    ans[8][0][0] = 1;
    ans[8][n - 1][n - 1] = 1;
    upper[8] -= 1;
    left[8] -= 1;
    down[8] -= 1;
    right[8] -= 1;

    // ur = 1 , dl = 1;
    // ll ans[9][n + 11][n + 11] = {0};
    ans[9][0][n - 1] = 1;
    ans[9][n - 1][0] = 1;
    upper[9] -= 1;
    right[9] -= 1;
    down[9] -= 1;
    left[9] -= 1;

    // ur = 1 , dr = 1;
    // ll ans[10][n + 11][n + 11] = {0};
    ans[10][0][n - 1] = 1;
    ans[10][n - 1][n - 1] = 1;
    upper[10] -= 1;
    right[10] -= 2;
    down[10] -=1 ;

    // dl = 1 , dr = 1;
    // ll ans[11][n + 11][n + 11] = {0};
    ans[11][n - 1][0] = 1;
    ans[11][n - 1][n - 1] = 1;
    down[11] -= 2;
    right[11] -= 1;
    left[11] -= 1;

    // ur = 1 , ul = 1 , dl = 1;
    // ll ans[12][n + 11][n + 11] = {0};
    ans[12][0][n - 1] = 1;
    ans[12][0][0] = 1;
    ans[12][n - 1][0] = 1;
    upper[12] -= 2;
    right[12] -= 1;
    left[12] -= 2;
    down[12] -= 1;


    // ur = 1 , ul = 1 , dr = 1;
    // ll ans[13][n + 11][n + 11] = {0};
    ans[13][0][n - 1] = 1;
    ans[13][0][0] = 1;
    ans[13][n - 1][n - 1] = 1;
    upper[13] -= 2;
    right[13] -= 2;
    left[13] -= 1;
    down[13] -= 1;

    // ur = 1 , dl = 1 , dr = 1;
    // ll ans[14][n + 11][n + 11] = {0};
    ans[14][0][n - 1] = 1;
    ans[14][n - 1][0] = 1;
    ans[14][n - 1][n - 1] = 1;
    upper[14] -= 1;
    right[14] -= 2;
    left[14] -= 1;
    down[14] -= 2;
    
    // ul = 1 , dl = 1 , dr = 1
    // ll ans[15][n + 11][n + 11] = {0};
    ans[15][0][0] = 1;
    ans[15][n - 1][0] = 1;
    ans[15][n - 1][n - 1] = 1;
    upper[15] -= 1;
    right[15] -= 1;
    left[15] -= 2;
    down[15] -= 2;

    // ur = 1 , ul = 1 , dr = 1, dl = 1;
    // ll ans[16][n + 11][n + 11] = {0};
    ans[16][0][0] = 1;
    ans[16][0][n - 1] = 1;
    ans[16][n - 1][0] = 1;
    ans[16][n - 1][n - 1] = 1;
    upper[16] -= 2;
    down[16] -= 2;
    right[16] -= 2;
    left[16] -= 2;

    bool ok = 0;
    FOR(i ,1 , 16){
        vector<vll> v;
        rep(j , n){
            vll ax;
            rep(k , n){
                ax.pb(ans[i][j][k]);
            }
            v.pb(ax);
        }
        if(check(v , n , upper[i] , right[i] , down[i] , left[i])){
            ok = 1;
            break;
        }
    }

    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    IOS;
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

