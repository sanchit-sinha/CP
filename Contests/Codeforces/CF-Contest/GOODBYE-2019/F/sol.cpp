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

    ll n;
    cin >> n;
    ll a[n + 11] = {0};

    rep(i , n) cin >> a[i + 1];

    ll ans = 0;

    // ll sum = 0;
    // rep(i , n) sum += a[i + 1];
    // ll ans2 = 0;
    // FOR(i  , 1 , n){
    //     ans2 += (a[i]&sum)*(a[i]|sum);
    // }

    // cout << ans2 << " ";

    FOR(i , 1, n){
        FOR(j , 1 , n){
            cout << i << " and " <<j << " = " << (a[i]&a[j]) << " , " << i <<" or "<< j << " = " << (a[i] | a[j]) << "\n"; 
        }
    }

    cout << "OR - AND\n";
    FOR(i ,1 ,n){
        ll x1 = 0 , x2 = 0;
        FOR(j , 1 , n){
            x1 += (a[i]|a[j]);

            x2 += (a[i]&a[j]);
        }

        cout << i << ": " << "OR = " << x1 << " , AND = " << x2 <<"\n";
        cout << "PRODUCT = " << x1*x2 <<"\n\n"; 
    }

    FOR(i ,1 , n){
        FOR(j ,1 , n){
            FOR(k , 1 , n){
                ans += (a[i]&a[j]) * (a[j] | a[k]);
            }
        }
    }

    cout << ans << "\n";
    // ll xx = 4|(6) , xy =  (4|1) + (4|2) + (4|3) ;
    // ll yy =  4&(1 + 2 + 3) , yx =  (4&1) + (4&2) + (4&3) ;
    // ll zz = (2&3)*4 , zy = (2*4)&3 , zx = (2)&(4*3) ;
    // cout << xx <<" " << xy << "\n";
    // cout << yy <<" " << yx <<"\n";
    // cout << zz << " " << zy << " " << zx << "\n";
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

