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


void solve(){
    ll n;
    cin >> n;
    ll a[n];
    rep(i , n) cin >> a[i];

    vpll v;
    rep(i , n){
        v.pb(mp(a[i] , i));
    }
    sort(all(v));


    ll pfx[n + 11] = {0};
    rep(i , n){
        if(i == 0) pfx[i] = v[i].f;
        else pfx[i] = pfx[i - 1] + v[i].f;
    }

    set<ll> ans;
    ans.insert((v[ n - 1].s));
    FORR(i , n - 2 , 0){
        if(pfx[i] >= v[i + 1].f) ans.insert(v[i].s);
        else break;
    }

    // FOR(i , 0, n - 1){
    //     ll ele = a[i];
    //     if(i == 0) continue;
    //     else{
    //         ll sum = pfx[i];
    //         ll l = i + 1;
    //         ll r = n - 1;
    //         ll pos = -1;
    //         ll mid =0 ;
    //         while(l <= r){
    //             mid = l + (r - l)/2;
    //             ll value = pfx[mid - 1];
    //             if(value >= mid){
    //                 l = mid + 1;
    //                 pos = mid;
    //             }
    //             else r = mid - 1;
    //         }

    //         if(pos == n - 1) ans.insert(i);
    //     }
    // }

    cout << sz(ans) << "\n";
    trav(it, ans) cout << *it + 1<< " ";
    cout << "\n";
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
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

