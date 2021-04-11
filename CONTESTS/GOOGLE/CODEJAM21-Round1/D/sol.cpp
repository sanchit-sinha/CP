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

ll count(vll &a , ll index1 , ll index2){
    ll x = a[index1];
    ll y = a[index2];

    string sx = to_string((ll)(x));
    string sy = to_string((ll)(y));

    ll ans = 0; 
    if(x < y) return 0;
    else{
        if(y == x){
            // add 0 to y
            sy = sy + '0';
            a[index2] = stoll(sy);
            y = a[index2];  
            
            return 1;
        }
        else{
            // x > y
            //change y ... 
            ll z = (ll)(x) + 1ll;
            string gr = to_string((ll)(z));

            // can y be == x + 1
            ll len = sz(sy);
            ll index = -1;
            rep(i , len){
                if(sy[i] != gr[i]){
                    index = i;
                    break;
                }
            }

            if(index == -1){
                // no change within sy
                sy = gr;
                a[index2] = z;
                return (sz(sy) - len);
            }
            else{
                while(sz(sy) != sz(sx)) sy.pb('0');

                a[index2] = stoll(sy);
                y = a[index2];
                if(y > x){
                    return (sz(sy) - len);
                }
                else{
                    sy.pb('0');
                    a[index2] = stoll(sy);
                    y = a[index2];
                    return (sz(sy) - len);
                }
            }

        }
    }


}
void solve(){
    ll n;
    cin >> n;

    vll a(n , 0);
    rep(i , n) cin >> a[i];

    if(n == 2){
        cout << count(a , 0 , 1) << "\n";
        return ;
    }
    if(n == 3){
        ll ans = 0;
        FOR(i , 1 , n - 1) ans += count(a , i - 1 , i);
        cout << ans << "\n";
        // rep(i , n) cout << a[i] << "\n";
        return;
    }

    ll ans = 0;
    FOR(i , 1 , n - 1){
        ans += count(a , i - 1 , i);
    }


    cout << ans << "\n";


    // rep(i , n) cout << a[i] << "\n";
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
        