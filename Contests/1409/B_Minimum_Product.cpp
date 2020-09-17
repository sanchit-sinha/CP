#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

ll solve(ll a,ll x,ll b,ll y,ll n){
        ll m1=(a-x),m2=(b-y);
        ll p=1;
        a-=min(m1,n);
        n-=min(n,m1);
        b-=min(m2,n);
        return a*b;
}
int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                ll a,b,x,y,n;
                cin>>a>>b>>x>>y>>n;
                cout<<min(solve(a,x,b,y,n),solve(b,y,a,x,n))<<"\n";
        }    
}