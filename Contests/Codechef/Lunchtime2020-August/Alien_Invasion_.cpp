#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
#define ld long double

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

const ll N=1e5+11;
ll n;
ld d;
ll a[N];
bool check(ld cdt){
        ld time=0;
       for(ll i=0;i<n;i++){
               if(i==0) time=a[0];
               else{
                       ld start_time=(ld)a[i];
                       if(start_time+d<time) return false;
                       else{
                               if(start_time > time) time=start_time;
                       }
               }
               time+=cdt;
       }
       return true;
}
int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                for(ll i=0;i<n;i++) a[i]=0.0;

                cout << fixed<<setprecision(10);
                cin>>n>>d;
                for(ll i=0;i<n;i++) cin>>a[i];
                sort(a,a+n);
                ld l=0,r=a[n-1]+d,mid=0,ans=0;
                for(ll i=0;i<100;i++){
                        mid=l+(r-l)/2;
                        // cout << l <<" " << mid << " " << r<<"\n";
                        if(check(mid)) l=mid,ans=mid;
                        else r=mid;
                }
                cout<<ans<<"\n";
        }    
}