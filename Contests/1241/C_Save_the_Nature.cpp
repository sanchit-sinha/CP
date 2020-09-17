#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

const ll N=2e5+1;
ll n,p[N],x,a,y,b,k;
bool check(ll mid,ll x,ll a,ll y,ll b){
        // last index=mid-1;
        ll end=mid-1;
        if(y>x) {
                swap(x,y);
                swap(a,b);
        }
        ll l=0,sum=0;
        for(ll i=b;i<=mid;i+=b){
                ll index=i-1;
                if(i%a==0 && i%b==0) sum+=(p[l++]/100)*(x+y) ;
        }

        for(ll i=a;i<=mid;i+=a){
                ll index=i-1;
                if(i%a==0 && i%b==0) continue;
                else if(i%a==0) sum+=(p[l++]/100)*x;
        }

        for(ll i=b;i<=mid;i+=b){
                ll index=i-1;
                if(i%a==0 && i%b==0) continue;
                else if(i%b==0) sum+=(p[l++]/100)*y;
        }

        if(sum>=k) return true;
        else return false;
}
int main(){
       IOS;
       ll T;
       cin>>T;
       while(T--){
               // clear
               for(ll i=0;i<n;i++) p[i]=0;

               cin>>n;
               for(ll i=0;i<n;i++) cin>>p[i];
                cin>>x>>a>>y>>b>>k;
               sort(p,p+n,greater<ll>());
               ll l=1,r=n,mid=0,ans=-1;
                while(l<=r){
                        mid=l+(r-l)/2;
                        // >=k
                        if(check(mid,x,a,y,b)) r=mid-1,ans=mid;
                        else l=mid+1; 
                }
               cout<<ans<<"\n";
       }    
}