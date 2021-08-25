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
ll n;
string a,b;
void convert(ll l,ll r){
    ll n=sz(a);
    for(ll i=l;i<=r;i++){
        if(a[i]=='0') a[i]='1';
        else a[i]='0';
    }
    string x;
    for(ll i=l;i<=r;i++) x.pb(a[i]);
    reverse(all(x));
    for(ll i=r+1;i<n;i++) x.pb(a[i]);
    a=x;
}
void solve(){
    a.clear();
    b.clear();

    vll ans;
    cin>>n>>a>>b;
    for(ll i=n-1;i>=0;--i){
        if(b[i]!=a[i]){
            if(b[i]=='1'){
                if(a[0]=='0'){
                    convert(0,i);
                    ans.pb(i);
                }
                else{
                    a[0]='1';
                    ans.pb(0);
                    convert(0,i);
                    ans.pb(i);
                }
            }
            else{
                if(a[0]=='1'){
                    convert(0,i);
                    ans.pb(i);
                }
                else{
                    a[0]='1';
                    ans.pb(0);
                    convert(0,i);
                    ans.pb(i);
                }
            }
        }
        // cout << i<<" : " <<a << " " << b<<endl;
    }
    cout<<sz(ans)<<" ";
    rep(i,sz(ans)) cout<<ans[i]+1<<" ";
    nl;
    // cout<< " a " << a <<" "<< b<<endl;nl;
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
        // cout<<"\n";
    }
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
