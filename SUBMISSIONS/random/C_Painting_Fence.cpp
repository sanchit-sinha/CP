#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll N=5e3+11;
ll a[N],n;

ll solve(ll l,ll r,ll ht){
        if(l>r || l<0 || r<0) return 0;
        ll mn=LLONG_MAX;
        for(ll i=l;i<=r;i++) mn=min(mn,a[i]-ht);
        ll index=-1;
        ll height=mn+ht;
        for(ll i=l;i<=r;i++){
                if(a[i]==height && index==-1){
                        index=i;
                        break;
                }
        }
        return min(r-l+1,solve(l,index-1,height)+solve(index+1,r,height)+mn);
}
int main(){
        IOS;
        cin>>n;
        for(ll i=0;i<n;i++) cin>>a[i];
        cout<<solve(0,n-1,0)<<"\n";
}
