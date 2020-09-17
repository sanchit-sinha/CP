#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        ll a[]={6,10,14,15,21,22,26};
        if(n<=30) cout<<"NO\n";
        else {
            bool ok=0;
            for(ll i=0;i<7;i++){
                for(ll j=i+1;j<7;j++){
                    for(ll k=j+1;k<7;k++){
                        ll x=a[i],y=a[j],z=a[k];
                        ll rem= n-x-y-z;
                        if(rem>=0){
                            if(rem != x && rem != y && rem != z){
                                ok=1;
                                cout<<"YES\n";
                                cout<<x<<" "<<y<<" "<<z<<" "<<rem<<"\n";
                            }
                        }
                        if(ok) break;
                    }
                        if(ok) break;
                }
                        if(ok) break;
            }
            if(!ok) cout<<"NO\n";
        }
    }    
}