/**
 *    Author:  Sanchit Sinha
 *    Created: 31.10.2020 19:53:05       
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

const ll N = 1e5+11;
ll n,a[N],pfx[N],sfx[N];
// finding shortest prime factor//SPF -- Nlog(n)
const ll mX = 1e5+11;
ll spf[mX];
void sieve (){
    spf[1]=1;
    for(ll i=2;i<mX;i++){
        if(spf[i]==0){
            spf[i]=i;
            for (ll j=1ll*i*i;j<mX;j+=i){
                if(spf[j]==0) spf[j]=i;
            }
        }
    }
}
void solve(){
    //clear
    rep(i,n) a[i]=0;

    cin>>n; 
    rep(i,n) cin>>a[i];

    set<ll> s;
    for(ll i=0;i<n;i++){
        ll x=a[i];
        while(x!=1){
            ll div=spf[x];
            s.insert(div);
            while(x%div==0) x/=div;
        }
        bool ok=1;
        for(ll j=i+1;j<n;j++){
            ll y=a[j];
            while(y!=1){
                ll div=spf[y];
                auto it=s.find(div);
                if(it!=s.end()){
                    ok=0;
                    break;
                }
                else while(y%div==0) y/=div;
            }
            if(!ok) break;
        }
        if(ok){
            cout<<i+1<<"\n";
            return ;
        }
    }
}
int main(){
    IOS;
    sieve();
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
