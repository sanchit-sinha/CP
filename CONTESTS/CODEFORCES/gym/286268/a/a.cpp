#include "bits/stdc++.h"
using namespace std;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define trav(a,x) for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define f first
#define s second

inline ll max(ll a,ll b) {return ((a>b)?a:b);}
inline ll min(ll a,ll b) {return ((a>b)?b:a);}
inline ll gcd(ll a ,ll b) {if(b==0) return a; a%=b;return gcd(b,a);}
ll power(ll x, ll y){if(y == 0) return 1; ll a = power(x,y/2);if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex , ll md) {ll ans = 1ll;while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll;x = (x * x) % md;}return ans;}

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5 + 11;
string s1 , s;
bool good[26];
void solve(){
    cin >> s1 >> s;
    rep(i , sz(s1)) good[s1[i] - 'a'] = 1;
    ll pos = -1;
    rep( i , sz(s)) if(s[i] == '*') pos = i;
    ll q;
    cin >> q;
    while(q--){
        string t;
        cin >> t;
        if(pos == -1){
            if(sz(t) != sz(s)) cout <<"NO\n";
            else{
                bool ok = 1;
                rep(i , sz(t)){
                    if(s[i] == '?') {
                        if(!good[t[i] - 'a']) ok = 0;  
                    }
                    else{
                        // cout << i << ": " << t[i] << " " << s[i] << endl;
                        if(t[i] != s[i]) ok = 0;
                    }
                }
                if(ok) cout <<"YES\n";
                else cout <<"NO\n";
            }
        }
        else{
            if(sz(t) < sz(s) - 1) cout <<"NO\n";
            else if(sz(t) == sz(s) - 1){
                bool ok = 1;
                for(ll i = 0 ; i < pos ; i++){
                        if(s[i] == '?') {
                            if(!good[t[i] - 'a']) ok = 0;  
                        }
                        else{
                            // cout << i << ": " << t[i] << " " << s[i] << endl;
                            if(t[i] != s[i]) ok = 0;
                        }  
                }
                for(ll i = pos ; i < sz(t); ++i){
                    if(s[i + 1] == '?') {
                            if(!good[t[i] - 'a']) ok = 0;  
                        }
                        else{
                            // cout << i << ": " << t[i] << " " << s[i + 1] << endl;
                            if(t[i] != s[i + 1]) ok = 0;
                        } 
                }
                if(ok) cout <<"YES\n";
                else cout <<"NO\n";
            }
            else{
                bool ok = 1;
                for(ll i = 0 ; i < pos ; i++){
                        if(s[i] == '?') {
                            if(!good[t[i] - 'a']) ok = 0;  
                        }
                        else{
                            // cout << i << ": " << t[i] << " " << s[i] << endl;
                            if(t[i] != s[i]) ok = 0;
                        }  
                }
                ll len = sz(t) - sz(s) + 1;
                // cout << pos  <<" " << pos + len << " o k " << ok <<  endl;
                for(ll i = pos ; i < pos + len ; i++){
                    if(good[t[i] - 'a']) ok = 0;
                }
                ll x = len - 1;
                for(ll i = pos + len ; i < sz(t) ; i++){
                    // cout << i <<" " << i - x << endl;
                    if(s[i - x] == '?'){
                        if(!good[t[i] - 'a']) ok = 0;
                    }
                    else{
                        if(s[i - x] != t[i]) ok = 0;
                    }
                }
                if(ok) cout <<"YES\n";
                else cout <<"NO\n";
            }
        }
    }
}
int main(){
    IOS;
    cout << fixed << setprecision(20);
    ll NTC = 1;
    // cin >> NTC;
    ll PTC = 0;
    while(PTC++ < NTC){
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
