#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define mp make_pair
#define mt make_tuple
#define get(x,c) get<x>(c)
#define trav(a,x) for(auto a=x.begin();a!=x.end();a++)
#define rep(i,n) for(int i=0;i<n;i++)
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
ll power(ll x,ll y);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5 + 11;
ll n,m,x[N],y[N],sfx[N];
vpll a,b;
void solve(){
    a.clear();b.clear();
    rep(i,n) sfx[i]=x[i]=y[i]=0;

    cin>>m>>n;
    
    rep(i,n){
        cin>>x[i]>>y[i];
        a.pb({x[i],i});
        b.pb({y[i],i});
    }

    sort(all(a));
    sort(all(b));

    for(ll i=n-1;i>=0;--i){
        if(i==n-1) sfx[i]=a[n-1].f;
        else sfx[i]=sfx[i+1]+a[i].f;
    }

    ll ans=-inf;
    for(ll i=0;i<n;i++){
        ll bi=b[i].f;
        ll l=0,r=n-1,mid=0,choosen=n,val=0;
        while(l<=r){
            mid=(l+(r-l)/2);
            if(a[mid].f>=bi) r=mid-1,choosen=mid;
            else l=mid+1;
        }
        ll ai=x[b[i].s];
        bool taken=0;
        if(choosen!=n && ai>=a[choosen].f) taken=1;
        ll num_choosen=n-choosen;
        if(m<=num_choosen) val=sfx[n-m];
        else{
            val=sfx[choosen];
            if(taken) val+=(m-num_choosen)*bi;
            else{
                val+=ai+(m-num_choosen-1)*bi;
            }
        }
        ans=max(ans,val);
    }
    cout<<ans<<endl;
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
        cout<<"\n";
    }
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
