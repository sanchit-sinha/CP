#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll N=1e3+11;
ll a[N],n,w;
int main(){
        IOS;
        cin>>n>>w;
        for(ll i=0;i<n;i++) cin>>a[i];
        ll mn=LLONG_MAX,mx=LLONG_MIN;   
        ll cur=0;
        for(ll i=0;i<n;i++){
                cur+=a[i];
                mn=min(mn,cur);
                mx=max(mx,cur);
        }
        // cout << mx <<" " << mn<<"\n";
        ll start=0,last=w;
        if(mn<0){
                start=-mn;
        }
        if(mx<0){
                start=max(-mn , -mx);
        }
        start=max(0ll,start);
        last=min(w,w-mx);
        ll ans=last-start+1;
        // cout<<start <<" " << last<<"\n";
        if(mx>w || start>last || ans<0 || ans>w+1){
                cout<<"0\n";
                return 0;
        }
        cout<<ans<<"\n";
}       
