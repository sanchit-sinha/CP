#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll int 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

const ll N=1e5+11;
vector<ll> v[N];
ll x[N],y[N],p[N],subtree_size[N],id[N];
set<ll> leaf;
ll n;
void dfs (ll node , ll parent){
        p[node] = parent;
        bool enter=0;
        for(auto child:v[node]){
                if(child!=parent){
                        enter=1;
                        dfs(child,node);
                        subtree_size[node]+=subtree_size[child];
                }
        }
        if(!enter) leaf.insert(node);
}
int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                //clear
                for(ll i=0;i<=n;i++){
                        x[i]=y[i]=subtree_size[i]=p[i]=id[i]= 0;
                        v[i].clear();
                }
                leaf.clear();
                cin>>n;
                for(ll i=1;i<=n;i++) subtree_size[i]=1;
                for(ll i=0;i<n-1;i++){
                        cin>>x[i] >> y[i];
                        v[x[i]].push_back(y[i]);
                        v[y[i]].push_back(x[i]);
                }
                dfs(1,0);
                // for(ll i=1;i<=n;i++){
                //         cout<<i<<" :  " << p[i] <<" " << subtree_size[i]<< " "  << "\n";
                // }
                // cout<<"\n";

                ll mn=INT_MAX;
                for(ll i=1;i<=n;i++){
                        ll len=(int)v[i].size();
                        ll mx=INT_MIN,sum=0;
                        auto it=leaf.find(i);
                        if(it == leaf.end()){
                                for(ll j=0;j<len;j++){
                                        if(v[i][j] != p[i]){
                                                ll val=subtree_size[v[i][j]];
                                                sum+=val;
                                                mx=max(mx , val);
                                        }
                                }
                                mx = max(mx , n-1-sum);
                        }
                        else mx=max(mx , n - 1);
                        id[i] = max(id[i] , mx);
                        mn=min(mn , mx);
                }
                // for(ll i=1;i<=n;i++) cout<<id[i]<<" ";
                // cout<<"\n";
                ll e1=0,e2=0;
                for(ll i=1;i<=n;i++){
                        if(id[i]==mn){
                                if(e1==0) e1=i;
                                else e2=i;
                        }
                }
                if(e1==0 || e2==0){
                        cout<<x[0] <<" " <<y[0]<<"\n";
                        cout<<x[0] <<" " <<y[0]<<"\n";
                }
                else{
                        ll other=-1;
                        for(ll i=0;i<(int)(v[e1].size());i++) if(v[e1][i] != e2) other=v[e1][i];
                        if(other == -1){
                                for(ll i=0;i<(int)(v[e2].size());i++) if(v[e2][i] != e1) other=v[e2][i];
                                cout << e2 <<" " << other<<"\n";
                                cout << e1 <<" " << other<<"\n";
                        }
                        else{
                                cout<< e1 <<" " << other<<"\n";
                                cout<< e2<<" " <<other<<"\n";
                        }
                }
        }    
}