/**
 *    Author:  Sanchit Sinha
 *    Created: 17.10.2020 00:44:21       
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
                ll x,y;
                cin>>x>>y;
                if(y>x) swap(x,y);
                if(x>y+y) cout<<"NO\n";
                else{
                        if((y+x)%3==0) cout<<"YES\n";
                        else cout<<"NO\n";
                }
        }    
        return 0;
}