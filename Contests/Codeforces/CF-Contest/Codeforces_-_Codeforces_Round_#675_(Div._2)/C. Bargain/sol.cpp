/**
 *    Author:  Sanchit Sinha
 *    Created: 05.10.2020 12:35:39       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll mod=1e9+7;
int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        string s;
        cin>>s;
        ll n=(int)s.size();
        /* 
        0 1   2    3 4 5    : n=6
               n-i-1th position
          <--i-->    <-n-i-1-> 
        --- no.of times a number is occurring : 
                sigma(i=0->n-1)a[i] * [(ic2+i)*(10^(n-i-1)) + sigma(r=0->n-i-2)[r*(10^(r-1))] ] 
                                                                                */
        vector<ll> right(n+11,0);
        for(ll i=1;i<n+10;i++){
                ll val=(i*powermod(10,i-1,mod))%mod;
                right[i]=right[i-1]+val;
                right[i]%=mod;
        }

        ll ans=0;
        for(ll i=0;i<n;i++){
                ll x=s[i]-'0';
                if(x==0) continue;

                ll left=(i*(i+1))/2;left%=mod;
                left*=x;left%=mod;
                left*=powermod(10,n-i-1,mod);left%=mod;
                ans+=left;ans%=mod;

                ll rgt=(right[n-i-1]%mod);
                rgt*=x;rgt%=mod;
                ans += rgt;ans%=mod;

        }
        cout<<ans<<"\n";
        return 0;
}