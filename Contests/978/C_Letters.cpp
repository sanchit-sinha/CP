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
        ll n,m;
        cin>>n>>m;
        ll a[n],b[m];
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<m;i++) cin>>b[i];
        ll pfx[n]={0};
        vector<ll> v;
        for(ll i=0;i<n;i++){
                if(i==0) pfx[i]=a[i];
                else pfx[i]=pfx[i-1]+a[i];
                v.push_back(pfx[i]);        
        }
        for(ll i=0;i<m;i++){
                ll room=b[i];
                auto it=lower_bound(v.begin() , v.end() , room);
                if(it != v.begin()){
                        it--;
                        ll val=*it;
                        ll index=it-v.begin()+1;
                        cout<<index+1<<" "<<room-val<<"\n";
                }
                else cout<<1<<" "<<room<<"\n";
        }
}
