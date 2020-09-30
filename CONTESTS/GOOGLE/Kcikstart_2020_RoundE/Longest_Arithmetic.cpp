#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
       IOS;
       ll T;
       cin>>T;
       ll index=1;
        while(T--){
               cout<<"Case #"<<index++<<":"<<' ';
               ll n;
               cin>>n;
               ll a[n];
               for(ll i=0;i<n;i++) cin>>a[i];
               ll dif[n-1];
               for(ll i=0;i<n-1;i++) dif[i]=a[i]-a[i+1];
        //        for(ll i=0;i<n-1;i++) cout << dif[i] <<" ";
        //        cout<<"\n";
                ll ans=0;
                for(ll i=0;i<n-1;i++){
                        ll ct=0;
                        ll x=dif[i];
                        while(i<n && dif[i]==x) i++,ct++;
                        ans=max(ans,ct);
                        i--;
                }
                cout<<ans+1<<"\n";
       }    
}