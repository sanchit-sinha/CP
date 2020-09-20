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
                ll n,x;
                cin>>n>>x;
                ll a[n];
                ll dif[n];
                ll ct=0;
                for(ll i=0;i<n;i++) cin>>a[i],dif[i]=x-a[i],ct+=(a[i]==x);
                ll sum=0;
                for(ll i=0;i<n;i++) sum+=dif[i];
                if(ct==n) cout<<"0\n";
                else{
                        if(sum==0){
                                cout<<"1\n";
                                continue;
                        }
                        bool ok=0;
                        for(ll i=0;i<n;i++){
                                if(a[i]==x) ok=1;
                        }
                        if(ok) cout<<"1\n";
                        else cout<<"2\n";
                }
        }    
}       