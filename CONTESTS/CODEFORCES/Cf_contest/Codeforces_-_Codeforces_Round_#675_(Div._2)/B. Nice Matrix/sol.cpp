/**
 *    Author:  Sanchit Sinha
 *    Created: 05.10.2020 00:00:53       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll T;
        cin>>T;
        while(T--){
                ll n,m;
                cin>>n>>m;
                ll a[n][m];
                for(ll i=0;i<n;i++)for(ll j=0;j<m;j++) cin>>a[i][j];
                ll ans=0;
                ll b[n][m];
                for(ll i=0;i<n;i++){
                        for(ll j=0;j<m;j++){
                                ll u=a[i][j],v=a[n-1-i][j],w=a[i][m-j-1],x=a[n-1-i][m-j-1];
                                ll arr[4] = {u,v,w,x};
                                sort(arr,arr+4);
                                
                                ll eq=arr[1];
                                a[i][j]=a[n-1-i][j]=a[i][m-1-j]=a[n-1-i][m-1-j]=eq;
                                ans += abs(u- eq)+abs(v-eq)+abs(w-eq)+abs(x-eq);
                        }
                }
                cout<<ans<<"\n";
        }    
        return 0;
}