#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}


int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                ll n;
                cin>>n;
                ll a[n];
                map<ll,ll> m1,m2;
                for(ll i=0;i<n;i++){
                        cin>>a[i];
                        m1[a[i]]++;
                }
                ll ans=LLONG_MAX;
                for(auto it=m1.begin();it!=m1.end();it++) m2[it->second]++;
                ll mx=LLONG_MIN;
                for(auto it=m2.begin();it!=m2.end();it++){
                        mx=max(mx,it->second);
                }
                for(auto it=m2.begin();it!=m2.end();it++){
                        if(it->second == mx) ans=min(ans,it->first);
                }
                cout<<ans<<'\n';
        }    
}