#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
       IOS;
       ll T;
       cin>>T;
       while(T--){
               ll n;cin>>n;
               string s;
               cin>>s;
               ll pfx[n+2]={0};

                for(ll i=0;i<n;i++){
                        ll x=s[i]-'0';
                        pfx[i+1]=pfx[i]+x;
                }
                map<ll,vector<ll>> m;
                ll ans=0;
                for(ll i=1;i<=n;i++){
                        ll x=pfx[i]-i;
                        if(!x)ans++;
                        m[x].push_back(i);
                }
                for(ll i=1;i<=n;i++){
                        ll x=pfx[i]-i;
                        auto it=lower_bound(m[x].begin(),m[x].end(),i);
                        if(it!=m[x].begin()){
                                ll num=(--it)-m[x].begin()+1;
                                ans+=num;
                        }
                }
                cout<<ans<<"\n";
       }    
}