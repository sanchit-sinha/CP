/**
 *    Author:  Sanchit Sinha
 *    Created: 27.09.2020 21:28:56       
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
                map<ll,vector<ll>> pos;
                vector<ll> ans(n+1 , LLONG_MAX);
                for(ll i=0;i<n;i++) cin>>a[i] , pos[a[i]].push_back(i);
                for(auto it=pos.begin() ; it!=pos.end() ; it++){
                        ll x=it->first;
                        vector<ll> v = it->second;
                        ll len=(int)v.size();
                        ll prev=-1,index=0;
                        for(ll i=0;i<len;i++){
                                index=max(index , v[i] - prev );
                                prev=v[i];
                        }
                        index = max(index , n - prev);

                        ans[index-1] = min(ans[index-1] , x);
                }
                for(ll i=0;i<n;i++) {
                        if(i==0){
                                if(ans[i]==LLONG_MAX) ans[i] = -1;
                        }
                        else{
                                if(ans[i]==LLONG_MAX) ans[i] = ans[i-1];
                                else{
                                        if(ans[i-1] != -1) ans[i] = min(ans[i] , ans[i-1]);
                                }
                        }
                }
                for(ll i=0;i<n;i++) cout<<ans[i] <<" ";
                cout<<"\n";
        }    
        return 0;
}