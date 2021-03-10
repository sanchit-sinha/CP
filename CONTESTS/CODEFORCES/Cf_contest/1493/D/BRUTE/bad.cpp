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

const ll N = 2e5+11;
ll n , q;
ll a[N];
map<ll , ll> m[N];
multiset<ll> exponents[N];

#define SIEVE
// finding shortest prime factor in O(nlog(n))
const ll mX = N;
ll spf[mX];
void sieve (){
    spf[1] = 1;
    for(ll i = 2 ; i < mX ; i++){
         if(spf[i] == 0){
            spf[i] = i;
            for (ll j = 1ll * i * i ; j < mX ; j += i){
                if(spf[j] == 0) spf[j] = i;
            }
        }
    }
}
void add(ll index , ll x){
    ll temp = x;
    while(temp > 1){
        ll div = spf[temp];

        ll ct = 0;
        while(temp%div == 0){
            temp /= div;
            ct++;
        }

        m[index][div] = ct;
        exponents[div].insert(ct);
    }    
}
ll update(ll index , ll x , ll val){
    ll temp = x;
    while(temp > 1){
        ll div = spf[temp];
        ll ct = 0;
        while(temp%div == 0){
            temp /= div;
            ct++;
        }

        ll prevmn = 0;
        if(sz(exponents[div]) == n) prevmn = *(exponents[div]).begin();

        ll prev = m[index][div];
        if(prev) exponents[div].erase(exponents[div].find(prev));

        m[index][div] += ct;
        exponents[div].insert(m[index][div]);

        ll newmn = 0;
        if(sz(exponents[div]) == n) newmn = *(exponents[div]).begin();
    

        val *= (powermod(div, (newmn - prevmn) , mod));
        val %= mod;
    }

    return val;
}
void solve(){
    cin >> n >> q;
    rep(i , n) cin >> a[i];

    rep(i , n){
        ll x = a[i];
        add(i , x);
    }

    ll ans = 0;
    rep(i , n) ans = gcd(ans , a[i]);

    // cout << ans << "\n";
    // rep(i , n){
    //     ll x = a[i];
    //     cout << x << "-\n";
    //     trav(it , m[i]) cout << it->f << " " << it->s << "\n";
    //     cout << "\n";
    // }
    // return ;

    while(q--){
        ll index , val;
        cin >> index >> val ;
        index--;

        ans = update(index , val , ans)%mod;
        cout << ans << "\n";
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
