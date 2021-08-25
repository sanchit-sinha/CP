/**
 *    Author:  Sanchit Sinha
 *    Created: 26.10.2020 17:33:42       
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

const ll N = 2e5+11;
string s[N];
vll v[30];
ll n;
ll sz[N] , parent[N];
void make_set(ll node){
    parent[node] = node;
    sz[node] = 1;
}
ll find_set(ll a){
    if(a==parent[a]) return a;
    return parent[a]=find_set(parent[a]);
}
void union_set(ll a , ll b){
    ll p1=find_set(a);
    ll p2=find_set(b);
    if(p1!=p2){
        if(sz[p2]>sz[p1]) swap(p1,p2);
        parent[p2]=p1;
        sz[p1]+=sz[p2];
        sz[p2]=0;
    }
}
void solve(){
    cin>>n;
    rep(i,n) make_set(i);
    rep(i,n){
        cin>>s[i];
        ll len=sz(s[i]);
        rep(j,len){
            v[s[i][j]-'a'].pb(i);
        }
    }

    rep(i,26){
        ll len=sz(v[i]);
        if(len>1){
            rep(j,len-1){
                union_set(v[i][j],v[i][j+1]);
            }
        }
    }

    set<ll> ans;
    rep(i,n) ans.insert(find_set(i));
    cout<<sz(ans)<<"\n";
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
