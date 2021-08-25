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
    ll a[n] , b[n] , c[m];
    rep(i , n) cin >> a[i];
    rep(i , n) cin >> b[i];


    map<ll ,ll> col;
    rep(i , m){
        cin >> c[i];
        col[c[i]] = i;
    }

    map<ll , multiset<pll> > time ;
    set<ll> already;
    map<ll , set<ll>> difer;

    // cout << "--------------COL----------\n";
    // trav(it , col){
    //     cout << it->f << ": " << it->s << "\n";
    // }
    // cout << "\n\n";
    // cout << "--------TIME-----------\n";
    // trav(it , time){
    //     cout << it->f << ":  ";
    //     trav(it1 , it->s) cout << it1->f << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    ll mx = 0 , last_index = -1;

    rep(i , n){
        if(a[i] != b[i]) difer[b[i]].insert(i);

        auto it = col.find(b[i]);
        if(it != col.end()){
            time[b[i]].insert(mp(col[b[i]] , i));
            mx = max(mx , col[b[i]]);
            if(mx == col[b[i]]){
                last_index = i;
            }
        }
        else{
            if(a[i] != b[i]){
                cout << "NO\n";
                return ;
            }
            else{
                already.insert(a[i]);
            }
        }
    }



    vll index;
    rep(i , m){
        bool got = 0 ;
        auto it1 = difer.find(c[i]);    
        if(it1 != difer.end()){
            got = 1;
            ll indexx = *difer[c[i]].begin();
            index.pb(indexx);
            difer[c[i]].erase(indexx);

            time[c[i]].erase(time[c[i]].find(mp(col[c[i]] , indexx)));
            if(sz(time[c[i]]) == 0){
                time.erase(time.find(c[i]));
            }

            if(sz(difer[c[i]]) == 0){
                difer.erase(difer.find(c[i]));
            }
        }

        if(!got){
            if(i <= last_index){
                index.pb(last_index);
                if(i == last_index) last_index = -1;
            }
            else{
                cout << "NO\n";
                return ;
            }

            // auto it = time.find(c[i]);
            // if(it != time.end()){
            //     ll indexx = time[c[i]].begin()->s;
            //     ll timing = time[c[i]].begin()->f;
            //     if(timing >= i) got = 1;

            //     if(timing == i){
            //         index.pb(indexx);

            //         time[c[i]].erase(time[c[i]].find(mp(col[c[i]] , indexx)));
            //         if(sz(time[c[i]]) == 0){
            //             time.erase(time.find(c[i]));
            //         }
            //     }

            // }
            // else{
            //     if(sz(time) == 0){
            //         cout << "NO\n";
            //         return ;
            //     }
            //     else{
            //         ll indexx = ((time.begin())->s).begin()->s;
            //         index.pb(indexx);
            //     }
            // }
        }
    }

    cout << "YES\n";
    rep(i , m) cout << index[i] + 1 << " ";
    cout << "\n";
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

