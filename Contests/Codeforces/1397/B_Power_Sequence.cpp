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
        cin >> n;
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        ll ans=LLONG_MAX;
        bool ok=1;
        ll mx=LLONG_MAX;
        for(ll i=1;i<=1e6+4;i++){
                ll p=1;
                ll val=0;
                for(ll j=0;j<n;j++){
                       if(j==0) val+=abs(a[j]-p);
                        else{
                                if(p >= LLONG_MAX/i){
                                        ok=0;
                                        break;
                                }
                                else {
                                        p*=i;
                                        val+=(abs(a[j]-p));
                                }
                        }
                }
                // cout << i <<"  " << val<<"\n";
                if(!ok) break;
                else ans=min(ans,val);
        }
        cout<<ans<<"\n";
}
