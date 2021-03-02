#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define ll long long
#define ld long double
#define all(c) (c).begin() + 1,(c).end()
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

ll bits(ll x){
    if(x < 0) return -1;
    return __builtin_popcountll(x);
}
void solve(){
     ll a , b , k;
     cin >> a >> b >> k;

     vll v(a + b , 0);
     rep(i , sz(v)){
        if(i < b - 1) v[a + b - 1 - i] = 1;
     }
     v[0] = 1;


     do{
        ll x = 0ll ;
        rep(i , sz(v)){
            x += v[i]*(1ll<<(a+b-1-i));
        }     

        vll v2(a + b , 0);
        rep(i , sz(v2)){
            if(i < b - 1) v2[a + b - 1 - i] = 1;
        }

        v2[0] = 1;

        // cout << "TOP\n";
        // rep(i , a + b) cout << v[i];
        // cout << "\n";
        // rep(i , a + b) cout << v2[i];
        // cout << "\n";

        // cout << bits(x) << "\n";
        // return ;

        do{
            ll y = 0ll;
            rep(i , sz(v2)){
                y += v2[i]*(1ll<<(a+b-i-1));
            }
        //     cout << "TOPIN\n";
        // rep(i , a + b) cout << v2[i];
        // cout << "\n";
        // cout <<" " << x << " " << y << " " << x - y << "\n"; 

            if(bits(x-y) == k){
                ll temp = x - y;
                vll ans(a + b , 0);
                ll index = a + b - 1;
                while(temp){
                    ans[index--] = temp%2;
                    temp/=2;
                }


                rep(i , a + b) cout << v[i];
                cout << "\n";
                rep(i , a + b) cout << v2[i];
                cout << "\n";
                rep(i , a + b){
                    cout << ans[i];
                }
                cout << "\n\n";

            }
        }while(next_permutation(all(v2)));

     } while (next_permutation(all(v)));
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

