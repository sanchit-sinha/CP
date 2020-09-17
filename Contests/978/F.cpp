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
        ll n,k;
        cin>>n>>k;
        ll a[n],ans[n]={0};
        vector<ll> v;
        for(ll i=0;i<n;i++) cin>>a[i],v.push_back(a[i]);
        sort(v.begin() , v.end());
        for(ll i=0;i<k;i++){
                ll x,y;
                cin>>x>>y;
                x--,y--;
                if(a[x]<a[y]) ans[y]--;
                else if(a[y]<a[x]) ans[x]--;
        }
        for(ll i=0;i<n;i++){
                auto it=lower_bound(v.begin() , v.end() , a[i]);
                if(it != v.begin()){
                        it--;
                        ll num=(it - v.begin() + 1);
                        ans[i]+=num;
                }
                cout<<ans[i]<<" ";
        }
        cout<<"\n";
}
