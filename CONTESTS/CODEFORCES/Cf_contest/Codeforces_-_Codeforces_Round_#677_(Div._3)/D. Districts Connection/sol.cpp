/**
 *    Author:  Sanchit Sinha
 *    Created: 20.10.2020 22:08:30       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll T;
        cin>>T;
        while(T--){
                ll n;
                cin>>n;
                ll a[n];
                for(ll i=0;i<n;i++) cin>>a[i];
                set<pair<ll,ll>> s;
                for(ll i=0;i<n;i++){
                        for(ll j=i+1;j<n;j++) if(a[i]!=a[j])s.insert({i,j});
                }
                ll len=(int)s.size();
                if(len==n-1){
                        cout<<"YES\n";
                        for(auto it=s.begin();it!=s.end();it++) cout<<it->first+1<<" " <<it->second+1<<"\n";
                }
                else cout<<"NO\n";
        }    
        return 0;
}