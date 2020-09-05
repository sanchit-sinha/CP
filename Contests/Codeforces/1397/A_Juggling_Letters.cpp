#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}


int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                ll n;
                cin>>n;
                string s[n];
                ll sum=0;
                for(ll i =0;i<n;i++) cin>>s[i];
                ll ct[26]={0};
                for(ll i=0;i<n;i++){
                        ll len=(int)s[i].size();
                        sum+=len;
                        for(ll j=0;j<len;j++) ct[s[i][j]-'a']++; 
                }
                if(sum%n==0){
                        bool ok=1;
                        for(ll i=0;i<26;i++){
                                if(ct[i]%n) ok=0;
                        }
                        if(ok) cout<<"YES\n";
                        else cout<<"NO\n";
                }
                else cout<<"NO\n";
        }    
}