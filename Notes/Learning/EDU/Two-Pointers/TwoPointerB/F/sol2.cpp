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

string to_string(string s) {return '"' + s + '"';}string to_string(const char* s) {return to_string((string) s);}string to_string(bool b) {return (b ? "true" : "false");}template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A>string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}void debug_out() { cerr << "\n"; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n";debug_out(T...);} 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

inline ll gcd(ll a,ll b) {if(b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a,ll b) {return((a > b) ? a : b);}
inline ll min(ll a,ll b) {return((a > b) ? b : a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

/* supports: insertion from back : insert
             removal from front : popfront
             min and max query of elements in the data-structure : mn , mx
                                                                    */  
struct mn_mx_stack{
    stack <tuple<ll , ll , ll >> s1 , s2;  
    //       element , mn , mx | orig rev
    pair<ll , ll> mnn , mxx;

    void insert(ll add){
    	if((int)s1.size()){
    		tuple<ll , ll , ll> t = s1.top();
    		mnn.f = get<1> (t);
    		mxx.f = get<2> (t);
    	}
    	else mnn.f = inf , mxx.f = -inf ;

        mnn.f = min(mnn.f , add);
        mxx.f = max(mxx.f , add);

        tuple<ll , ll , ll > tnew = mt(add , mnn.f , mxx.f);
        s1.push(tnew);
    }

    void popfront(){
        if((int)s2.size()) s2.pop();
        else{
            while((int)(s1.size())){
                tuple<ll , ll , ll> t = s1.top();
                
                if((int)s2.size()){
		    		tuple<ll , ll , ll> t1 = s2.top();
		    		mnn.s = get<1> (t1);
		    		mxx.s = get<2> (t1);
		    	}
		    	else mnn.s = inf , mxx.s = -inf ;

                ll add = get<0> (t);
                mnn.s = min(mnn.s , add);
                mxx.s = max(mxx.s , add);

                t = make_tuple(add , mnn.s , mxx.s);
                s2.push(t);
                s1.pop();
            }

            s2.pop();
        }
    }   

    ll mn(){
        tuple<ll , ll , ll > t1 , t2;
        t1 = t2 = make_tuple(-1 , inf , -inf);
        
        if((int)s1.size()) t1 = s1.top();
        if((int)s2.size()) t2 = s2.top();
    
        return min(get<1>(t1) , get<1>(t2));
    }

    ll mx(){
        tuple<ll , ll , ll > t1 , t2;
        t1 = t2 = make_tuple(-1 , inf , -inf);
        
        if((int)s1.size()) t1 = s1.top();
        if((int)s2.size()) t2 = s2.top();
    
        return max(get<2>(t1) , get<2>(t2));
    }
};

void solve(){
	ll n , k;
	cin >> n >> k;

	vll a(n);
	rep(i , n) cin >> a[i];

	mn_mx_stack s;

	ll l = 0 , r = 0 , ans = 0ll;	
	s.insert(a[0]);

    while(l < n && r < n){
        ll mn = s.mn();
        ll mx = s.mx();

        ll x = mx - mn;
        if(x <= k){ // increase mx || decrease mn
            ans += (r - l + 1);
            r++;
            s.insert(a[r]);
        }
        else{
            s.popfront();
            l++;
        }
    }    

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
   
    ll NTC=1;
    // cin>>NTC;

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
