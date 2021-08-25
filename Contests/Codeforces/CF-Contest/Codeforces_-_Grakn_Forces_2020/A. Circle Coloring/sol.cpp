/**
 *    Author:  Sanchit Sinha
 *    Created: 30.09.2020 20:06:27       
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
                ll a[n],b[n],c[n];
                for(ll i=0;i<n;i++) cin>>a[i];
                for(ll i=0;i<n;i++) cin>>b[i];
                for(ll i=0;i<n;i++) cin>>c[i];
                cout << a[0]<<" ";
                ll prev = a[0];
                for(ll i=1;i<n-1;i++){
                        if(a[i] != prev){
                                cout<<a[i] <<" ";
                                prev = a[i];
                        } 
                        else if(b[i] != prev){
                                cout << b[i] <<" ";
                                prev = b[i];
                        }
                        else{
                                cout << c[i];
                                prev = c[i];
                        }
                }
                ll one = a[0];
                if(a[n-1] != one && a[n-1] != prev) cout<<a[n-1]<<" ";
                else if(b[n-1] != one && b[n-1] != prev) cout<<b[n-1]<<" ";
                else if(c[n-1] != one && c[n-1] != prev) cout<<c[n-1]<<" ";
                cout <<"\n";
        }    
        return 0;
}