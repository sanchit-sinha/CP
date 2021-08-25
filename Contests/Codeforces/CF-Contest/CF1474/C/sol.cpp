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

    n += n;
    ll arr[n];
    rep(i , n) cin >> arr[i];
    sort(arr ,arr  + n);

    bool ok = 0;
    vpll ans ;

    ll a = arr[n - 1];
    
    FORR(i , n - 2 , 0){
        ll b = arr[i];
        multiset<ll> s;
        rep(j , n){
            s.insert(arr[j]);
        }
        s.erase(s.find(a));
        s.erase(s.find(b));

        vpll ans;
        ll sum = max(a , b);
        ans.pb(mp(a , b));
        while(!s.empty()){
            ll mx = *s.rbegin();
            s.erase(s.find(mx));

            auto it = s.find(sum - mx);
            if(it != s.end()){
                sum = mx;
                ll ele = *it;
                s.erase(it);

                ans.pb(mp(mx , ele));
            }
            else break;

        }

        if(sz(s) == 0){
            ok = 1;
            cout << "YES\n";
            cout << a + b << "\n";
            rep(k , sz(ans)) cout << ans[k].f <<" " << ans[k].s << "\n";
            return ;
        }
    }

    cout << "NO\n";
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

