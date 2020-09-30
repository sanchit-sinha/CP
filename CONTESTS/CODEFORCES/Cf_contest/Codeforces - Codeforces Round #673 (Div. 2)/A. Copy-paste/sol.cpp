/**
 *    Author:  Sanchit Sinha
 *    Created: 27.09.2020 20:37:41       
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
                ll n,k;
                cin>>n>>k;
                ll a[n];
                for(ll i=0;i<n;i++) cin>>a[i];
                bool ok=1;
                for(ll i=0;i<n;i++) if(a[i]>k) ok=0;
                if(ok){
                        ll ans=0;
                        sort(a,a+n);
                        for(ll i=1;i<n;i++){
                                ll x=k-a[i];
                                ans += (x/a[0]);
                        }
                        cout << ans<<"\n";
                }
                else cout<<"0\n";
        }    
        return 0;
}