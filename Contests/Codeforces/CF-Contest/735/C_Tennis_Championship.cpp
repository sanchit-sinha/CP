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
        if(n==2) cout<<"1\n";
        else if(n==3) cout<<"2\n";
        else{
                ll a=1,b=1;
                ll ans=0;
                while(b<=n){
                        ll temp=b;
                        b=a+b;
                        a=temp;
                        ans++;
                }
                cout<<ans-1<<"\n";
        }
}
