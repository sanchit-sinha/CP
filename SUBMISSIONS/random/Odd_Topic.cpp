#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll int
int main(){
        IOS;    
        ll n,m,q;
        cin>>n>>m>>q;
        ll a[n+1],b[m+1];
        for(ll i=0;i<n;i++) cin>>a[i+1]; 
        for(ll i=0;i<m;i++) cin>>b[i+1]; 
        while(q--){
                ll l1,r1,l2,r2;
                cin>>l1>>r1>>l2>>r2;
                ll ct[4001]={0};
                for(ll i=l1;i<=r1;i++) ct[a[i]]++; 
                ll ans=0;
                for(ll i=l2;i<=r2;i++){
                        ct[b[i]]++;
                }
                for(ll i=0;i<4e3+1;i++) if(ct[i]&1)ans++;
                cout<<ans<<"\n";
        }
}