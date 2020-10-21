/**
 *    Author:  Sanchit Sinha
 *    Created: 16.10.2020 22:13:42       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        string s;
        cin>>s;
        ll n=(int)s.size();
        ll ans=0;
        for(ll i=0;i<n;i++){
                char c=s[i];
                ll len=0;
                while(i<n && s[i]==c) i++,len++;
                i--;
                ans=max(ans,len);
        }
        cout<<ans<<'\n';

        return 0;
}
