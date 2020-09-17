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
                ll one=0;
                for(ll i=0;i<n;i++) cin>>a[i] , one+=(a[i]==1);
                if(one>n/2){
                        if(one&1) one--;
                        cout<<one<<"\n";
                        for(ll i=0;i<one;i++) cout<<"1 ";
                        cout<<"\n";
                }
                else{
                        cout<<n-one<<"\n";
                        for(ll i=0;i<n-one;i++) cout<<"0 ";
                        cout<<"\n";
                }
        }    
}