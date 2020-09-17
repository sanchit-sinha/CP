#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
       IOS;
       ll T;
       cin>>T;
       while(T--){
               ll n,k;
               cin>>n>>k;
               ll a[n];
               for(ll i=0;i<n;i++) cin>>a[i];
               ll sum=0;ll ans=0;
               bool ok=1;
                for(ll i=0;i<n;i++){
                        if(sum+a[i]<=k) sum+=a[i];
                        else {
                                sum=a[i];
                                if(sum>k){
                                        ok=0;
                                        break;
                                }
                                else ans++;
                        }
                }
                if(!ok) cout<<-1<<"\n";
                else cout <<ans+1<<"\n";
       }    
}