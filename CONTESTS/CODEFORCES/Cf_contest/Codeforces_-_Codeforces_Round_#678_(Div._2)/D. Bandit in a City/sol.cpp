/**
 *    Author:  Sanchit Sinha
 *    Created: 25.10.2020 15:57:52       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll N=2e5+11;
ll n,a[N],subtree_sum[N];
vector<ll>v[N];
ll ans;
void dfs(ll node,ll parent){
    for(auto child:v[node]){
        if(child != parent){
            dfs(child,node);
            subtree_sum[node]+=subtree_sum[child];
        }
    }
    subtree_sum[node]+=a[node];
}
void calc(ll node,ll parent){
    ll x=a[node];
    ll len=(int)v[node].size();
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(ll i=2;i<=n;i++){
        ll x;
        cin>>x;
        v[x].push_back(i);
    }
    for(ll i=1;i<=n;i++) cin>>a[i];

    dfs(1,0);
    for(ll i=1;i<=n;i++){
        cout<< i <<" : " << subtree_sum[i]<<"\n";
    }

    calc(1,0);
    cout<<ans<<"\n";
    return 0;
}
