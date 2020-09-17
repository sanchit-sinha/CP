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
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        if(n<=2) cout<<"0\n";
        else{
                ll ans=LLONG_MAX;
                for(ll i=-1;i<=1;i++){
                        for(ll j=-1;j<=1;j++){
                                ll cur_ans=0;
                                ll a0=a[0]+i,a1=a[1]+j;
                                ll dif=a1-a0;
                                bool ok=1;
                                for(ll k=2;k<n;k++){
                                        ll error=abs(a[k]-(a0+k*dif));
                                        if(error>1){
                                                ok=0;
                                                break;
                                        }
                                        else if(error==1){
                                                cur_ans++;
                                        }
                                        else continue;
                                }
                                if(ok) ans=min(ans,cur_ans+abs(i)+abs(j));
                        }
                }
                if(ans==LLONG_MAX)cout<<"-1\n";
                else cout<<ans<<"\n";
        }
}
