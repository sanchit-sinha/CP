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

ll ask(ll l , ll r){
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    ll x;
    cin >> x;

    return x;
} 
void solve(){
    ll n;
    cin >> n;

    ll l = 1 , r = n , mid = 0 , ans = -1;

    if(l + 2 < r){
        ll index = ask(1 , n);
        while(l + 2 < r){
            mid = l + (r - l)/2;

            if(index <= mid){
                ll check = ask(l , mid);
                if(check == index){
                    r = mid ;
                    ans = mid;
                }
                else{
                    l = mid ;
                    // index = ask(l , r);
                    index = r;
                    if(index == -1) break;
                }
            }
            else{
                ll check = ask(mid , r);
                if(check == index){
                    ans = mid;
                    l = mid;
                }
                else{
                    r = mid ;
                    // index = ask(l , r);
                    index = l;
                    if(index == -1) break;
                }
            }
        }
    }
    
    if(l + 2 >= r){
        if(l == r){
            ans = l;
        }
        else if(l + 1 == r){
            ll index = ask(l , r);
            if(index == l) ans = r;
            else ans = l;
        }
        else{
            ll index1 = ask(l , l + 1);
            ll index2 = ask(l + 1 , r);

            ll mx1 = 0 , mx2 = 0;
            if(index1 == l) mx1 = l + 1;
            else mx1 = l;

            if(index2 == r) mx2 = l + 1;
            else mx2 = r;
        
            if(mx1 == l + 1 && mx2 == l + 1) ans = l + 1;
            else{
                ll index = ask(mx1 , mx2);
                if(index == mx1) ans = mx2;
                else ans = mx1;
            }
        }
    }
    cout << "! " << ans << "\n";
    cout.flush();
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

