/**
 *    Author:  Sanchit Sinha
 *    Created: 20.10.2020 20:11:27       
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
                ll ans=0;
                vector<ll> one;
                for(ll i=0;i<n;i++) if(a[i]) one.push_back(i+1);
                ll len=(int)one.size();
                if(len<=1) cout<<"0\n";
                else{
                        ll ans=0;
                        for(ll i=1;i<len;i++) ans+=(one[i]-one[i-1]-1);
                        cout<<ans<<"\n";
                }
        }    
        return 0;
}