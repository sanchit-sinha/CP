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
#define sz(c)               (int)((c).size())
#define get(x,c)            get<x>((c))
#define trav(a,x)           for(auto a = (x).begin() ; a != (x).end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

string to_string(string s) {return '"' + s + '"';} string to_string(const char* s) {return to_string((string) s);} string to_string(bool b) {return (b ? "true" : "false");} template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";} template <typename A>string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", ";} first = false; res += to_string(x);} res += "}"; return res;} void debug_out() { cerr << "\n"; } template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n"; debug_out(T...);}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

inline ll gcd(ll a, ll b) {if (b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a, ll b) {return ((a > b) ? a : b);}
inline ll min(ll a, ll b) {return ((a > b) ? b : a);}
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

ll ask(vll v){
    cout << "? ";
    ll m = sz(v);
    rep(i , m) cout << v[i] << " ";

    cout << endl;

    ll x;
    cin >> x;

    return x;
}

void pr(ll ans){
    cout << "!" << " " << ans << endl;
}
void solve() {
    ll n , k;
    cin >> n >> k;

    if(n < k){
        cout << -1 << endl;
        return;
    }

    ll ans = 0ll;
    vll rem;
    for(ll i = 1 ; i <= n ; i += k){
        vll v;
        FOR(j , i , i + k - 1){
           if(j <= n) v.pb(j);
        }

        if(sz(v) == k){
            ll x = ask(v);
            ans = (ans ^ x);
        }
        else{
            rem = v;
        }
    }


    if(sz(rem) == 0){
        pr(ans);        
        return;
    }

    ll remlen = sz(rem);
    if(remlen % 2 == 0){
        vll choose;
        FOR(j , 1 , k - 1) choose.pb(j);

        FOR(j , 0 , remlen - 1){
            ll node = rem[j];
            choose.pb(node);
            
            ll x = ask(choose);
            ans = (ans ^ x);

            choose.pop_back();
        }

        pr(ans);
        return;
    }

    if(remlen % 2 == 1){
        if(k%2 == 0){
            cout << -1 << endl;
            return;
        }
        else{
            // k is odd => k - remlen -> even
            ll pickup = k - remlen;
            ll last = rem[0] - 1;

            vll choose;
            FORR(i , last , last - pickup + 1){
                choose.pb(i);
            }

            vll tot;
            rep(i , sz(rem)) tot.pb(rem[i]);
            rep(i , sz(choose)) tot.pb(choose[i]);

            assert(sz(tot) == k);

            ll x = ask(tot);
            ans = (ans ^ x);

            ll req_more = k - 1 - sz(rem);
            FOR(i , 1 , req_more) rem.pb(i);

            assert(sz(choose) == k - 1);

            rep(j , sz(choose)){
                ll node = choose[j];

                rem.pb(node);
                ll xx = ask(rem);
                ans = (ans ^ xx);

                rem.pop_back();
            }


            pr(ans);
            return;

        }
    }

    cout << -1 << endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);

    ll NTC = 1;
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

    ll PTC = 0;
    while ((PTC++) < NTC) {
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
