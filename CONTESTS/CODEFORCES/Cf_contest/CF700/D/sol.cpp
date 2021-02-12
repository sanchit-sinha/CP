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
    ll n;
    cin >> n;
    ll a[n + 11] = {0};
    rep(i , n) cin >> a[i];
    vll black , white ;
    black.pb(n);
    white.pb(n);

    map<ll ,set<ll> > m;
    rep(i , n) m[a[i]].insert(i);

    bool safe[n + 11] = {0};
    trav(it , m){
        if(sz(it->s) == 1){
            ll index = *(it->s).begin();
            safe[index] = 1;
        }
    }
    safe[n] = 0;
    // rep(i , n) cout << safe[i] << " ";
    // cout << "\n";

    rep(i , n){
        ll x = a[i];
        ll black_back_index = black.back();
        ll white_back_index = white.back();

        ll black_back_ele = a[black_back_index];
        ll white_back_ele = a[white_back_index];
        
        if(sz(m[a[i]]) == 1) safe[i] = 1;

        if(safe[i]){
            if(!safe[black_back_index]) black.pb(i);
            else white.pb(i);
        }   
        else{
            m[a[i]].erase(m[a[i]].find(i));
            // cout << "(" << black_back_index << " " << white_back_index << ") \n";
            bool unsafe_black = !safe[black_back_index];
            bool unsafe_white = !safe[white_back_index];

            bool unsame_black = (black_back_ele != a[i]);
            bool unsame_white = (white_back_ele != a[i]);

            // cout << " start " << i << ": " << unsafe_black << " " << unsafe_white << " " << unsame_black << " " << unsame_white << "\n";
 
            if(unsafe_black){
                if(unsafe_white){
                    // black - not safe 
                    // white  - not safe 
                    if(unsame_black) {
                        // cout << " i " << i << "\n";
                        black.pb(i);
                    }
                    else if(unsame_white){
                        // cout << " i " << i << "\n";
                        white.pb(i);
                    }
                }
                else{   
                    // black - not safe 
                    // white - safe 
                    if(unsame_black) {
                        // cout << " i " << i << "\n";
                        black.pb(i);
                    }
                    else if(unsame_white) {
                        // cout << " i " << i << "\n";
                        ll len = sz(white);
                        bool ok = 0;
                        if(len >= 2){
                            // cout << " ii " << i << " " << white[len - 2] << "\n";
                            if(a[white[len - 2]] != a[i]) ok = 1;
                        }
                         if(white_back_index > black_back_index && ok){
                            white.pop_back();
                            black.pb(white_back_index);
                        }
                        white.pb(i);
                    }
                }
            }
            else{
                if(unsafe_white){
                    // black - safe 
                    // white - not safe 
                    if(unsame_white) white.pb(i);
                    else if(unsame_black){
                        ll len = sz(black);
                        bool ok = 0;
                        if(len >= 2){
                            // cout << " ii "<< i << " " << black[len - 2] << "\n";
                            if(a[black[len - 2]] != a[i]) ok = 1;
                        }
                        if(black_back_index > white_back_index && ok ){
                            black.pop_back();
                            white.pb(black_back_index);
                        }
                        black.pb(i);
                    }
                }
                else{
                    // black - safe 
                    // white - safe 
                    if(unsame_black) black.pb(i);
                    else if(unsame_white) white.pb(i);
                }   
            }
        }
       
    }
    trav(it , black) cout << *it << " ";
    cout << "\n";
    trav(it , white) cout << *it << " ";
    cout << "\n\n";

    cout << sz(black) + sz(white) - 2 << "\n";
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

