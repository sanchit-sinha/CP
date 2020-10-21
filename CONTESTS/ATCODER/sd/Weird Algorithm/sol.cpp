/**
 *    Author:  Sanchit Sinha
 *    Created: 16.10.2020 22:11:12       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll n;
        cin>>n;
        cout << n <<" ";
        while(n!=1){
                if(n%2==0) n/=2;
                else n=3*n+1;
                cout<<n<<" ";
        }
        cout<<"\n";
        return 0;
}
