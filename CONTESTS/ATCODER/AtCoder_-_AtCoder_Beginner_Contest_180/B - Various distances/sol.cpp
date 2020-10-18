/**
 *    Author:  Sanchit Sinha
 *    Created: 17.10.2020 16:30:57       
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
        cout<<fixed<<setprecision(20);
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
                cin>>a[i];
                if(a[i]<0) a[i]=-a[i];
        }
        ll ans1=0,ans3=0;
        long double ans2=0.0;
        for(ll i=0;i<n;i++){
                ans1+=a[i];
                ans2+=a[i]*a[i];
                ans3=max(ans3,a[i]);
        }
        long double x=sqrt(ans2);
        cout<<ans1<<"\n" <<x<<"\n"<<ans3<<"\n";
        return 0;
}
