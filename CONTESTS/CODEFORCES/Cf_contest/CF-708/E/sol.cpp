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

const ll N = 1e7+1;


// finding shortest prime factor in O(nlog(n))
const ll mX = N;
ll spf[mX];
void sieve (){
    spf[1] = 1;
    for(ll i = 2 ; i < mX ; i++){
         if(spf[i] == 0){
            spf[i] = i;
            for (ll j = 1ll * i * i ; j < mX ; j += i){
                if(spf[j] == 0) spf[j] = i;
            }
        }
    }
} 
void insert_req(ll temp , set<ll> &req){
    ll p = 1;
    while(temp != 1){
        ll div = spf[temp];
        ll ct = 0;
        while(temp%div == 0){
            temp /= div;
            ct++;
        }
        if(ct&1) p*=div;
    }
    req.insert(p);
}

void print(set<ll> s){
    cout << "-----\n";
    trav(it , s) cout << *it << " ";
    cout << "\n";
    cout << "------\n";
}
void solve(){
    ll n , k;
    cin >> n >> k;

    ll a[n];
    rep(i , n) cin >> a[i];
    ll ans = 1;
    set<ll> req , pres;

    insert_req(a[0] , req);
    FOR(i , 1 , n - 1){
        insert_req(a[i] , pres);
        auto it = req.find(*pres.begin());
        if(it != req.end()){
            // will form perfect sq
            ans++;
            if(sz(req)) req.clear();
            req.insert(*pres.begin());
        }
        else{
            req.insert(*pres.begin());
        }
        pres.clear();
    }

    cout << ans << "\n";
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    sieve();
    ll NTC=1;
    cin>>NTC;
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

