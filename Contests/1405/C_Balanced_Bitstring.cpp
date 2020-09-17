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
                ll n,k;
                cin>>n>>k;
                string s;
                cin>>s;
                bool ok=1;
                for(ll i=0;i<k;i++){
                        ll one=0,zero=0,other=0;
                        for(ll j=i;j<n;j+=k){
                                if(s[j]=='1') one++;
                                else if(s[j]=='0') zero++;
                                else other++;
                        }
                        if(one>0 && zero>0) ok=0;
                        else{
                                if(one){
                                        for(ll j=i;j<n;j+=k) s[j]='1';
                                }
                                else if(zero){
                                        for(ll j=i;j<n;j+=k) s[j]='0';
                                }
                        }
                }
                
                if(ok){
                        ll one=0,zero=0,other=0;
                        for(ll i=0;i<k;i++){
                                if(s[i]=='1') one++;
                                else if(s[i]=='0') zero++;
                                else other++;
                        }
                        for(ll i=0;i<k;i++){
                                if(s[i]=='?'){
                                        if(one<(k/2)) s[i]='1',one++;
                                        else s[i]='0',zero++;
                                }
                        }
                        if(zero != (k/2)  || one != (k/2)) ok=0;
                        if(ok){
                                for(ll i=0;i<k;i++){
                                        ll one=0,zero=0,other=0;
                                        for(ll j=i;j<n;j+=k){
                                                if(s[j]=='1') one++;
                                                else if(s[j]=='0') zero++;
                                                else other++;
                                        }
                                        if(one>0 && zero>0) ok=0;
                                        else{
                                                if(one){
                                                        for(ll j=i;j<n;j+=k) s[j]='1';
                                                }
                                                else if(zero){
                                                        for(ll j=i;j<n;j+=k) s[j]='0';
                                                }
                                        }
                                }
                                if(ok){
                                        ll ct[2]={0};
                                        for(ll i=0;i<k;i++) ct[s[i]-'0']++;
                                        if(ct[1] != ct[0]) ok=0;
                                        for(ll i=k;i<n;i++){
                                                ct[s[i-k] -'0']--;

                                                ct[s[i]-'0']++;
                                                if(ct[1] != ct[0]) ok=0;
                                        }
                                }
                        }
                }
                if(ok) cout<<"YES\n";
                else cout<<"NO\n";
        }    
}