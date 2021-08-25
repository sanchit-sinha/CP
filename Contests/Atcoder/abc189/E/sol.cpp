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

vector<vll> matrixmul(vector<vll> v1 , vector<vll> v2){
    ll n = v1.size();

    vector<vll > a;

    for(ll i = 0 ; i <  n ; i++){
        vll x ;
        for(ll j = 0 ; j < n; j++){
            ll val = 0;
            for(ll k = 0 ; k < n; k++){
                val += v1[i][k] * v2[k][j];
            }
            x.pb(val);
        }
        a.pb(x);
    }   

    return a; 
}
void print(vector<vll> v){
    ll n = v.size();
    ll m = v.size();

    rep(i , n){
        rep(j , m) cout << v[i][j] <<" ";
        cout <<" \n";
    }
    cout <<"\n";
}

void solve(){
    ll n;
    cin >> n;
    ll x[n] , y[n];
    rep(i , n) cin >> x[i] >> y[i];

    ll m;
    cin >> m;
    vector<vll> v;
    vll a;
    
    a.pb(1);a.pb(0);a.pb(0);
    v.pb(a);

    a.clear();

    a.pb(0);a.pb(1);a.pb(0);
    v.pb(a);

    a.clear();

    a.pb(0);a.pb(0);a.pb(1);
    v.pb(a);


    vector<vector<vll>> pref;
    pref.pb(v);


    rep(i , m){
        ll x;
        cin >> x;

        vector<vll> transform ;
        if(x == 1){
            vll a,b,c;
            a.pb(0);  a.pb(1); a.pb(0); transform.pb(a);
            b.pb(-1); b.pb(0); b.pb(0); transform.pb(b);
            c.pb(0);  c.pb(0); c.pb(1); transform.pb(c);

        }
        else if(x == 2){
            vll a,b,c;
            a.pb(0);  a.pb(-1); a.pb(0); transform.pb(a);
            b.pb(1);  b.pb(0); b.pb(0);  transform.pb(b);
            c.pb(0);  c.pb(0); c.pb(1); transform.pb(c);

        }
        else if(x == 3){
            ll p;
            cin >> p;

            vll a,b,c;
            a.pb(-1);  a.pb(0); a.pb(2*p); transform.pb(a);
            b.pb(0);  b.pb(1); b.pb(0);  transform.pb(b);
            c.pb(0);  c.pb(0); c.pb(1); transform.pb(c);
        }
        else if(x == 4){
            ll p;
            cin >> p;

            vll a,b,c;
            a.pb(1);  a.pb(0); a.pb(0); transform.pb(a);
            b.pb(0);  b.pb(-1); b.pb(2*p);  transform.pb(b);
            c.pb(0);  c.pb(0); c.pb(1); transform.pb(c);
        }

        v = matrixmul(transform , v);
        pref.pb(v);

        // cout <<"-------------------------\n";
        // print(transform);
        // cout <<"*****************\n";
        // print(v);
        // cout <<"-------------------------\n";
    }


    ll q;
    cin >> q;
    while(q--){
        ll index1 , index2 ;
        cin >> index2 >> index1;
        index1--;

        ll xx = x[index1] , yy = y[index1];
        vector<vll> v = pref[index2];

        // cout << xx <<" : " << yy <<"\n";
        // print(v);

        ll xf , yf;
        xf = v[0][0]*xx + v[0][1]*yy + v[0][2];
        yf = v[1][0]*xx + v[1][1]*yy + v[1][2];

        cout << xf <<" " << yf << "\n";
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
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

