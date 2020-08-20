#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
        IOS;
        ll n;
        cin>> n;
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        ll ans=0;
        for(ll i=0;i<n;i++){
                for(ll j=i+1;j<n;j++){
                        for(ll k=j+1;k<n;k++){
                                ll x=a[i],y=a[j],z=a[k];
                                ll b[3]={x,y,z};
                                sort(b,b+3);
                                if(b[0]+b[1]>b[2] && b[0]!=b[1] && b[1]!=b[2]) {
                                        ans++;
                                }
                        }
                }
        }
        cout<<ans<<"\n";
}
