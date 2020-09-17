#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

const ll N=2e5+11;
ll n,a[N],b[N];
vector<ll> topo,v[N],choosen_index;
bool vis[N];
void dfs(ll node){
    vis[node]=1;
    for(auto child:v[node]){
        if(!vis[child]) dfs(child);
    }
    topo.push_back(node);
}

int main(){
    IOS;
    cin>>n;

    ll ans=0;
    for(ll i=1;i<=n;i++)
        cin>>a[i],ans+=a[i];

    for(ll i=1;i<=n;i++){
        cin>>b[i];
        if(b[i]!=-1) v[i].push_back(b[i]);
    }

    for(ll i=1;i<=n;++i){
        if(!vis[i]) dfs(i);
    }

    reverse(topo.begin(),topo.end());

    for(ll i=1;i<=n;++i) vis[i]=0;

    for(ll i=0;i<(int)(topo.size());++i){
        ll node=topo[i];
        if(b[node]==-1){
            choosen_index.push_back(node);
            vis[node]=1;
        }
        for(auto child:v[node]){
            ll to_add=a[node];
            if(to_add>=0){
                choosen_index.push_back(node);
                vis[node]=1;
                a[child]+=to_add;
                ans+=to_add;
            }
        }
    }

    for(ll i=n-1;i>=0;--i){
        ll node=topo[i];
        if(!vis[node]) choosen_index.push_back(node);
    }

    cout<<ans<<"\n";
    for(ll i=0;i<(int)(choosen_index.size());++i) cout<<choosen_index[i]<<" ";

}
