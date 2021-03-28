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
    ll n , m;
    cin >> n >> m;

    map< ll , vll > day_friend_availabilty;
    map<ll , multiset<ll> > people;
    rep(i , m){
        ll k;
        cin >> k;
        rep(j , k){
            ll x;
            cin >> x;
            day_friend_availabilty[i + 1].pb(x);
            people[x].insert(i + 1);
        }
    }

    map<ll , multiset<pll>> day;
    // day[i] = {friend availabe for how many days , which friend available}
    rep(i , m){
        ll index = i + 1;
        trav(it , day_friend_availabilty[index]){
            ll person = *it;
            day[index].insert(mp(sz(people[person]) , person));
        }
    }

    map<ll , multiset<pll > > frnd;
    // frnd[i] = {how many people are free that day , which day free}
    rep(i , n){
        ll index = i + 1;
        trav(it , people[index]){
            ll dday = *it;
            frnd[index].insert(mp(sz(day[dday]) , dday));
        }
    }

    map<ll , ll > availability;
    FOR(i , 1 , n){
        ll len = sz(frnd[i]);
        availability[i] = min((m + 1)/2 , len);        
    }

    ll ans[m + 1] = {0};
    trav(it , day){
        ll day_number = it->f;
        trav(it1 , day[day_number]){
            ll frnd_name = it1->s;
            ans[day_number] = frnd_name;
            availability[frnd_name]--;

            auto it3 = day[day_number].find(mp(sz(frnd[frnd_name]) , frnd_name));
            if(it3 != day[day_number].end()) {
                day[day_number].erase(it3);    
                people[frnd_name].erase(people[frnd_name].find(day_number));
            }

            if(availability[frnd_name] == 0){
                availability.erase(availability.find(frnd_name));
            }
            else{
                day[day_number].insert(mp(sz(people[frnd_name]) , frnd_name));

            }
        }
    }

    bool ok = 0;
    rep(i , m){
        ll index = i + 1;
        if(ans[index] == 0){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    rep(i , m) cout << ans[i + 1] << " ";
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
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
