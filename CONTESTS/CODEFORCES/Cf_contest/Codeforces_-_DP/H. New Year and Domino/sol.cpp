/**
 *    Author:  Sanchit Sinha
 *    Created: 02.11.2020 17:25:54       
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

const ll N = 511;
ll n,m;
string s[N];
ll dphorizontal[N][N],dpvertical[N][N];
void solve(){
    cin>>n>>m;
    rep(i,n) cin>>s[i];

    // horizontal
    rep(i,n){
        rep(j,m){
            if(i-1>=0) dphorizontal[i][j]+=dphorizontal[i-1][j];
            if(j-1>=0) dphorizontal[i][j]+=dphorizontal[i][j-1];
            if(i-1>=0 && j-1>=0) dphorizontal[i][j]-=dphorizontal[i-1][j-1];
            if(j-1>=0 && s[i][j-1]=='.' && s[i][j]=='.') dphorizontal[i][j]++;
        }
    }

    // vertical
    rep(i,n){
        rep(j,m){
            if(i-1>=0) dpvertical[i][j]+=dpvertical[i-1][j];
            if(j-1>=0) dpvertical[i][j]+=dpvertical[i][j-1];
            if(i-1>=0 && j-1>=0) dpvertical[i][j]-=dpvertical[i-1][j-1];
            if(i-1>=0 && s[i-1][j]=='.' && s[i][j]=='.') dpvertical[i][j]++;
        }
    }

    cout << dphorizontal[3][4] <<" " << dpvertical[3][4]<<"\n";
    cout << dphorizontal[0][1] <<" " << dpvertical[0][1]<<"\n";

    ll q;
    cin>>q;
    while(q--){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--;y1--;
        x2--,y2--;

        ll ans=0;
        ans+=dphorizontal[x2][y2];
        if(x1-1>=0) ans-=dphorizontal[x1-1][y2];
        if(y1-1>=0) ans-=dphorizontal[x2][y1-1];
        if(x1-1>=0 && y1-1>=0) ans+=dphorizontal[x1-1][y1-1];


        ans+=dpvertical[x2][y2];
        if(x1-1>=0) ans-=dpvertical[x1-1][y2];
        if(y1-1>=0) ans-=dpvertical[x2][y1-1];
        if(x1-1>=0 && y1-1>=0) ans+=dpvertical[x1-1][y1-1];

        cout<<ans<<"\n";
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
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
