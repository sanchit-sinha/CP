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
               string s,t;
               cin>>s>>t;
               ll n=(int)s.size();
                bool ok=0;
                for(ll i=0;i<n;i++){
                        for(ll j=0;j<n;j++) {
                                if(s[i]==t[j]) ok=1;
                        }
                }
                if(ok) cout<<"YES\n";
                else cout<<"NO\n";
       }    
}