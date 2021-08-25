/**
 *    Author:  Sanchit Sinha
 *    Created: 05.10.2020 12:19:52       
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
                vector<vector<ll>> a(n , vector<ll>(m,0));
                for(ll i=0;i<n;i++){
                        for(ll j=0;j<m;j++) cin>>a[i][j];
                }
                ll ans=0;
                for(ll i=0;i<n;i++){
                        for(ll j=0;j<m;j++){
                                ll arr[4]={a[i][j],a[n-1-i][j],a[i][m-1-j],a[n-1-i][m-1-j]};
                                sort(arr,arr+4);
                                ll eq=arr[1];
                                ll val=abs(a[i][j]-eq)+abs(a[n-1-i][j]-eq)+abs(a[i][m-j-1]-eq)+abs(a[n-1-i][m-j-1]-eq); 
                                a[i][j]=a[n-1-i][j]=a[i][m-j-1]=a[n-1-i][m-1-j]=eq;
                                if(i==n/2 || j==m/2) val/=2;                               
                                ans += val;
                        }
                }
                cout<<ans<<"\n";
        }       
        return 0;
}