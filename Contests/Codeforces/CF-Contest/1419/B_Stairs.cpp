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
                ll x=1;
                ll ans=0;
                ll index=1;
                while(n>0){
                        ll val=(x*(x+1))/2;
                        if(n>=val)ans++;
                        x+=(1ll<<index);
                        index++;
                        n-=val;
                }
                cout<<ans<<"\n";
        }    
}