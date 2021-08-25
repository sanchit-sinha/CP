/**
 *    author:  Sanchit Sinha
 *    created: 27.09.2020 13:32:25       
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
                ll ans=0;
                bool turn=1;
                while(n>0){
                        if(n&1){
                                n--;
                                if(turn) ans++;
                        }
                        else{
                                if(turn){
                                        if(n!=4 && n%4==0){
                                                ans++;
                                                n--;
                                        }
                                        else{
                                                ans+=(n/2);
                                                n/=2;
                                        }
                                }
                                else{
                                        if(n!=4 && n%4==0) n--;
                                        else n/=2;
                                }
                        }
                        turn =!turn;
                }
                cout<<ans<<"\n";
        }    
        return 0;
}