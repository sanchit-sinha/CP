/**
 *    Author:  Sanchit Sinha
 *    Created: 24.10.2020 17:34:17       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll N=1e6+11;
ll spf[N];
void sieve(){
    spf[0]=1;
    spf[1]=1;
    for(ll i=2;i<N;i++){
        if(spf[i]==0){
            for(ll j=i;j<N;j+=i){
                if(!spf[j]) spf[j]=i;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1;i<n;i++){
        ll x=n-i;
        ll y=1;
        while(x!=1){
            ll div=spf[x];
            ll ct=0;
            while(x%div==0)x/=div,ct++;
            y*=(ct+1);
        }
        ans+=y;
    }
    cout<<ans<<"\n";
    return 0;
}
