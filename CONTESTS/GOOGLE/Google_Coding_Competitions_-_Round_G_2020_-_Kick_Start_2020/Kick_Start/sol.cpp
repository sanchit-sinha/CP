/**
 *    Author:  Sanchit Sinha
 *    Created: 18.10.2020 20:15:03       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
bool check(string t,ll index,ll len1,string s,ll len2){
        bool ok=1;
        ll j=0;
        if(len1+index > len2) return 0;
        for(ll i=index;i<index+len1;i++){
                if(s[i]!=t[j++]){
                        ok=0;
                        return ok;
                }
        }
        return ok;
}
int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll T;
        cin>>T;
        for(ll PTC=1;PTC<=T;PTC++){
                cout<<"Case #"<<PTC<<":"<<' ';
                string s;
                cin>>s;
                ll kicks=0,starts=0;
                ll ans=0;
                ll n=(int)s.size();
                for(ll i=0;i<n;i++){
                        char c=s[i];
                        if(c=='K'){
                                if(check("KICK",i,4,s,n)) kicks++;
                        }
                        else if(c=='S'){
                                if(check("START",i,5,s,n)){
                                        starts++;
                                        ans+=kicks;
                                }

                        }
                }
                cout<<ans<<"\n";
        }    
}
