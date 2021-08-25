#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}


int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                ll n,q;
                cin>>n>>q;
                ll a[n];
                for(ll i=0;i<n;i++) cin>>a[i];
                vector<ll> v;
                v.push_back(a[0]);
                bool big=1;
                for(ll i=1;i<n;i++){
                        if(big){
                                if(big && a[i]<a[i-1]){
                                        v.push_back(a[i]);
                                        big=0;
                                }
                                else {
                                        v.pop_back();
                                        v.push_back(a[i]);
                                }
                        }
                        else{
                                if(!big && a[i]>a[i-1]){
                                        v.push_back(a[i]);
                                        big=1;
                                }
                                else{
                                        v.pop_back();
                                        v.push_back(a[i]);
                                }
                        }
                }
                ll len=(int)v.size();
                if(len-2>=0 && v[len-1]<v[len-2]) v.pop_back();
                len=(int)v.size();

                ll ans=0;
                for(ll i=0;i<len;i++){
                        if(i&1) ans-=v[i];
                        else ans+=v[i];
                }
                cout<<ans<<"\n";
        }    
}