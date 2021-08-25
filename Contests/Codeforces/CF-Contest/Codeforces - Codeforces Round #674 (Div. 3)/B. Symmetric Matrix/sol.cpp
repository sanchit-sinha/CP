/**
 *    Author:  Sanchit Sinha
 *    Created: 28.09.2020 13:46:49       
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
                ll n,m;
                cin>>n>>m;
                ll ul[n],ur[n],bl[n],br[n];
                for(ll i=0;i<n;i++){
                        cin>>ul[i]>>ur[i]>>bl[i]>>br[i];
                }
                if(m&1) cout<<"NO\n";
                else{
                        bool ok=0;
                        for(ll i=0;i<n;i++){
                                if(bl[i] == ur[i]) ok=1;
                        }
                        if(ok)  cout<<"YES\n";
                        else cout<<"NO\n";
                }
        }    
        return 0;
}