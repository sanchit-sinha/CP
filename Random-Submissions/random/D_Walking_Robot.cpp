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
        ll n,a,b;
        cin>>n>>b>>a;
        ll mx=a;
        ll x[n+1];
        for(ll i=0;i<n;i++) cin>>x[i+1];
        for(ll i=1;i<=n;i++){
                if(a==0 && b==0){
                        cout<<i-1<<"\n";
                        return 0;
                }
                if(x[i]){
                        if(b && a!=mx) b--,a++;
                        else a--;
                }
                else{
                        if(a) a--;
                        else b--;
                }
        }
        cout<<n<<"\n";
}
