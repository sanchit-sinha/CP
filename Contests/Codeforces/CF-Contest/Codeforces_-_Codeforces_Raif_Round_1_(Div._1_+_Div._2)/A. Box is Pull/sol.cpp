/**
 *    Author:  Sanchit Sinha
 *    Created: 17.10.2020 18:39:46       
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
                ll x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                if(x1==x2 || y1==y2)  cout<<abs(x2-x1)+abs(y2-y1)<<"\n";
                else cout<<abs(x2-x1)+2+abs(y2-y1)<<"\n";
        }    
        return 0;
}