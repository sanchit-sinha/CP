/**
 *    Author:  Sanchit Sinha
 *    Created: 17.10.2020 19:19:57       
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
                string s;
                cin>>s;
                ll sum=0,n=(int)(s.size()),ct=0;
                for(ll i=0;i<n;i++){
                        if(s[i]=='A') sum++;
                        else{
                                sum--;
                                if(sum<0){
                                        ct++;
                                        sum=0;
                                }
                        }
                }
                cout<<(ct&1) +max(sum,0)<<"\n";
        }    
        return 0;
}