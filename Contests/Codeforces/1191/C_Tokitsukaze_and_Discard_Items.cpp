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
        ll n,m,k;
        cin>>n>>m>>k;
        ll a[m];
        for(ll i=0;i<m;i++) cin>>a[i];
        sort(a,a+m);
        ll last_index=k;
        ll ans=0;

        for(ll i=0;i<m;i++){
                if(a[i]<=last_index){
                        ll ct=0;
                        while(i<m && a[i]<=last_index) ct++,i++;
                        i--; 
                        ans++;
                        last_index+=ct;
                        last_index=min(last_index , n);
                }
                else{
                        ll dif=a[i]-last_index;
                        ll div=(dif-1+k)/k;
                        last_index+=div*k;
                        last_index=min(last_index , n);
                        ll ct=0;
                        while(i<m && a[i]<=last_index)ct++,i++;
                        i--;
                        ans++;
                        last_index+=ct;
                        last_index=min(last_index , n);
                }
        }
        cout<<ans<<"\n";
}
