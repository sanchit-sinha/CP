#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

// Credits: https://codeforces.com/blog/entry/82050?#comment-689223
int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                ll n;
                cin>>n;
                ll a[n],sum=0,mx=LLONG_MIN;
                for(ll i=0;i<n;i++) cin>>a[i],sum+=a[i],mx=max(mx,a[i]);
                if(mx>sum-mx) cout<<"T\n";
                else{
                        if(sum%2==0) cout<<"HL\n";
                        else cout<<"T\n";
                }
        }    
}