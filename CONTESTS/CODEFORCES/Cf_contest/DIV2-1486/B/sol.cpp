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
    ll x[n] , y[n];
    rep(i , n){
        cin >> x[i] >> y[i];
    }

    sort(x , x + n);
    sort(y , y + n);

    if(n&1){
        cout << 1 << "\n";
    }
    else{
        ll x1 = x[n/2];
        ll x2 = x[n/2 - 1];

        ll y1 = y[n/2];
        ll y2 = y[n/2 - 1];

        ll mxx = max(x1 , x2);
        ll mnx = min(x1 , x2);

        ll mxy = max(y1 , y2);
        ll mny = min(y1 , y2);

        cout << (mxx - mnx + 1)*(mxy - mny + 1) << "\n";

        // set<pll> s;

        // s.insert(mp(x1 , y1));
        // s.insert(mp(x1 , y2));
        // s.insert(mp(x2 , y1));
        // s.insert(mp(x2 , y2));

        // trav(it , s){
        //     cout << it->f << " " << it->s << "\n";
        // }
   
        // cout << sz(s) << "\n";
    }

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

