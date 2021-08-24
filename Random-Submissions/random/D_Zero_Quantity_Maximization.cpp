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
        cout<<fixed<<setprecision(20);
        ll n;
        map<pair< pair<ll,ll> ,pair<ll,ll> > ,ll>m;
        cin>>n;
        ll a[n],b[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>b[i];
        ll ct=0,ct1=0;
        for(ll i=0;i<n;i++){
                if(b[i]==0) ct1++;
               if(a[i]){
                       ll x=a[i],y=b[i];
                       bool neg1=0,neg2=0;
                       if(x<0) x=-x,neg1=1;
                       if(y<0) y=-y,neg2=1;
                       pair<ll,ll> p1,p2;
                       if(neg2 && !neg1) neg1=1,neg2=0;
                       if(neg1 && neg2) neg1=0,neg2=0;
                       p1.first=neg1;
                       p2.first=neg2;
                       ll g=gcd(x,y);
                       x/=g,y/=g;
                       p1.second=x,p2.second=y;
                       m[make_pair(p1,p2)]++;  
               }
                else{
                        if(b[i]==0) ct++;
                }
        }
        ll ans=0;
        for(auto it=m.begin() ;it!=m.end();it++) {
                ans=max(ans,it->second);
        }
        ans+=ct;
        cout<<max(ans,ct1)<<"\n";
}
