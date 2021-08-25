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
ll value(vll a , vll &b){
    ll n = sz(a);
    ll ans = 0;
    rep(i , n - 1){
        FOR(j , i , n - 1){
            if(a[j] == b[i]){
                ll ct = j - i + 1;
                reverse(a.begin() + i , a.begin() + j + 1);
                ans += ct;
            }
        }
    }
    return ans;
}
void solve(){
    ll n;
    cin >> n;>

    ll cost;
    cin >> cost;

    vll a;
    vll ans(n + 1 , -1);
    rep(i , n + 21){
        a.pb(i);
    }

    ll rem = cost;
    FOR(i , 1 , n - 1){
        ll other = n - (i - 1) - 2;
        // cout << i << " : " << " other " << other << " ";

        if((rem - other < 0)){
            cout << "IMPOSSIBLE\n";
            return;
        }
        ll ahead = min(n - i + 1 , rem - other);

        if((i + ahead) > (n + 1)){
            cout << "IMPOSSIBLE\n";
            return;
        }
        reverse(a.begin() + i , a.begin() + i + ahead);
        // rep(j , n) cout << a[j + 1] << " ";
        // cout << "\n";
        ll index = a[i];
        ans[index] = i;

        rem -= (ahead);

        // cout << " index " << index << " " << " pos " << pos << " " << " done " << done << " " << " rem " << rem << "\n";
    }

    ll ct = 0;
    FOR(i ,1 , n) {
        if(ans[i] == -1){
            ans[i] = n;
            ct++;
        }
    }

    if(ct != 1){
        cout << "IMPOSSIBLE\n";
        return;
    }

    vll check , b;
    rep(i , n) check.pb(ans[i + 1]) , b.pb(i + 1);

    ll costt = value(check, b);
    if(costt != cost){
        cout << "IMPOSSIBLE\n";
        return;
    }
    FOR(i ,1 , n) cout << ans[i] << " ";
    cout << "\n";
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
        cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
