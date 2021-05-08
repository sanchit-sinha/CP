#include "bits/stdc++.h"
using namespace std;
#define f                   first
#define s                   second
#define pb                  push_back
#define ll                  int
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

const ll N = 1e5+11;

string gr(string s){
    ll n = sz(s);
    FORR(i , n - 1 , 0){
        if(s[i] == '9') s[i] = '0';
        else{
            s[i]++;
            return s;
            break;
        }
    } 

    reverse(all(s));
    s.pb('1');
    reverse(all(s));

    return s;
}
bool check(string s){
    // cout << s << "\n\n";

    ll n = sz(s);
    FOR(l , 1 , n - 1){
        string f = s.substr(0 , l);
        ll i = l; // next index of starting string 
        bool got = 1;
        while(i < n){
            string next = gr(f);
            // cout << l << " " << i << ":  " << f << " " << next << "\n";

            bool ok = 1;
            ll index = 0;
            FOR(j , i , n - 1){
                if(index == sz(next)) break;
                if(next[index] != s[j]){
                    ok = 0;
                    got = 0;
                    break;
                }

                index++;    
            }

            if(index != sz(next)) ok = 0 , got = 0;
            // cout << " index " << index <<  " " << next << "\n";

            if(ok){
                i += sz(next);
                f = next;
            }
            else break;
        }
        if(got) {
            // cout << " this is i t" << f << "\n";
            return 1; 
        }
    }

    return 0;
}
void solve(){
    ll n;   
    cin >> n;

    // cout << gr("9999") << "\n";
    // cout << gr("1999") << "\n" ;

    // check("78910");
    // return;

    FOR(i , n + 1 , 1234567){
        string s = to_string(i);
        if(check(s)){
            cout << i << "\n";
            return;
        }
    }
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
