/**
 *    Author:  Sanchit Sinha
 *    Created: 30.09.2020 22:40:22       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll n,m;
        cin>>n>>m;
        ll big_height[4111] = {0};
        ll rx[n],ry[n];
        ll sx[m],sy[m];
        for(ll i=0;i<n;i++) cin>>rx[i]>>ry[i];
        for(ll i=0;i<m;i++) cin>>sx[i]>>sy[i];
        for(ll i=0;i<=2000;i++){
                for(ll j=0;j<m;j++){
                        if(sy[j]>=i) big_height[i] = max(big_height[i] , sx[j]); 
                }
        }

        ll ans=LLONG_MAX;
        for(ll i=0;i<=2001;i++){
                ll ry_new[n];
                for(ll j=0;j<n;j++) ry_new[j] = ry[j]+i;
                ll val=0;
                for(ll j=0;j<n;j++){
                        val = max(val , big_height[ry_new[j]]);
                }
                ans = min(ans , val+i);
        }
        cout << ans<<"\n";
        return 0;
}
