/**
 *    Author:  Sanchit Sinha
 *    Created: 12.11.2020 01:07:32       
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
map<ll,ll> m;
string s;
ll n;
bool check(ll x){
    map<ll,ll> v;
    while(x){
        v[(x%10)]++;
        x/=10;
    }
    trav(it,v){
        ll xx=it->f;
        ll cnt=it->s;
        auto it1=m.find(xx);
        if(it1 == m.end()) return false;
        else{
            if(cnt > m[xx]) return false;
        }
    }
    return true;
}
void solve(){
    cin>>s;
    n=sz(s);
    rep(i,n){
        ll x=s[i]-'0';
        m[x]++;
    }
    if(n<=2){
        ll num=0;
        rep(i,n) num=num*10 + s[i]-'0';
        if(num%8==0){
            cout<<"Yes\n";
            return;
        }
        reverse(all(s));
        num=0;
        rep(i,n) num=num*10+s[i]-'0';
        if(num%8==0){
            cout<<"Yes\n";
            return;
        }
        cout<<"No\n";
        return;
    }
    FOR(i,13,200){
        ll x=8*i;
        if(check(x)){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
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
