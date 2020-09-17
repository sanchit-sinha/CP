#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
const ll N=1e5+11;
ll a[N],n,s,pfx[N];
pair<ll,ll> mx[N];
int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                for(ll i=0;i<n+1;i++) a[i]=pfx[i]=mx[i].first=mx[i].second=0;
                
                cin>>n>>s;
                for(ll i=0;i<n;i++) cin>>a[i+1];
                for(ll i=1;i<=n;i++){
                        pfx[i]=pfx[i-1]+a[i];
                }                
                for(ll i=1;i<=n;i++){
                        if(i==1) mx[i].first=a[i],mx[i].second=i;
                        else{
                                mx[i].first=max(mx[i-1].first,a[i]);
                                if(mx[i].first==a[i]) mx[i].second=i;
                                else mx[i].second=mx[i-1].second;
                        }
                }

                ll ans=0,index=0;
                for(ll i=1;i<=n;i++){
                        ll gifts=0;
                        // remove one till i
                        ll val=pfx[i],mxx=mx[i].first;
                        if(val<=s){
                                gifts=i;
                                ans=max(ans,gifts);
                                if(ans==gifts) index=0;
                        }
                        else{
                                val-=mxx;
                                if(val<=s) gifts=i-1;
                                ans=max(ans,gifts);
                                if(ans==gifts) index=mx[i].second;
                        }
                }

                cout << index<<"\n";
        }    
}