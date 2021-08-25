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
        string s,t;
        cin>>s>>t;
        ll len1=(int)s.size() , len2=(int)t.size();
        ll ans=LLONG_MAX;
        for(ll i=0;i+len2-1<=len1-1;i++){
                ll change=0;
                for(ll j=0;j<len2;j++){
                        if(s[i+j] != t[j]) change++;
                }
                ans=min(ans,change);
        }
        cout<<ans<<"\n";
}
