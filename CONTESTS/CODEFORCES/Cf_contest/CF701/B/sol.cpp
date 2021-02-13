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


void solve(){
    ll n , q , k;
    cin >> n >> q >> k;
    ll a[n + 11] = {0};
    rep(i , n) cin >> a[i + 1];

    ll left[n + 11] = {0};
    ll right[n + 11] = {0};

    FOR(i , 1 , n){
        if(i > 1) left[i] =  left[i - 1] + (a[i] - a[i - 1] - 1);
        if(i < n) right[i] = right[i - 1] + (a[i + 1] - a[i] - 1);
    }


    right[n] = right[n - 1];

    // FOR( i , 1 , n) cout << right[i] << " ";
    // cout << "\n";

    while(q--){
        ll l , r;
        cin >> l >> r;

        ll ans = 0 ;
        if(l == r) {
            ans = (k - 1);
        }
        else{
            ans += (a[l] - 1);

            // cout << " 1 : " << ans << "\n";
            ans += (k - a[r]);

            // cout << " 2 : " << ans << "\n";
            ans += right[r - 1] - right[l - 1];

            // cout << " 3 : " << ans << "\n";


            ans += left[r] - left[l];
            // cout << " 4 : " << ans << "\n\n";
        }

        cout << ans << "\n";
    }
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    ll NTC=1;
    // cin>>NTC;
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

