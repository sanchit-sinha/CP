#include "bits/stdc++.h"
using namespace std;
#define f                   first
#define s                   second
#define pb                  push_back
#define ll                  long long
#define ld                  long double
#define lb                  lower_bound
#define ub                  upper_bound
#define mp                  make_pair
#define mt                  make_tuple
#define pll                 pair<ll , ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (int)(c.size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(int i = 0 ; i < n ; i++)
#define FOR(i, a, b)        for(int i = a ; i <= b; i++)
#define FORR(i, b, a)       for(int i = b ; i >= a; i--)

inline ll gcd(ll a,ll b) {if(b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a,ll b) {return((a > b) ? a : b);}
inline ll min(ll a,ll b) {return((a > b) ? b : a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5+11;


void solve(){
    ll n , k;
    cin >> n >> k;
    set<ll> s;
    rep(i , n){
        ll x;
        cin >> x;
        s.insert(x);
    }

    vll v;
    trav(it , s) v.pb(*it);

    if(k <= 30){
        ll mx = 0ll;
        FOR(i , 1 , k){
            FOR(j , 1 , k){
                ll first = i;
                ll second = j;

                ll ct = 0;
                FOR(l , 1 , k){
                    ll dis1 = abs(first - l);
                    ll dis2 = abs(second - l);

                    ll mn = inf;
                    FOR(t , 0 , sz(v) - 1){
                        ll ele = v[t];
                        ll distance = abs(ele - l);

                        mn = min(mn , distance);
                    }

                    if(dis1 < mn || dis2 < mn) ct++;
                }
                mx = max(mx , ct);
            }
        }

        ld ans = 1.0 * mx;
        ans /= k;
        cout << ans << "\n";
        return;
    }

    vll ans;
    ll first = *s.begin();
    ll last = *s.rbegin();

    ans.pb(first - 1);
    ans.pb(k - last);

    vll both;

    FOR(i , 0 , sz(v) - 2){
        ll pres = v[i];
        ll next = v[i + 1];

        ll dis = next - pres - 1;
        if(dis){
            ll val = (dis + 1)/2;
            ans.pb(val);
            both.pb(dis);
        }
    }

    sort(all(ans));
    reverse(all(ans));

    sort(all(both));
    reverse(all(both));

    // rep(i , sz(ans)) cout << ans[i] << " ";
    // cout << "\n";

    ll mx1 = (ans[0] + ans[1]);
    ll mx2 = 0;
    if(sz(both)) mx2 = both[0];

    ll mx = max(mx1 , mx2);

    ll num = 1.0 * mx;

    ld res = (1.0 * num)/k;
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
   
    ll NTC=1;
    cin>>NTC;

    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        factorial();
    #endif 
    #ifdef PREPROCESS
        preprocess();
    #endif
    
    ll PTC=0;
    while((PTC++)<NTC){
        cout << "Case #" << PTC << ":" << ' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
