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
    ll n , m;
    cin >> n>> m;
    ll a[n];
    ll b[m];
    rep(i , n) cin >> a[i];
    rep(j , m) cin >> b[j];

    vll ele; 
    rep(j , m){
        ele.pb(a[b[j] - 1]);
    }

    vll mn;
    FOR(i , 1, m - 1){
        ll l =  b[i - 1] - 1;
        ll r = b[i] - 1;
        ll mnn = LLONG_MAX;
        FOR(j , l , r) mnn = min(mnn , a[j]);

        mn.pb(mnn);
    }

    ll ans = accumulate(ele.begin() , ele.end() , 0ll);

    vll dp(n , 0);
    ll len = mn.size();



    vpll v;
    FORR(i , len - 1 , 0){
        if(i == len - 1) dp[i] = mn[i] , v.pb(mp(mn[i] , i));
        else{
            if(mn[i] >= mn[i + 1]){
                dp[i] = mn[i] + dp[i + 1];
                v.pb(mp(mn[i] , i));
            }
            else{
                ll movement = 0;
                ll index = -1;

                while(v.size() && v.back().f >= mn[i]){
                    movement++;
                    v.pop_back();
                }

                if(v.size()) index = v.back().s;

                v.pb(mp(mn[i] , i));

                if(index != -1) dp[i] = mn[i]*(index - i) + dp[index];
                else dp[i] = mn[i] * (len - i);
            }
        }   
    }

    // rep(i , len + 1) cout << ele[i] << " ";
    // cout << "\n";   
    // rep(i , len) cout << mn[i] <<" ";
    // cout << "\n";
    // cout <<" ---------DP------------\n";
    // FOR(i , 0 , len - 1) cout << dp[i] << " ";
    // cout << "\n";

    FOR(i , 0 , len - 1) ans += dp[i];

    cout << ans << "\n";
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

