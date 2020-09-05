#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

ll mx(ll element,ll index ,ll d,ll n,ll y){
        if(index<0 || index>n) return LLONG_MAX;
        ll a[n]={0};
        a[index]=element;
        for(ll i=index-1;i>=0;i--) a[i]=a[i+1]-d;
        for(ll i=index+1;i<n;i++) a[i]=a[i-1]+d;
        bool ok=1;
        bool pres=0;
        for(ll i=0;i<n;i++){
                if(a[i]<=0) ok=0;
                if(a[i]==y) pres=1;
        }
        if(!ok || !pres) return LLONG_MAX;
        else{
                ll mxx=LLONG_MIN;
                for(ll i=0;i<n;i++) mxx=max(mxx,a[i]);
                return mxx;
        }
}
int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                ll n;
                cin>>n;
                ll a[n];
                ll x,y;
                cin>>x>>y;
                ll dif=(y-x);
                ll ans=LLONG_MAX;
                ll last_element=0;
                ll differnce=0;
                ll mn=LLONG_MAX;
                for(ll i=n-1;i>=1;i--){
                        if(dif%i==0){
                                ll d=(dif/i);
                                for(ll j=0;j<n;j++){
                                        // x at j
                                        ll index=j;
                                        ll xx=mx(x,j,d,n,y);
                                        ll yy=mx(x,j,-d,n,y);
                                        ans=min(ans,xx);
                                        if(ans==xx){
                                                differnce=d;
                                                last_element=x+(n-1-j)*d;
                                        }
                                        ans=min(ans,yy);
                                        if(ans==yy){
                                                differnce=-d;
                                                last_element=x-(n-1-j)*d;
                                        }
                                }
                        }
                }
                for(ll i=n-1;i>=0;i--){
                        if(i==n-1) a[i]=last_element;
                        else a[i]=a[i+1]-differnce;
                }
                for(ll i=0;i<n;i++) cout<<a[i]<<" ";
                cout<<"\n";
        }    
}