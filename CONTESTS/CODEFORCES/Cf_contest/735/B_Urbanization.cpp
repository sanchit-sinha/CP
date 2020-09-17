#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}


int main(){
        IOS;
        cout<< fixed<<setprecision(20);
        ll n,n1,n2;
        cin>>n>>n1>>n2;
        ll price[n];
        for(ll i=0;i<n;i++) cin>>price[i];
        sort(price , price + n , greater<ll>());
        // n1<n2
        if(n1>n2)swap(n1,n2);         
        long double price1=0.0,price2=0.0;
        ll index=n1;
        for(ll i=0;i<index;i++) price1+=price[i];
        long double ans=price1/n1;
        for(ll i=index;i<index+n2;i++) price2+=price[i];
        ans+=(price2/n2);
        cout<<ans<<"\n";
}
