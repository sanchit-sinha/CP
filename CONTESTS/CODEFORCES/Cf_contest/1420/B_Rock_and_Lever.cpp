#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}


int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                ll n;
                cin>>n;
                ll a[n];
                for(ll i=0;i<n;i++) cin>>a[i];
                map<ll,ll>m;
                for(ll i=0;i<n;i++){
                        for(ll j=31;j>=0;j--){
                                if(a[i]&(1ll<<j)){
                                        cout << a[i] << " " << j <<"\n";
                                        m[j]++;
                                        break;
                                }
                        }
                }
                ll ans=0;
                for(ll i=0;i<=31;i++) ans+=((m[i]*(m[i]-1))/2);
                cout<<ans<<"\n";
        }    
}