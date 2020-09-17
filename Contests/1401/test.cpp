#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

const ll N=1e5+11,M=6e4+11,mod=1e9+7;
ll n,m,number_of_occurences[N];
vector<ll> v[N] , factor, edges;

void dfs(ll node,ll p){
        number_of_occurences[node]=1;
        for(auto child:v[node]){
                if(child!=p){
                        dfs(child,node);
                        number_of_occurences[node]+=number_of_occurences[child];
                        number_of_occurences[node]%=mod;
                }
        }
        ll pp=(number_of_occurences[node] * (n - number_of_occurences[node]))%mod;
         edges.push_back(pp);
}
int main(){
       IOS;
       ll T;
       cin>>T;
       while(T--){
                // clear
                for(ll i=0;i<=n;i++){
                        v[i].clear();
                        factor.clear();
                        edges.clear();
                        number_of_occurences[i]=0;
                }

                cin>>n;
                for(ll i=0;i<n-1;i++){
                        ll x,y;
                        cin>>x>>y;
                        v[x].push_back(y), v[y].push_back(x);
                }
                dfs(1,0);
                cin>>m;
                for(ll i=0;i<m;i++){
                        ll x;
                        cin>>x;
                        factor.push_back(x);
                }
                sort(factor.rbegin() , factor.rend());
                sort(edges.rbegin() , edges.rend());
                ll ans=0;
                if(m<=n-1){
                        for(ll i=0;i<n-1;i++){
                                ll p=edges[i]%mod;
                                if(i<m){
                                        p*=factor[i];
                                        p%=mod;
                                }
                                ans+=p;
                                ans%=mod;
                        }
                }
                else{
                        ll index=m-1;
                        for(ll i=n-2;i>0;i--){
                                ll p=edges[i]%mod;
                                p*=factor[index--];p%=mod;
                                ans+=p; ans%=mod;
                        }
                        ll p=1;
                        for(ll i=index;i>=0;i--) p*=factor[i] , p%=mod;
                        p*=edges[0];p%=mod;
                        ans+=p;ans%=mod;
                }
                cout<<ans<<"\n";

       }    
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}