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
map<ll , ll > dp;
void value(vll &special ,ll num , ll index){
    auto it1 = ub(all(special) , index - num);
    auto it2 = find(all(special) , index);

    dp[index] = it2 - it1 + 1;
}
void traverse(vll box , vll special){
    ll n = sz(box);
    FOR(i , 1 , n - 1){
        ll l = box[i - 1];
        ll r = box[i];

        ll m = 0;
        ll sizeright = 0 , sizeleft = 0;

        auto itright = lb(all(special) , r);
        if(itright != special.begin()){
            sizeright = 1;
            itright--;
        }

        auto itleft = lb(all(special) , l);
        if(itleft != special.end()){
            sizeleft = 1;
        }

        if(sizeright && sizeleft){
            // [l , r )
            m = itright - itleft + 1;
            cerr << " " << l << " " << r <<" " << m << "\n";
            ll start_index = itleft - special.begin();
            ll num = i;

            for(ll i = start_index; i < start_index + m ; i++){
                ll index = special[i];
                value(special , num , index);
            }
        }
    }
}
void print(){
    cerr << "*********************\n";
    ll ans = 0;
    trav(it , dp) ans = max(ans , it->s);

    cerr << ans << "\n";
    cerr << "*********************\n";
}
void solve(){
    dp.clear();

    ll n , m;
    cin >> n >> m;
    ll a[n];
    ll b[m];
    rep(i , n) cin >> a[i];
    rep(i , m) cin >> b[i];

    vll boxesr , boxesl, specialr , speciall;
    boxesr.pb(0);
    boxesl.pb(0);
    rep(i , n){
        if(a[i] > 0) boxesr.pb(a[i]);
        else boxesl.pb(-a[i]); 
    }
    boxesr.pb(LLONG_MAX);
    boxesl.pb(LLONG_MAX);

    specialr.pb(0);
    speciall.pb(0);
    rep(i , m){
        if(b[i] > 0) specialr.pb(b[i]); 
        else speciall.pb(-b[i]);
    }
    specialr.pb(LLONG_MAX);
    speciall.pb(LLONG_MAX);

    sort(all(boxesr));
    sort(all(boxesl));

    sort(all(specialr));
    sort(all(speciall));

    traverse(boxesr , specialr);
    ll ans1 = 0;
    trav(it , dp) ans1 = max(ans1 , it->s);

    print();
    
    dp.clear();
    traverse(boxesl , speciall);
    ll ans2 = 0;
    trav(it , dp) ans2 = max(ans2 , it->s);
    
    print();


    ll ans = 0;
    trav(it , dp) ans = max(ans , it->s);

    cout << ans1 + ans2 << "\n";
    cerr << "$$$$$$$$$$$$$$$$$$$$$$$$4\n";
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
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

