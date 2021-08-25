/**
 *    Author:  Sanchit Sinha
 *    Created: 29.10.2020 01:43:09       
**/
#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define mp make_pair
#define mt make_tuple
#define get(x,c) get<x>(c)
#define trav(a,x) for(auto a=x.begin();a!=x.end();a++)
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,b,a) for(int i=b;i>=a;i--)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define f first
#define s second

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll power(ll x,ll y);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 511;
ll n,m;
string s[N];
ll dx[4] = {1 , -1 , 0 , 0};
ll dy[4] = {0 , 0 , 1 , -1};
bool vis[N][N];
void dfs(ll i , ll j){
    vis[i][j] = 1;
    for(ll k=0;k<4;k++){
        ll x = i - dx[k];
        ll y = j - dy[k];
        if(x >= 0 && y >= 0 && x < n && y < m && vis[x][y] == 0 && s[x][y]=='*'){
            dfs(x , y);
        }
    }
}
ll connected_components(){
    ll number=0;
    rep(i,n){
        rep(j,m){
            if(!vis[i][j] && s[i][j]=='*'){
                number++;
                dfs(i,j);
            }
        }
    }
    return number;
}
bool present(ll index1,ll index2){
    if(index1>=0 && index1<n && index2>=0 && index2<m){
        if(s[index1][index2]=='*') return true;
        else return false;
    }
    else return false;
}
void solve(){
    cin>>n>>m;
    rep(i,n) cin>>s[i];
    if(connected_components()==1){
        ll ans=0;
        ll ct=0;
        ll index1=-1,index2=-1;
        bool got=0;
        rep(i,n){
            rep(j,m){
                if(s[i][j]=='*'){
                    ll pres=0;
                    if(present(i-1,j)) pres++;
                    if(present(i+1,j)) pres++;
                    if(present(i,j+1)) pres++;
                    if(present(i,j-1)) pres++;
                    if(pres==4){
                        got=1;
                        index1=i;
                        index2=j;
                        break;
                    }
                }
            }
            if(got) break;
        }

        if(index1==-1 || index2==-1) cout<<"NO\n";
        else{
            bool ok=1;
            rep(i,n){
                rep(j,m){
                    if(i==index1 || j==index2) continue;
                    else{
                        if(s[i][j]=='*'){
                            ok=0;
                            break;
                        }
                    }
                }
                if(ok==0) break;
            }
            if(!ok) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
    else cout<<"NO\n";
}
int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    ll NTC=1;
    // cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
