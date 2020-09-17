#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

const ll N=1e5+11,M=6e4+11,mod=1e9+7;
ll n,m;
ll x[N],y[N],lower_subtree[N],upper_subtree[N],dis[N];
vector<pair<ll,ll>> number_of_occurences;
vector<ll> v[N] , factor;
bool vis[N];

void dfs(ll node){
        vis[node]=1;
        lower_subtree[node]=1;
        for(auto child:v[node]){
                if(!vis[child]){
                        dis[child]=dis[node]+1;
                        dis[child]%=mod;

                        dfs(child);
                        
                        lower_subtree[node]+=lower_subtree[child];
                        lower_subtree[node]%=mod;                
                }
        }
}

int main(){
       IOS;
       ll T;
       cin>>T;
       while(T--){
                // clear
                for(ll i=0;i<=n;i++){
                        x[i]=y[i]=lower_subtree[i]=upper_subtree[i]=0;
                        v[i].clear();
                        vis[i]=dis[i]=0;
                        factor.clear();
                        number_of_occurences.clear();
                }

                cin>>n;
                for(ll i=0;i<n-1;i++){
                        cin>>x[i]>>y[i];
                        v[x[i]].push_back(y[i]);
                        v[y[i]].push_back(x[i]);
                }

                dfs(1);
       
                // for(ll i=1;i<=n;i++) cout<<i <<" " << lower_subtree[i] <<" "<<upper_subtree[i]<<" " << dis[i]<<"\n";
                // cout<<"\n";

                for(ll i=0;i<n-1;i++){
                        ll xx=x[i],yy=y[i];
                        if(dis[xx] > dis[yy]) swap(xx,yy);
                        ll below=lower_subtree[yy];
                        upper_subtree[xx] = n - lower_subtree[yy];
                        ll above= upper_subtree[xx];

                        ll p=(above*below)%mod;

                        // cout << i << " " << xx <<" : " << above<< " ; " << yy <<" : " <<below<< " : : " << p<<"\n";
                        number_of_occurences.push_back(make_pair(p,i));
                }

                sort(number_of_occurences.rbegin() , number_of_occurences.rend());

                cin>>m;
                for(ll i=0;i<m;i++){
                        ll x;cin>>x;
                        factor.push_back(x);
                }
                sort(factor.rbegin() , factor.rend());

                ll ans=0;
                if(m<=n-1){
                        for(ll i=0;i<n-1;i++){
                                if(i<m){
                                        ans+=(number_of_occurences[i].first * factor[i])%mod;
                                        ans%=mod;
                                }
                                else{
                                        ans+=(number_of_occurences[i].first);
                                        ans%=mod;
                                }
                        }
                }
                else{
                        /*
                                 m > n-1 
                                 m-n+2
                                                */
                        ll index=m-1;
                        for(ll i=n-2;i>0;i--){
                                ans+=(number_of_occurences[i].first * factor[index--]);
                                ans%=mod;
                        }
                        ll p=1;
                        for(ll i=index;i>=0;i--) p*=factor[i],p%=mod;
                        ans+=(number_of_occurences[0].first * p)%mod;
                        ans%=mod;
                }
                cout<<ans<<"\n";
       }    
}