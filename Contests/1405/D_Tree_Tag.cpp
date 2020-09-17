#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

const ll N=1e5+11;
ll n,a,b,da,db;
vector<ll> v[N];
ll dis_from_a[N],dis_from_b[N];
void dfsa(ll node , ll p){
        for(auto child:v[node]){
                if(child != p){
                        dis_from_a[child]=dis_from_a[node]+1;
                        dfsa(child , node);
                }
        }
}
void dfsb(ll node ,ll p){
        for(auto child:v[node]){
                if(child != p){
                        dis_from_b[child] = dis_from_b[node]+1;
                        dfsb(child , node);
                }
        }
}
int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                //clear
                for(ll i=0;i<=n;i++){
                        v[i].clear();
                        dis_from_b[i]=dis_from_a[i]=0;
                }
               
                cin>>n>>a>>b>>da>>db;
                for(ll i=0;i<n-1;i++){
                        ll x,y;
                        cin>>x>>y;
                        v[x].push_back(y);
                        v[y].push_back(x);
                }
                dfsa(a,0);
                dfsb(b,0);
                ll dis_to_b=dis_from_a[b];
                ll dis_to_a=dis_from_b[a];
                if(dis_to_b <= da) cout<<"Alice\n";
                else{
                        if(db>2*da){
                                bool pres=0;
                                for(ll i=1;i<=n;i++){
                                        if(dis_from_b[i] > 2*da) pres=1;
                                }
                                if(pres) cout<<"Bob\n";
                                else{
                                        bool got=0;
                                        ll node1=0;
                                        ll mx=LLONG_MIN;
                                        for(ll i=1;i<=n;i++){
                                                mx=max(mx , dis_from_b[i]);
                                                if(mx == dis_from_b[i]) node1=i;
                                                dis_from_b[i]=0;
                                        }
                                        dfsb(node1,0);
                                        mx=LLONG_MIN;
                                        ll node2=0;
                                        for(ll i=1;i<=n;i++){
                                                mx=max(mx , dis_from_b[i]);
                                                if(mx == dis_from_b[i]) node2=i;
                                        }
                                        // node1 , node2 are the ends of diameter
                                        if(dis_from_a[node2] > 2*da || dis_from_a[node1] > 2*da) got=1;
                                        if(got) cout<<"Bob\n";
                                        else cout<<"Alice\n";
                                }
                        }
                        else cout<<"Alice\n";
                }
        }    
}