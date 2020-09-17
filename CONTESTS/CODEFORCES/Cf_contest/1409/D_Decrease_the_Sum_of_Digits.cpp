#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll unsigned long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

ll sum(ll x){
        ll s=0;
        while(x) s+=(x%10) ,  x/=10;
        return s;
}
int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                ll n,x;
                cin>>n>>x;
                /* >0 >0 >0 >0  0 0 0 0 0
                    _ _ _ _ _  _ _  _ _  _  */      
                if(sum(n)<=x) cout<<"0\n";
                else{
                        ll ans=0,p=1;
                        for(ll i=0;i<18;i++){
                                ll add=p*((10 - (n/p)%10)); 
                                n+=add;
                                ans+=add;
                                if(sum(n)<=x){
                                        break;
                                }
                                p*=10;
                        }
                        cout<<ans<<"\n";
                }
        }    
}