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
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll x,y,z,w;
        x=a*c;
        y=a*d;
        z=b*c;
        w=b*d;
        ll ans=LLONG_MIN;
        ans=max(ans , x);
        ans=max(ans , y);
        ans=max(ans , z);
        ans=max(ans , w);
        cout<<ans<<"\n";
}
