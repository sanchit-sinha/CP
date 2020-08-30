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
                map<ll,ll> m;
                for(ll i=0;i<n;i++){
                        ll x;
                        cin>>x;
                        m[x]++;
                }
                vector<ll> cnt;
                for(auto it=m.begin() ;it!=m.end() ; it++){
                        cnt.push_back(it->second);
                }
                sort(cnt.begin() , cnt.end() , greater<ll>());
                ll len=(int)cnt.size();
                ll ans=cnt[0];
                ll previous=cnt[0];
                for(ll i=1;i<len;i++){
                        if(previous <= 0) break;
                        if(cnt[i]<previous) ans+=cnt[i];
                        else ans+=previous-1;
                        previous--;
                        previous=min(previous , cnt[i]);                
                }
                cout<<ans<<"\n";
        }    
}