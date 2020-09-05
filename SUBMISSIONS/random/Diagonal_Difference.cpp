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
        ll n;
        cin>>n;
        vector< vector<ll> > a(n,(vector<ll>(n,0)));
        for(ll i=0;i<n;i++){
                for(ll j=0;j<n;j++) cin>>a[i][j];
        }
        ll ans=0;
        ll x=0,y=0;
        for(ll i=0;i<n;i++){
                if(x<n && y<n) ans+=a[x++][y++];
        }
        x=n-1,y=0;
        for(ll i=0;i<n;i++){
                if(x>=0 && y<n) ans-=a[x--][y++];
        }
        ans=abs(ans);
        cout<<ans<<"\n";
}
