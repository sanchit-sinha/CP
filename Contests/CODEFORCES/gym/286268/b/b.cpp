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

const ll N = 1e2 + 11;
ll n , m , parent[N];
vll v[N];
string A[N][N] , B[N][N];
char c[N][N];
bool vis[N];
vll topo1 , topo2;
vll topo;
void dfs(ll node){
    vis[node] = 1;
    for(auto child : v[node]){
        if(!vis[child]){
            parent[child] = node;
            dfs(child);
        }
    }
    topo.pb(node);
}
void solve(){
    cin >> n >> m;
    rep(i , m){
        ll x , y ;
        char z;
        cin >> x >> y;
        cin >> z;
        v[x].pb(y);
        c[y][x] = (char)(z);
    }
    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1;  j <= n ; j++){
            // clear
            topo.clear() ; topo1.clear() ; topo2.clear();
            for(ll k = 1 ; k <= n; k++) {
                vis[k] = 0;
            }
            for(ll k = 0 ; k <= n; k++){
                for(ll l = 0 ; l <= n ; l++) A[k][l] = "", B[k][l] = "";
            }
            // A
            dfs(i);
            topo1 = topo;
            
            topo.clear();
            
            // B
            dfs(j);
            topo2 = topo;

            reverse(all(topo1));
            reverse(all(topo2));

            // cout << " I " << i << ":  " <<  j << endl;
            // for(ll k =0  ; k < sz(topo1) ; k++) cout << topo1[k] << " ";
            // nl;
            // for(ll k = 0 ; k < sz(topo2) ; k++) cout << topo2[k] << " ";
            // nl;nl; 

            for(ll k = 0 ; k < sz(topo1) ; k++){
                ll node = topo1[k];
                for(auto child :v[node]){
                    A[child][node] = A[node][parent[node]];
                    A[child][node].pb(c[child][node]);
                }
            }

            for(ll k = 0 ; k < sz(topo2) ; k++){
                ll node = topo2[k];
                for(auto child : v[node]){
                    B[child][node] = B[node][parent[node]];
                    B[child][node].pb(c[child][node]);
                }
            }
            


            vector<string> v1 , v2;
            for(ll k = 0 ; k < sz(topo1) ; k++){
                ll node = topo1[k];
                if(sz(v[node]) == 0) {
                    // cout << " string " << A[node][parent[node]] << " ";
                    v1.pb(A[node][parent[node]]);
                }
            }

            for(ll k =0 ; k < sz(topo2) ; k++){
                ll node = topo2[k];
                if(sz(v[node]) == 0) {
                    // cout << " B " << B[node][parent[node]] << " ";
                    v2.pb(B[node][parent[node]]);
                }
            }

            bool wina = 1;
            bool ok = 1;
            for(ll k = 0 ; k < sz(v1) ; k++){
                string s1 = v1[k];
                ok = 1;
                for(ll l = 0 ; l  <sz(v2) ; l++){
                    string s2 = v2[l];
                    cout << " s1 " << s1 << " " << " s2 " << s2 << endl;
                    if(s1 < s2) ok = 0;
                }
                if(ok) break;
            }
            if(ok) cout << "A";
            else cout <<"B";
        }
        nl;
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
