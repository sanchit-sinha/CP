/**
 *    Author:  Sanchit Sinha
 *    Created: 01.11.2020 17:00:00       
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
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll arr[4];
        arr[0]=d+b;
        arr[1]=d+c;
        arr[2]=a+b;
        arr[3]=a+c;
        sort(arr,arr+4);
        cout<<arr[2]<<"\n";
    }    
    return 0;
}