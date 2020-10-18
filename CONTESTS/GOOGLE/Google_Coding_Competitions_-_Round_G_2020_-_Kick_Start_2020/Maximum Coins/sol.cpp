/**
 *    Author:  Sanchit Sinha
 *    Created: 18.10.2020 20:23:56       
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
        for(ll PTC=1;PTC<=T;PTC++){
                cout<<"Case #"<<PTC<<":"<<' ';
                ll n;;
                cin>>n;
                vector<vector<ll>>coins(n,vector<ll>(n,0));
                for(ll i=0;i<n;i++){
                        for(ll j=0;j<n;j++) cin>>coins[i][j];
                }
                ll ans=0;
                for(ll i=0;i<n;i++){
                        ll x=i,y=0;
                        ll val=0;
                        for(ll j=0;j<n;j++){
                                ll index1=i
                        }
                }                
        }    
}
