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

pair<string , string> arrange(string s , string t){
    pair<string , string > p = mp("" , "");
    ll n = sz(s);
    ll m = sz(t);

    if(n > m) p = mp(s , t);
    else if(n < m) p = mp(t , s);
    else{
        rep(i , n){
            if(s[i] > t[i]){
                p = mp(s , t);
                return p;
            }
            else if(s[i] < t[i]){
                p = mp(t , s);
                return p;
            }
        }
    }

    return p;
}
string make_gr(string s){
    string t;
    string temp = s;

    ll n = sz(temp);
    reverse(all(temp));
    rep(i , n){
        if(temp[i] != '9'){
            temp[i]++;
            break;
        }
        else temp[i] = '0'; 
    }
    if(temp.back() == '0') temp.pb('1');
    reverse(all(temp));

    return temp;
}
ll op_loc_eq(string s){
    string temp = s;

    ll n = sz(temp);
    string t = make_gr(s);
        
    if(sz(s) != sz(t)) return inf;
    rep(i , n) if(s[i] != t[i]) return (i);
    return inf;
}

void solve(){
    ll n;
    cin >> n;

    vector<string> s(n);
    rep(i , n) cin >> s[i];

    ll op = 0;
    FOR(i , 1 , n - 1){
        string oldsi = s[i];

        string pres = s[i];
        string prev = s[i - 1];

        pair<string , string> p = arrange(pres, prev); 
        string big = p.f;
        string small = p.s;

        if(pres == small){
            // present string is smaller than prev
            bool ok = 1;
            rep(j , sz(pres)) if(pres[j] != prev[j]) ok = 0;
            if(ok){
                ll index = op_loc_eq(prev);
                if(index >= sz(pres)){
                    pres = make_gr(prev);
                    s[i] = pres;
                }
                else{
                    while(sz(pres) != sz(prev)) pres.pb('0');

                    if(pres == arrange(pres , prev).f) s[i] = pres;
                    else{
                        pres.pb('0');
                        s[i] = pres;
                    }
                }
            }
            else{
                while(sz(pres) != sz(prev)) pres.pb('0');

                if(pres == arrange(pres , prev).f) s[i] = pres;
                else{
                    pres.pb('0');
                    s[i] = pres;
                }
            }
        }
        else if(sz(small) == 0){
            // both strings are equal
            pres.pb('0');
            s[i] = pres;
        }

        op += sz(s[i]) - sz(oldsi);
    } 

    // rep(i , n) cout << s[i] << "\n";
    // cout << "\n\n";
    cout << op << "\n";
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
