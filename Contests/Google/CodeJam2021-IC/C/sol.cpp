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

string convdecimal(ll x){
    string ans;
    if(x == 0) ans.pb('0');
    while(x) ans.pb((char)(x%2 + '0')) , x /= 2;

    reverse(all(ans));
    return ans;
}
ll convbinary(string s){
    ll x = 0ll;
    rep(i , sz(s)){
        x += (1ll << (sz(s) - i - 1)) * (s[i] - '0');
    }
    return x;
}
void perform(vll &op , ll x , ll y , ll &ans){
    ll len = sz(op);
    // 0 for double 
    // 1 for not 

  

    do{ 
        // string final = s;
        // if(op[0] == 1 && op[1] == 0 && op[2] == 0 && op[3] == 1){
        //     cout << " this one\n";
        //     rep(i , len) cout << op[i] << " ";
        //     cout << "\n";
        // }

        ll f = x;
        rep(i , len){
            if(op[i] == 1){
                string final = convdecimal(f);
                rep(j , sz(final)){
                    if(final[j] == '0') final[j] = '1';
                    else final[j] = '0';
                }
                f = convbinary(final);
                // reverse(all(final));
                // while(sz(final)){
                //     if(final.back() == '0') final.pop_back();
                //     else break;
                // }

                // reverse(all(final));
            }
            else f *= 2;

            // if(sz(final) == sz(t)){
            //     if(final == t){
            //         ans = min(ans , i + 1);
            //         break;
            //     }
            // }

            if(f == y) {
                ans = min(ans , i + 1);
                break;
            }
        }
    } while (next_permutation(all(op)));
}
void solve(){
    string s , t;
    cin >> s >> t;

    if(s == t){
        cout << 0 << "\n";
        return;
    }
    
    ll x = 0 , y = 0;
    x = convbinary(s);
    y = convbinary(t);


    //debug
    // vll testop;
    // testop.pb(1);
    // testop.pb(0);
    // testop.pb(0);
    // testop.pb(1);
    // ll f = x;
    // rep(i , sz(testop)){
    //     if(testop[i] == 1){
    //         string final = convdecimal(f);
    //         rep(j , sz(final)){
    //             if(final[j] == '0') final[j] = '1';
    //             else final[j] = '0';
    //         }
    //         cout << " final " << final << " : " << convbinary(final) << "\n\n";
    //         f = convbinary(final);
    //     }
    //     else f *= 2;
    // }
    // cout << f << "\n";
    // return;


    ll ans = inf;



    // vll op;
    // rep(i , 8) op.pb(0);
    // rep(i , 16) op.pb(1);

    // perform(op , x , y , ans);

    // op.clear();

    // rep(i , 16) op.pb(0);
    // rep(i , 8) op.pb(1);

    // perform(op , x , y , ans);

    ll tot = 15;
    FOR(i , 0 , tot){
        ll one = i;
        ll zero = tot - one;
        vll op;
        rep(j , zero) op.pb(0);
        rep(j , one) op.pb(1);

       perform(op , x , y , ans);
 
    }



    if(ans == inf) cout << "IMPOSSIBLE\n";
    else cout << ans << "\n";
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
