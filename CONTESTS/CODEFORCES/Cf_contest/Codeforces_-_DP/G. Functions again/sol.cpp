/**
 *    Author:  Sanchit Sinha
 *    Created: 02.11.2020 16:28:23       
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
ll n,a[N],aabs[N],dp[N][2];
// dp[i][0] - ans for even lengthed size subarray ending at i
// dp[i][1] - ans for odd  lengthed size subarray ending at i
void solve(){
    cin>>n;
    rep(i,n) cin>>a[i];
    rep(i,n-1) aabs[i]=abs(a[i]-a[i+1]);
    // rep(i,n-1) cout<<aabs[i]<<" ";
    // cout<<"\n";
    rep(i,n-1){
        if(i==0){
            dp[i][0]=0;
            dp[i][1]=aabs[i];
        }
        else{
            // even lengthed 
            dp[i][0]=max(0ll,dp[i-1][1]-aabs[i]);
            // odd lengthed
            dp[i][1]=max(aabs[i],dp[i-1][0]+aabs[i]);
        }
    }
    ll ans=0;
    // rep(i,n-1){
    //     cout<<i<<" : ";
    //     cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    // }
    rep(i,n-1){
        ans=max(ans,dp[i][0]);
        ans=max(ans,dp[i][1]);
    }
    cout<<ans<<"\n";
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
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
