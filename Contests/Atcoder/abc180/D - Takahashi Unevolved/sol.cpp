/**
 *    Author:  Sanchit Sinha
 *    Created: 17.10.2020 16:38:47       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll unsigned long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll x,y,a,b;
        cin>>x>>y>>a>>b;
        ll ans=0;
        while(x<y){
                if(x>=y/a && x+a>=y) break;
                if(x>=y/a){
                        ll div=(y-1-x)/b;
                        ans+=max(div,0);
                        break; 
                }
                ll x1=x*a;
                ll x2=x+b;
                if(x1<=x2){
                        x*=a;
                        if(x<y)ans++;
                        else break;
                }
                else{
                        ll div=(y-1-x)/b;
                        ans+=max(div,0);
                        break;
                }
        }   
        cout<<ans<<"\n";
        return 0;       
}
