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
                ll n;
                cin>>n;
                map<ll , ll > m;
                ll a[n];
                for(ll i=0;i<n;i++) cin>>a[i],m[a[i]]++;
                sort(a,a+n);
                set<ll> s;
                for(ll i=0;i<n;i++) s.insert(a[i]);
                ll x=0,y=0;
                ll index=0;
                for(auto it =s.begin() ; it!=s.end();it++){
                        if(*it != index){
                                break;
                        }
                        else x=++index;
                }
                y=x;
                for(ll i=0;i<n;i++){
                        if(a[i]<=x){
                                if(m[a[i]]>1){
                                        continue;
                                }
                                else{
                                        y=a[i];
                                        break;
                                }
                        }
                }
                cout<<x+y<<"\n";
        }       
}