/**
 *    Author:  Sanchit Sinha
 *    Created: 26.10.2020 09:58:13       
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

const ll N = 2e5+1;
ll n;
vll v[N],ans(N,-1);
ll x[N],y[N];
void solve(){
    cin>>n;
    rep(i,n-1){
        cin>>x[i]>>y[i];
        v[x[i]].pb(y[i]);
        v[y[i]].pb(x[i]);
    }
    if(n==2){
        cout<<"0\n";
        return ;
    }
    else if(n==3){
        cout<<"0\n1\n";
        return ;
    }
    set<pll> got;
    for(ll i=1;i<=n;i++){
        ll len=sz(v[i]);
        if(len>=3){
            rep(j,3){
                got.insert(mp(i,v[i][j]));
            }
            break;
        }
    }   
    set<ll> fill;
    rep(i,n-1) fill.insert(i);
    ll index=0;
    if(sz(got)==3){
        rep(i,n-1){
            auto it1=got.find(mp(x[i],y[i]));
            auto it2=got.find(mp(y[i],x[i]));
            if(it1 != got.end() || it2 != got.end()){
                ans[i]=index;
                fill.erase(fill.find(index));
                index++;
            }
        }
    }
    rep(i,n-1){
        if(ans[i]!=-1)cout<<ans[i]<<"\n";
        else{
            cout<<*fill.begin()<<"\n";
            fill.erase(fill.begin());
        }
    }
    cout<<"\n";
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
