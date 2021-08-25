#include "bits/stdc++.h"
using namespace std;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define size(c) (int)(c.size())
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

const ll N = 1e3 +11;
ll n;
string s;
ll rot[N];
string convert(ll add){
    ll n = size(s);
    string s1;
    for(ll i = 0 ; i < n; i++){
        char c  = (char)( ((s[i] - '0' + add)%10) + '0');
        s1.pb((char)(c));
    }
    return s1;
}
string rotate(string &s1 , ll times){
    string x;
    times = n - times;
    for(ll i = times ; i < n ; i++) x.pb(s1[i]);
    for(ll i = 0 ; i < times ; i++) x.pb(s1[i]);
    return x;
}
void solve(){
    cin >> n ;
    cin >> s;
    ll mn = inf;
    string ans = "";
    ll  mark = 0;
    for(ll i = 0 ; i < n;  i++){
        ll num = s[i] - '0';
        ll dif = 10 - num;
        string s1 = convert(dif);
        string def = s1;
        // cout << i << " :  " << s1 << endl;
        for(ll j = 0 ; j < n; j++){
            string nw = rotate(def , j);
            // cout << j <<" " << nw << endl;
            if(nw < s1) s1 = nw;
        }
        if(ans == "") ans = s1;
        else if(s1 < ans) ans = s1;
    }
    cout << ans << endl;
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
