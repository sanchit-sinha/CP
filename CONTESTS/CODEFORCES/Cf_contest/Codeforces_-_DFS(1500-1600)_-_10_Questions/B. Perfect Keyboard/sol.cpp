/**
 *    Author:  Sanchit Sinha
 *    Created: 26.10.2020 17:14:22       
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

const ll N = 30;
string ans,s;
set<ll> v[N];
vll nodes;
ll leaf;
bool vis[N];
void dfs(ll node){
    vis[node]=1;
    nodes.pb(node);
    bool enter=0;
    for(auto child:v[node]){
        if(!vis[child]){
            enter=1;
            dfs(child);
        }
    }
    if(!enter) leaf=node;
}
void store(ll node){
    vis[node]=1;
    char c=(char)('a'+node);
    ans.pb((char)c);
    for(auto child:v[node]){
        if(!vis[child]){
            store(child);
        }
    }
}
void solve(){
    s.clear();
    ans.clear();
    nodes.clear();
    rep(i,27){
        vis[i]=0;
        v[i].clear();
    }
    leaf=-1;
   
    cin>>s;
    ll n=sz(s);
    rep(i,n-1){
        ll x=s[i]-'a';
        ll y=s[i+1]-'a';
        
        if(x==y){
            cout<<"NO\n";
            return ;
        }
        else{
            v[x].insert(y);
            v[y].insert(x);
        }
    }   

    rep(i,26){
        if(!vis[i]){
            dfs(i);
            
            ll len=sz(nodes);
            rep(j,len){
                ll node=nodes[j];
                ll len1=sz(v[j]);
                if(len1>2){
                    cout<<"NO\n";
                    return ;
                }
                vis[node]=0;
            }
            store(leaf);

            nodes.clear();
            leaf=-1;
        }
    }

    rep(i,n-1){
        char pres=s[i],next=s[i+1];
        rep(j,26){
            if(ans[j]==pres){
                ll index1=j-1;
                ll index2=j+1;
                bool got=0;

                if(index1>=0 && index1<26){
                    if(ans[index1]==next) got=1;
                }
                if(index2>=0 && index2<26){
                    if(ans[index2]==next) got=1;
                }

                if(!got){
                    cout<<"NO\n";
                    return ;
                }
            }
        }
    }

    cout<<"YES\n";
    cout<<ans<<"\n";
}
int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    ll NTC=1;
    cin>>NTC;
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
