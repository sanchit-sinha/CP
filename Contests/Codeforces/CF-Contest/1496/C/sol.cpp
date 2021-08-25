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

    ld ans = 0.0;

    ll x[n] ;
    ll y[n];

    ll index1 = 0;
    ll index2 = 0;

    rep(i , n + n){
        ll xx , yy;
        cin >> xx >> yy;
        xx = abs(xx);
        yy = abs(yy);

        if(xx == 0) y[index2++] = yy;
        else x[index1++] = xx;
    } 

    sort(x , x + n);
    sort(y , y + n);


    //M1
    multiset<ll> xs , ys;
    rep(i , n){
        ll xx = x[i];
        ll yy = y[i];

        xx = abs(xx);
        yy = abs(yy);

     ys.insert(yy);
     xs.insert(xx);
    }

    // trav(it , xs) cout << *it << " ";
    // cout << "\n";
    // trav(it , ys) cout << *it << " ";
    // cout << "\n";

    multiset<ll> mx;
    multiset<ll> my;

    trav(it , xs){
        ll xx = *it;
        auto it1 = ys.find(xx);
        if(it1 == ys.end()){
            mx.insert(xx);
        }
        else{
            ans += sqrt(xx*xx + xx*xx);
            ys.erase(it1);
        }
    }

    // cout << ans << "\n\n";

    trav(it , ys) my.insert(*it);

    // trav(it , mx) cout << *it << " ";
    // cout << "\n";
    // trav(it , my) cout << *it << " ";
    // cout << "\n";


    while(!mx.empty() && !my.empty()){
        ll elex = *mx.begin();
        ll eley = *my.rbegin();

        ans += sqrt(elex*elex + eley*eley);

        mx.erase(mx.find(elex));
        my.erase(my.find(eley));
    }

    // cout << ans << "\n";

    ld ans1 = 0.0;
    ld ans2 = 0.0;

    rep(i , n){
        ll xx = x[i];
        ll yy = y[n - 1 - i];
        ans1 += sqrt(xx*xx + yy*yy);
        
        ll yy1 = y[i];
        ans2 += sqrt(xx*xx + yy1*yy1);
    }

    ld val = min(ans , ans1);
    val = min(val , ans2);

    cout << val << "\n";
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

