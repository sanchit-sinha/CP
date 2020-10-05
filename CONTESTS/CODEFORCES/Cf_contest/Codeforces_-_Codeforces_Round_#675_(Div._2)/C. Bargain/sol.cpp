/**
 *    Author:  Sanchit Sinha
 *    Created: 04.10.2020 23:20:05       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll mod =1e9+7;
int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        string s;
        cin>>s;
        ll n=(int)s.size();
        ll ans=0;
        for(ll i=0;i<n;i++){
                for(ll j=i+1;j<n;j++){
                        ll num =0 ;
                        for(ll k=i;k<=j;k++){
                                ll x= s[k] -'0';
                                
                        }
                }
        }
        cout << ans<<"\n";
        return 0;
}
