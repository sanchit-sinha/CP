/**
 *    Author:  Sanchit Sinha
 *    Created: 17.10.2020 18:58:25       
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
        ll T=1;
        while(T--){
                ll n;
                cin>>n ;
                string s;
                cin>>s;
                ll cwc=0,cc=0;
                for(ll i=0;i<n;i++){
                        if(s[i]=='>') cc++;
                        else if(s[i]=='<') cwc++;
                }

                if(cc==0||cwc==0) cout<<n<<"\n";
                else{
                        ll ans=0;
                        for(ll i=0;i<n;i++){
                                ll next=(i);
                                ll prev=(i-1+n)%n;
                                if(s[prev] == '-' || s[next]=='-'){
                                        // cout << i <<" " << prev<<" " << next<<"\n";
                                        // cout << i <<" : " << s[prev] <<" " << s[next]<<"\n\n";
                                        ans++;
                                }
                        }
                        cout<<ans<<"\n";
                }
        }    
        return 0;
}