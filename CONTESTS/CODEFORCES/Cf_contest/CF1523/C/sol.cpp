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
string gr(string s){
    ll n = sz(s);
    reverse(all(s));
    rep(i , n){
        if(s[i] != '9'){
            s[i]++;
            break;
        }
        else s[i] = '0';
    }    

    if(s.back() == '0') s.pb('1');
    reverse(all(s));
    return s;
}
string nx(string s){
    string rem;
    ll index = -1;
    ll n = sz(s);
    rep(i , n) if(s[i] == '.') index = i;

    FOR(i , index + 1 , n - 1) rem.pb(s[i]);
    
    while(sz(s) && s.back() != '.') s.pop_back();
    if(sz(s) && s[0] == '.') s.pop_back();
    string t = gr(rem);


    s += t;
    return s;
}
bool check(string s , ll x){
    string tt = to_string(x);
    string rem;
    ll index = -1;
    ll n = sz(s);
    rep(i , n) if(s[i] == '.') index = i;

    FOR(i , index + 1 , n - 1) rem.pb(s[i]);
    string t = gr(rem);

 
    if(t == tt) return 1;
    return 0;
}
void solve(){
    ll n; cin >> n;

    vll v(n);
    rep(i , n) cin >> v[i];

    map<ll , string> m;
    ll ones = 0;
    ll index = n;
    rep(i , n){
        if(v[i] == 1) ones++;
        else{
            index = i;
            break;
        }
    }

    vector<string> ans;
    m[1] = "1";
    ll prev = 1;
    ans.pb(m[prev]);
    rep(i , ones - 1){
        string s = m[prev] + ".1";
        m[prev + 1] = s;
        prev = prev + 1;
        ans.pb(m[prev]);
    }

    FOR(i , index , n - 1){
        if(v[i] == 1){
            if(sz(m)){
                auto it = m.rbegin();
                ll len = it->f;
                string s = m[len];
                s += ".1";
                m[len + 1] = s;
                ans.pb(m[len + 1]);
            }
            else m[1] = "1"; 
        }
        else{
            bool got = 1;
            while(!m.empty()){
                auto it = m.rbegin();
                ll len = it->f;
                string s = m[len];
                if(check(s , v[i])){
                    string t = nx(s);
                    m[len] = t;
                    got = 1;
                    ans.pb(m[len]);
                    break;
                }
                else{
                    auto it1 = m.find(len);
                    if(it1 != m.end()) m.erase(it1);
                }   
            }
        }
    }

    rep(i , sz(ans)) cout << ans[i] << "\n";
    cout << "\n";

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
