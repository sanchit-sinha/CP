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
    string s[n];

    rep(i , n) cin >> s[i];

    ll x1 = -1 , y1 = -1, x2 = -1 , y2= -1;
    bool got = 0;

    rep(i , n){
        rep(j , n){
            if(s[i][j] == '*'){
                if(got == 0){
                    x1 = i , y1 = j;
                    got = 1;
                }
                else{
                    x2 = i , y2 = j;
                }
            }
        }
    }

    if(y1 == y2){
        if(y1 - 1 >= 0){
            s[x1][y1 - 1] = '*';
            s[x2][y1 - 1] = '*';
        }
        else if(y1 + 1 < n){
            s[x1][y1 + 1] = '*';
            s[x2][y1 + 1] = '*';
        }
    }
    else if(x1 == x2){
        if(x1 - 1 >= 0){
            s[x1 - 1][y1] = '*';
            s[x2 - 1][y2] = '*';
        }
        else if(x1 + 1 < n){
            s[x1 + 1][y1] = '*';
            s[x2 + 1][y2] = '*';
        }
    }
    else{
        s[x1][y2] = '*';
        s[x2][y1] = '*';
    }

    rep(i , n) cout << s[i] << "\n";

}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        factorial();
    #endif
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
