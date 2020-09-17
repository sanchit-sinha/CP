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

const ll N = 1e5 + 11;
ll n ;
string s , t;
void solve(){
    cin >> n >> s >> t;
    vll ct(26 , 0);
    rep(i , n){
        ct[s[i] - 'a']++;
        ct[t[i] - 'a']++;
    }
    bool crct = 1;
    for(ll i = 0 ; i < 26 ; i++) if(ct[i]%2 != 0 ) crct = 0;
    if(!crct) cout << "No\n";
    else{
        cout << "Yes\n";
        vector<bool> vis(n , 0);
        vpll index;
        for(ll i = 0 ; i < n ; i++){
            if(s[i] == t[i]) vis[i] = 1 ;
            else{
                char c = s[i];
                for(ll j = i + 1 ; j < n; j++){
                    if(s[j] == c){
                        index.pb({j + 1 , i + 1});
                        swap(s[j] , t[i]);
                        vis[i] = 1 ;
                        break;
                    }
                }
                if(!vis[i]){
                    for(ll j = i + 1 ; j < n; j++){
                        if(t[j] == c){
                            index.pb({n , j + 1});
                            swap(t[j] , s[n - 1]);
                            index.pb({n , i + 1});
                            swap(t[i] , s[n - 1]);
                            vis[i] = 1;
                            break;
                        }
                    }
                }
            }
        }
        cout << size(index) << endl;
        for(ll i = 0 ; i < size(index) ; i++) cout << index[i].f << " " << index[i].s << endl;
    }
}
int main(){
    IOS;
    cout << fixed << setprecision(20);
    ll NTC = 1;
    cin >> NTC;
    ll PTC = 0;
    while(PTC++ < NTC){
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
