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
        sort(a,a+n,greater<ll>());
        vector<ll>v(n,-1);
        ll index=0;
        ll done=-1;
        for(ll i=0;i<n;i++){
                ll j=index;
                if(j<n){
                        v[j]=a[i];
                        index+=2;
                        done=i;
                }
                else break;
        }
        index=1;
        for(ll i=done+1;i<n;i++){
                v[index]=a[i];
                index+=2;
                if(index>=n) break;
        }
        ll ans=0;
        for(ll i=1;i<n-1;i++){
                if(v[i]<v[i-1] && v[i]<v[i+1]) ans++;
        }
        cout<<ans<<"\n";
        for(ll i=0;i<n;i++) cout<<v[i] <<" ";
        cout<<"\n";
}
