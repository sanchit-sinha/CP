#include "bits/stdc++.h"
using namespace std;

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

const ll N=1e5+11;

ll n,m,people[N],total_people[N],good[N],bad[N],child_good[N],child_bad[N],parent[N],happiness[N];
vector<ll> v[N];
bool vis[N];

void total_population(ll node){
    vis[node]=1;
    for(auto child:v[node]){
        if(!vis[child]){
            total_population(child);
            total_people[node]+=total_people[child];
        }
    }
}

void child_calculation(ll node){
    vis[node]=1;
    for(auto child:v[node]){
        if(!vis[child]){
            child_calculation(child);
            child_good[node] += good[child];
            child_bad[node] += bad[child];
        }
    }
}
int main(){
    IOS;
    ll T;
    cin>>T;
    while(T--){
        for(ll i=0;i<=n;i++){ 
            people[i]=total_people[i]=good[i]=bad[i]=child_bad[i]=child_good[i]=vis[i]=happiness[i]=0;        
            v[i].clear();
        }
        
        bool ok=1;
        cin>>n>>m;

        for(ll i=0;i<n;i++)
            cin>>people[i+1],total_people[i+1]=people[i+1];

        for(ll i=0;i<n;i++)
            cin>>happiness[i+1];

        for(ll i=0;i<n-1;i++){
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y),v[y].push_back(x);
        }

        total_population(1);
        for(ll i=0;i<=n;i++) vis[i]=0;

        for(ll i=1;i<=n;++i){
            good[i]=(total_people[i]+happiness[i])/2;
            bad[i]=(total_people[i]-happiness[i])/2;

            if(good[i]+bad[i]!=total_people[i]) ok=0;
            if(good[i]-bad[i] != happiness[i]) ok=0;

            if(good[i]<0 || good[i]>total_people[i]) ok=0;
            if(bad[i]<0 || bad[i]>total_people[i]) ok=0;  
        }

        child_calculation(1);

        for(ll i=1;i<=n;i++){
            if(good[i]<child_good[i]) ok=0;
        }

        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }    
}