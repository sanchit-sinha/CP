/**
 *    Author:  Sanchit Sinha
 *    Created: 16.11.2020 18:47:33       
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

void solve(){
    ll n,m;
    cin>>n>>m;
    ll a[n][m];
    rep(i,n){
        rep(j,m) cin>>a[i][j];
    }
    // turn = 1 , even : turn =0 odd
    rep(i,n){
        if(i&1){
            rep(j,m){
                if(j%2 == 0){
                    if(a[i][j]%2 == 0) a[i][j]++;
                }
                else{
                    if(a[i][j]%2) a[i][j]++;
                }
            }
        }
        else{
            rep(j,m){
                if(j%2 == 0){
                    if(a[i][j]%2) a[i][j]++;
                }
                else{
                    if(a[i][j]%2 == 0) a[i][j]++;
                }
            }
        }
    }
    rep(i,n){
        rep(j,m) cout<<a[i][j]<<" ";
        cout<<"\n";
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
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
