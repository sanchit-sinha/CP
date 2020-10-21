/**
 *    Author:  Sanchit Sinha
 *    Created: 16.10.2020 22:23:24       
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
                if(max(x,y)%2==0){
                        ll sq=max(x,y)*max(x,y);
                        if(x>y) cout<<sq-(y-1)<<"\n";
                        else cout<<sq-(y-1)-(y-x)<<"\n";
                }
                else{
                        swap(x,y);
                        ll sq=max(x,y)*max(x,y);
                        if(x>y) cout<<sq-(y-1)<<"\n";
                        else cout<<sq-(y-1)-(y-x)<<"\n";
                }
        }    
        return 0;
}