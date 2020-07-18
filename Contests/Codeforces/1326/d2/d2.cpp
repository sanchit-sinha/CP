#include "bits/stdc++.h"
using namespace std;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
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

const ll N = 1e6 + 1;
// 1 indexed .. p[i] is the length of the longest proper prefix of the substring s[0…i] which is also a suffix of this substring 
vll KMP(string &s){
    int n = (int)s.length();
    vector<ll> p(n + 1);
    p[0] = 0; p[1] = 0;
    int j;
    for(int i = 2; i <= n; i++){
       j = p[i - 1];
       while(j > 0 && s[j] != s[i - 1]) j = p[j];
       if(s[j] == s[i - 1]) j++;
       p[i] = j;
    }
    return p;
}
void solve(){
    string s;
    cin >> s;
    string temp = s;
    ll n = s.size();
    string x , y ;
    x = s ;
    reverse(all(s));
    y = s ;
    ll l1 = 0;
    for(ll i = 0 ; i < n ; i++ ){
        if(x[i] == y[i]){
            l1  =  i + 1;
        }
        else break;
    }
    // cout << l1 << " ";
    y.clear(); 
    for(ll i = l1 ; i <= n - l1 - 1; i++) y.pb(x[i]);
    // cout << y << " ";
    // nl;
    if(l1 + l1 >= n){
        cout << temp << endl;
        return;
    }
    string x1 = y + '$';
    reverse(all(y));
    string y1 = y + '$';
    x1 += y;
    reverse(all(y));
    y1 += y;
    // cout << x1 << endl;
    // cout << y1 << endl;
    vll kmp = KMP(x1);
    ll l2 = kmp[(int)(x1.size())];
    // cout << l2;
    kmp.clear();
    kmp = KMP(y1);
    ll l3 = kmp[(int)(y1.size())];
    // cout << " " << l3 ;
    // nl;nl;

    for(ll i = 0 ; i <= l1 - 1 ; i++) cout << temp[i];
    if(l2 > l3) for(ll i = l1 ; i <= l1 + l2 - 1 ; i++) cout << temp[i];
    else for(ll i = n - 1 - (l1 - 1) - l3; i < (n - 1) - (l1 - 1) ; i++) cout << temp[i];
    for(ll i = (n - 1) - (l1 - 1) ; i <= n - 1 ; i++) cout << temp[i];
    nl;
}
int main(){
    IOS;
    cout << fixed << setprecision(20);
    ll NTC=1;
    cin>>NTC;
    ll PTC=0;
    while(PTC++<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
