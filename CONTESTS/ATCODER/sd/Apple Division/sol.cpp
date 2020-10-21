/**
 *    Author:  Sanchit Sinha
 *    Created: 17.10.2020 01:04:18       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

ll bit(ll x,ll a[],ll n,ll sum1){
        ll bits[n]={0};
        ll index=0;
        while(x) bits[index++]=x%2,x/=2;
        ll sum2=0;
        for(ll i=0;i<n;i++) if(bits[i]) sum2+=a[i];
        sum1-=sum2;
        return abs(sum1-sum2);
}
int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll n;
        cin>>n;
        ll a[n];
        ll ans=LLONG_MAX,sum=0;
        for(ll i=0;i<n;i++) cin>>a[i],sum+=a[i];
        for(ll i=0;i<(1ll<<n);i++){
                ans=min(ans,bit(i,a,n,sum));
        }
        cout<<ans<<"\n";
        return 0;
}
