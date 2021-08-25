#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
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
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5+11;

pll count(string &s){
    ll n = sz(s);
    ll zr = 0;
    rep(i , n) zr += (s[i] == '0');
    return mp(zr , n - zr);
}
string generate(string &s , string &t , char buffer , char add){
    ll n = sz(s);
    ll len = 3*(n/2);
 
    string ans(len , '?');
    ll add_at_ct[n + 2] = {0};
 
    ll ct = 0;
    rep(i , n){
        if(t[i] == buffer) ct++;
        else{
            ll cnt = 0;
            while(i < n && t[i] == add) i++ , cnt++;
            i--;
 
            add_at_ct[ct] = cnt;
        } 
    }
 
    ll index = 0;
    ct = 0;
    rep(j , add_at_ct[0]) ans[index++] = add;
    rep(i , n){
        ans[index++] = s[i];
        if(s[i] == buffer){
            ct++;
            rep(j , add_at_ct[ct]) ans[index++] = add;
        }
    }
 
    FOR(j , index , len - 1) ans[j] = buffer;
 
    return ans;
}
void solve(){
    ll n;
    cin >> n;

    ll m = 3;
    string s[m];
    rep(i , m) cin >> s[i];

    pll p[m];
    rep(i , m){
        p[i] = count(s[i]);
    }
    
    vll mxzr , mxone;
    rep(i , m){
        if(p[i].f >= n) mxzr.pb(i);
        if(p[i].s >= n) mxone.pb(i);
    }

    string ans;
    if(sz(mxzr) >= 2) {
        ll x = mxzr[0] , y = mxzr[1];
        if(p[x].f < p[y].f) swap(x , y);       
        ans = generate(s[x] , s[y] , '0' , '1');
    }
    else if(sz(mxone) >= 2){
        ll x = mxone[0] , y = mxone[1];
        if(p[x].s < p[y].s) swap(x , y);
        ans = generate(s[x] , s[y] , '1' , '0');
    }
    else assert(0);

    cout << ans << "\n";

}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    
    ll NTC=1;
    cin>>NTC;
    
    #ifdef PREPROCESS
        preprocess();
    #endif
    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        factorial();
    #endif 
    
    ll PTC=0;
    while((PTC++)<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
