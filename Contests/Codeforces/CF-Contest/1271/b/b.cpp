#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define nl cout << "\n"
#define endl "\n"
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define mp make_pair
#define mt make_tuple
#define get(x,c) get<x>(c)
#define trav(a,x) for(auto a=x.begin() ; a!=x.end() ; a++)
#define rep(i,n) for(int i=0 ; i<n ; i++)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define f first
#define s second

inline ll max(ll a,ll b) {return ((a>b)?a:b);}
inline ll min(ll a,ll b) {return ((a>b)?b:a);}
inline ll gcd(ll a ,ll b) {if(b==0) return a; a%=b;return gcd(b,a);}
ll power(ll x,ll y){if(y == 0) return 1; ll a = power(x,y/2);if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x,ll ex ,ll md) {ll ans = 1ll;while(ex > 0){if(ex & 1ll) ans = (ans*x)%md; ex >>= 1ll;x=(x*x)%md;}return ans;}

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 2e2 + 11;
ll n;
string s;
void solve(){
    cin>>n>>s;
    vll ans;
    string s1 = s;
    rep(i,n-1){
        if(s[i]=='B' && s[i+1]=='B'){
            ans.pb(i);
            s[i] = 'W';
            s[i+1] ='W';
        }
        else if(s[i] =='B' && s[i+1] == 'W'){
            ans.pb(i);
            s[i] = 'W';
            s[i+1] = 'B';
        } 
    }
    if(s[n-1] == 'W'){
        cout<<sz(ans) << endl;
        trav(it,ans) cout<<(*it) + 1 <<" ";
        nl;
    }
    else{
        vll ans2;
        rep(i,n-1){
            if(s1[i]=='W' && s1[i+1]=='W'){
                ans2.pb(i);
                s1[i] = 'B';
                s1[i+1] ='B';
            }
            else if(s1[i] =='W' && s1[i+1] == 'B'){
                ans2.pb(i);
                s1[i] = 'B';
                s1[i+1] = 'W';
            } 
        }
        if(s1[n-1] == 'B'){
            cout <<sz(ans2) <<endl;
            trav(it,ans2) cout<<(*it) + 1<<" ";
            nl;
        }
        else cout << -1 <<endl;
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
        cout << "\n";
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
