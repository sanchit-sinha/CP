/**
 *    Author:  Sanchit Sinha
 *    Created: 28.09.2020 14:56:15       
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
        ll a[n+1];
        for(ll i=0;i<n;i++) cin>>a[i+1];
        ll ans=0,sum=0;
        ll barrier = 0;
        map<ll,ll> m;
        m[0] = 0;
        for(ll i=1;i<=n;i++){
                sum+=a[i];
                auto it=m.find(sum);
                if(it == m.end()){
                        // insert
                        m[sum] = max(m[sum] , i);
                }
                else{
                        ll index=m[sum]+1;
                        // cout << index <<" : " << barrier <<" " << i <<"\n";
                        if(index>=barrier){
                                // cout << "taken\n\n";
                                ans++;
                                barrier=i;
                        }
                        m[sum] = max(m[sum] , i);
                }
        }
        cout<<ans<<"\n";

        return 0;
}
