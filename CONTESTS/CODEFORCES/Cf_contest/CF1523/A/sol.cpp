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

bool good(string s , ll index){
    ll goodm = 0;
    if(index - 1 >= 0 && s[index - 1] == '1') goodm++;
    if(index + 1 < sz(s) && s[index + 1] == '1') goodm++;

    return (goodm == 1);
}
void solve(){
    ll n , m;
    cin >> n >> m;

    string s;
    cin >> s;

    vll ones;
    rep(i , n){
        if(s[i] == '1') ones.pb(i);
    } 


    ll len = sz(ones);
    if(len > 1){
        FOR(i , 1 , len - 1){
            ll index1 = ones[i - 1];
            ll index2 = ones[i];

            ll l = index1 + 1, r = index2 - 1;
            ll op = m;
            while(op > 0 && l <= r){
                bool okl = 0 , okr = 0;
                if(good(s , l)) okl = 1;
                if(good(s , r)) okr = 1;

                if(okl){
                    s[l] = '1';
                    l++;
                }

                if(okr){
                    s[r] = '1';
                    r--;
                }

                if(okl || okr) op--;
                else break;
            }
        }
    }

    if(sz(ones)){
        ll op = m;
        ll r = ones[0] - 1;
        while(op > 0 && r >= 0){
            s[r] = '1';
            op--;
            r--;
        }


        op = m;
        ll l = ones[len - 1] + 1;
        while(op > 0 && l < n){
            s[l] = '1';
            op--;
            l++;
        }
    }

    cout << s << "\n";

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
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

