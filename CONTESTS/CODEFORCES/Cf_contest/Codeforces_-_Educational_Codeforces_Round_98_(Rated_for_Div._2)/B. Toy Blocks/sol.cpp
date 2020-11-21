/**
 *    Created: 19.11.2020 20:42:29       
**/
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
ll power(ll x,ll y);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5 + 11;
ll n;
ll a[N];
ll calc(ll x){
    ll ans=0;
    rep(i,n){
        ans+=max(0,x-a[i]);
    }
    return ans;
}
void solve(){
    //clear
    rep(i,n) a[i]=0;

    cin>>n;
    rep(i,n) cin>>a[i];
    sort(a,a+n);
    ll mx1=a[n-1];
    ll mx2=a[n-2];
    ll ans=0;
    ll val1 = calc(mx1);
    ll val2 = calc(mx2);
    // rep(i,n) cout<<a[i]<<" ";
    // cout<<"\n";
    // cout<<val1<<" " <<val2<<"\n";
    rep(i,n){
        if(i<n-1){
            ll z=val1;
            z-=mx1;
            z+=a[i];
            if(a[i]<=z) ans=max(ans,z-a[i]);
            else{
                ll y=a[i];
                y-=z;
                y%=(n-1);
                if(y)ans=max(ans,(n-1-y));
            }   
        }
        else{
            if(a[i]<=val2) ans=max(ans,val2-a[i]);
            else{
                ll y=a[i];
                y-=val2;
                y%=(n-1);
                if(y) ans=max(ans,n-1-y);
            }
        }
        // cout << i <<" : " << ans<<"\n";
    }
    cout<<ans<<"\n";
    // cout<<"------------\n";
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
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
