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
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

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

void debug(map<ll,ll> &room){
    cout << "################\n";
    trav(it , room) cout << it->f << " : " << it->s << "\n";
    cout << "#################\n";
}
void solve(){
    ll n;
    cin >> n;

    vll x(n) , y(n) , people(n);
    rep(i , n) cin >> x[i] >> y[i];

    vector< pair<pll , ll >> v;
    rep(i , n) v.pb({{x[i] , y[i]} , i});
    sort(all(v));

    ll room_number = 1;
    multiset<pll> s;

    // rep(i , n) cout << v[i].s << " : " << v[i].f.f << " " << v[i].f.s << "\n"; 

    rep(i , sz(v)){
        ll l = v[i].f.f;
        ll r = v[i].f.s;
        ll index = v[i].s;

        bool got = 1;
        auto it = s.begin();
        if(it == s.end()) got = 0;
        else if(it->f >= l) got = 0;

        ll room = 0;
        if(got){
            room = it->s;
            s.erase(it);
            s.insert({r , room}); 
        }
        else{
            room = room_number++;
            s.insert({r , room});
        }

        people[index] = room;
    }

    cout << room_number - 1 << "\n";
    rep(i , n) cout << people[i] << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
   
    ll NTC=1;
    // cin>>NTC;

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
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
