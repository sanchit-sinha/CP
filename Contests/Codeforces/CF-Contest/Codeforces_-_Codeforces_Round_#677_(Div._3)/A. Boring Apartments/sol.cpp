/**
 *    Author:  Sanchit Sinha
 *    Created: 20.10.2020 20:07:26       
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
                ll n;
                cin>>n;
                ll a=n%10;
                ll ans = (a-1)*10;
                ll ct=0;
                while(n){
                        ct++;
                        n/=10;
                }
                if(ct==1) cout<<ans+1<<"\n";
                else if(ct==2) cout<<ans+3<<"\n";
                else if(ct==3) cout<<ans+6<<"\n";
                else cout<<ans+10<<"\n";
        }    
        return 0;
}