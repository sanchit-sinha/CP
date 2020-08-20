#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

const ll mod=998244353 ;
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

int main(){
        IOS;
        ll n;
        cin>>n;
        map<ll,vector<ll>> kid;
        map<ll,ll> item;

        for(ll i=1;i<=n;i++){
                ll k;
                cin>>k;
                for(ll j=0;j<k;j++){
                        ll x;
                        cin>>x;
                        kid[i].push_back(x);
                        item[x]++;
                }
        }

        ll ans=0;
        for(ll i=1;i<=n;i++){
                ll len=(int)(kid[i].size());
                for(auto itm:kid[i]){
                        ll p=1;
                        ll x=itm;
                        
                        ll above =1,lower=1;
                        lower*=n;
                        lower%=mod;
                        lower*=n;
                        lower%=mod;
                        lower*=len;
                        lower%=mod;

                        above*=item[x];
                        above%=mod;
                        
                        p*=above;
                        p%=mod;
                        p*=powermod(lower,mod-2,mod);
                        p%=mod;

                        ans+=p;
                        ans%=mod;
                }
        }
        cout << ans<<"\n";
}
