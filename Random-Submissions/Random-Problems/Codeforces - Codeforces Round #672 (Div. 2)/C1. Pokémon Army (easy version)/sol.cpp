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
                ll n,q;
                cin>>n>>q;
                ll A[n];
                for(ll i=0;i<n;i++) cin>>A[i];
                // mx[i] = mx value of sequence : a[i],a[i+1],a[i+2].....a[n-1]
                vector<ll> mx(n+1 , 0);
                // mn[i] = mn value of sequence : a[i],a[i+1],a[i+2].....a[n-1]
                vector<ll> mn(n+1 , 0);
                // a[0] - a[1] + a[2] - a[3] + .....
                // a[0] - (a[1] - a[2] + a[3] + .... )
                mx[n-1]=A[n-1] , mn[n-1]=0;
                for(ll i=n-2;i>=0;i--){
                        mx[i] = max(mx[i+1],A[i]-mn[i+1]);
                        mn[i] = min(mn[i+1],A[i]-mx[i+1]);
                }
                cout<<mx[0]<<"\n";
        }       
        return 0;
}