/**
 *    Author:  Sanchit Sinha
 *    Created: 21.10.2020 09:19:40       
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
                set<pair<ll,ll>>ans;
                int x=-1;
                for(ll i=0;i<n;i++){
                        if(a[i]!=a[0]){
                                ans.insert({0+1,i+1});
                                x=i;
                        }
                }
                if(x==-1){
                        cout<<"NO\n";
                        continue;
                }       
                for(ll i=1;i<n;i++){
                        if(a[i]==a[0]) ans.insert({x+1,i+1});
                }
                cout<<"YES\n";
                for(auto &x:ans) cout<<x.first<<" " <<x.second<<"\n";
        }       
        return 0;
}