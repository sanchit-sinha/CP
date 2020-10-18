/**
 *    Author:  Sanchit Sinha
 *    Created: 17.10.2020 17:54:25       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
const ll N=20;
ll n,x[N],y[N],z[N],dis[N][N];
vector<pair<ll ,pair<ll,ll> > >v;
ll sz[N] , parent[N];
void make_set(ll node){
        parent[node] = node;
        sz[node] = 1;
}
ll find_set(ll a){
        if(a==parent[a]) return a;
        return parent[a]=find_set(parent[a]);
}
void union_set(ll a , ll b){
        ll p1=find_set(a);
        ll p2=find_set(b);
        if(p1!=p2){
                if(sz[p2]>sz[p1]) swap(p1,p2);
                parent[p2]=p1;
                sz[p1]+=sz[p2];
                sz[p2]=0;
        }
}
ll kruskal(){
        ll cost=0;
        sort(v.begin() , v.end());
        ll n=(int)v.size();
        for(ll i=0;i<n;i++){
                ll weight=v[i].first;
                ll u=v[i].second.first;
                ll v1=v[i].second.second;
                if(find_set(u) != find_set(v1)){
                        cost+=weight;
                        union_set(u,v1);
                }
        }
        return cost;
}


vector<pair<ll,ll>> v1[N];
ll dist[N];
// node > 1
void dij(ll node){
        set<pair<ll,ll>> s;
        for(ll i=2;i<=n;i++){
                dist[i]=LLONG_MAX;
                s.insert(make_pair(dist[i],i));
        }
        s.insert(make_pair(0,1));
        dist[1]=0;
        while(!s.empty()){
                ll from=s.begin()->second;
                s.erase(s.begin());
                for(auto child:v1[from]){
                        ll len=child.second;
                        ll to=child.first;
                        if(dist[from]+len < dist[to]){
                                s.erase(make_pair(dist[to],to));
                                dist[to]=dist[from]+len;
                                s.insert({dist[to] , to});
                        }
                }
        }
}
int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin>>n;
        for(ll i=1;i<=n;i++) make_set(i);
        for(ll i=1;i<=n;i++){   
                cin>>x[i]>>y[i]>>z[i];
        }
        for(ll i=1;i<=n;i++){
                for(ll j=1;j<=n;j++){
                        ll dist=abs(x[i]-x[j])+abs(y[i]-y[j])+max(0,z[i]-z[j]);
                        v.push_back(make_pair(dist,make_pair(i,j)));
                        dis[i][j]=dist;

                        v1[i].push_back(make_pair(j,dis[i][j]));
                        v1[j].push_back(make_pair(i,dis[i][j]));
                }
        }
        
        ll ans1=kruskal();
        // for(ll k=1;k<=n;k++){
        //         for(ll i=1;i<=n;i++){
        //                 for(ll j=1;j<=n;j++){
        //                         if (dis[i][k] + dis[k][j] < dis[i][j]) dis[i][j] = dis[i][k] + dis[k][j];
        //                 }
        //         }
        // }
        // ll ans2=LLONG_MAX;
        // for(ll i=2;i<=n;i++) ans2=min(ans2,dis[1][i]);

        ll ans2=0;
        for(ll i=2;i<=n;i++) ans2=min(ans2,dist[i]);
        cout << ans1+ans2<<"\n";
        return 0;
}
