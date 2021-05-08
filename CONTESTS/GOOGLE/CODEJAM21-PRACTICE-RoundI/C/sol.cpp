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

ll findScore(string s , string t){
    ll ans = 0ll;
    ll n = sz(s);
    rep(i , n) ans += (s[i] == t[i]);
    return ans;
}
bool compatible(string &s , vector<string> &answer , vll &score){
    ll n = sz(score);
    rep(i , n){
        if(findScore(s , answer[i]) != score[i]) return 0; 
    }
    return 1;
}   
void solve(){
    ll n , q;
    cin >> n >> q;

    vector<string> answer(n);
    vll score(n);
    rep(i , n) cin >> answer[i] >> score[i];

    vector<string> answer_key;
    if(q <= 10){
        // finding all possible equally likely answer keys
        rep(i , (1ll << q)){
            string poss;
            rep(j , q){
                if(i & (1ll << j)) poss.pb('T');
                else poss.pb('F');
            }
            if(compatible(poss , answer , score)) answer_key.pb(poss);
        }

        // finding expected score for all possible student's answer as per the answer keys
        map<string , pll> expectation;
        rep(i , (1ll << q)){
            string my_answer;
            rep(j , q){
                if(i & (1ll << j)) my_answer.pb('T');
                else my_answer.pb('F');
            }

            // find expected score for my_answer
            ll len = sz(answer_key);
            ll num = 0ll;
            ll den = len;
            rep(j , len){   
                num += findScore(my_answer , answer_key[j]);
            }

            expectation[my_answer] = mp(num , den);
        }

        // finding answer with max expectation
        string pr;
        ll val = 0ll;
        ll num = 0ll , den = 0ll;
        trav(it , expectation){
            pll p = (it->s);
            val = max(val , p.f);
            if(val == p.f) {
                num = p.f , den = p.s;
                pr = it->f;
            }
        }

        ll g = gcd(num , den);
        num /= g;
        den /= g;

        cout << pr << " " << num << "/" << den << "\n";
    }
    else assert(0);

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
