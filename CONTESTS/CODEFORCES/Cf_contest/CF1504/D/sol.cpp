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

pair<ll , pll> fill(vector<vll> &ans , ll col , ll rem){
    ll n = sz(ans);
    rep(i , n){
        rep(j , n){
            if((i+j)%2 == rem){
                if(ans[i][j] == 0){
                    ans[i][j] = col;
                    pair<ll , pll > p = mp(col , mp(i , j));
                    return p;
                }
            }
        }
    }
    pair<ll , pll > p = mp(-1 , mp(-1 , -1));
    return p;
}
void solve(){
    ll n;
    cin >> n;

    vector< vll > ans(n , vll (n , 0));
    /* 1 -> odd 
       2 -> even
       3 -> both
                        */
    rep(i , n*n){
        ll ntcol;
        cin >> ntcol;

        if(ntcol != 1){
            // use 1 at odd place
            pair<ll , pll> p = fill(ans , 1 , 1); 
            ll col = p.f;
            ll x = p.s.f;
            ll y = p.s.s;

            if(x == -1){
                // no odd place
                if(ntcol == 3){
                    p = fill(ans , 2 , 0);
                }
                else{
                    p = fill(ans , 3 , 0);
                }
            }
            
            cout << p.f << " " << p.s.f + 1<< " " << p.s.s + 1<< "\n";
            cout.flush();            
        }
        else if(ntcol != 2){
            //2 at even place
            pair<ll , pll> p = fill(ans , 2 , 0); 
            ll col = p.f;
            ll x = p.s.f;
            ll y = p.s.s;

            if(x == -1){
                //no even place
                if(ntcol == 1){
                    p = fill(ans , 3 , 1);
                }
                else{
                    p = fill(ans , 1 , 1);
                }
            }

            cout << p.f << " " << p.s.f + 1<< " " << p.s.s + 1<< "\n";
            cout.flush();
        }
    } 
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
        