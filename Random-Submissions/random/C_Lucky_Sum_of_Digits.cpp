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
        ll n;cin>>n;
        ll mn=LLONG_MAX;
        for(ll i=0;i<=1e6;i++){
                ll a=i;
                if((n-a*4)%7==0){
                        ll b=(n-a*4)/7;
                       if(b>=0) mn=min(mn,a+b);
                }
        }
        if(mn==LLONG_MAX) cout<<-1<<"\n";
        else{
                ll a=0,b=0;
                for(ll i=0;i<=1e6;i++){
                        if((n-4*i)%7==0){
                                if(i + (n-4*i)/7 == mn){
                                        a=i,b=(n-4*i)/7;
                                }
                        }
                }
                for(ll i=0;i<a;i++) cout<<4;
                for(ll i=0;i<b;i++) cout<<7;
                cout<<"\n";
        }
}
