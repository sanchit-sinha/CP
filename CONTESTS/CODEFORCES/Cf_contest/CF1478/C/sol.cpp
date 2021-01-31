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
    
    ll m = n;

    n += n;

    ll a[n];
    rep(i , n) cin >> a[i];

    sort(a , a + n);
    // rep(i , n) cout << a[i] << " " ;
    // cout << "\n";

    ll sum = 0;
    vll v;
    ll rem = n/2;

    vll b;
    vll c;
    for(int i = 1 ; i < n ;i+=2 ) c.pb(a[i]);
    for(int i = 0 ; i < n; i+=2) b.pb(a[i]);
    sort(all(b));
    reverse(all(b));


    sort(all(c));
    reverse(all(c));

    if(b != c){
        cout << "NO\n";
        return ;
    }
    // rep(i , n/2) cout << b[i] <<" ";

    rep(i , n/2){
        ll x = b[i];
        ll num = x - 2*sum;
        ll div = 2*rem;
        if(num>0 && num%div == 0){
            num /= div;
            // cout << num << " " ; 
                
            v.pb(num);

            sum += num;
            rem--;

            // if(num == 0){
            //     cout << "NO\n";
            //     return ;
            // }
        }
        else{
            cout << "NO\n";
            return ;
        }
    }

    set<ll> s;
    rep(i , n/2){
        s.insert(v[i]);
        s.insert(-v[i]);
    }

    if(sz(s) != n) cout << "NO\n";
    else cout <<"YES\n";

    // rep(i , n/2) cout << v[i] <<" ";
    // cout << "\n";
    // cout << "YES\n";


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

