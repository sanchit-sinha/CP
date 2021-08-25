/**
 *    Author:  Sanchit Sinha
 *    Created: 28.09.2020 13:53:31       
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
                ll ans=0,mn=LLONG_MAX;
                for(ll i=1;i <= 1e5 ; i++){
                        ll first = i;
                        ll req = (n - 1 + first)/first;
                        mn = min(mn , first-1 + (req - 1));
                }
                cout << mn <<"\n";
        }    
        return 0;
}