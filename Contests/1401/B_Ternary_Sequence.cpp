#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
       IOS;
       ll T;
       cin>>T;
       while(T--){
               ll a0,a1,a2,b0,b1,b2;
               cin>>a0>>a1>>a2>>b0>>b1>>b2;
                ll ans=0;
                if(b1<=a2){
                        ans=2*b1;
                        a2-=b1,b1=0;
                        // 2 2 2 2 1 1  0 
                        //  2 2 0 0
                        if(b2<=a2+a0){
                                cout<<ans<<"\n";
                        }
                        else{
                                b2-=(a2+a0),a2=0,a0=0;
                                ans-=min(a1,b2)*2;
                                cout<<ans<<"\n";
                                // 1 11 1 
                                // 2 2  0 0
                        }
                }
                else{
                        ans=2*a2;
                        b1-=a2,a2=0;
                        // 1 1 1 0 0 
                        // 1 1 2 2 0 0 
                        if(a0>=b2){
                                a0-=b2,b2=0;
                                // 1 1 1 0 0 
                                // 1 1  0 
                                cout<<ans<<"\n";
                        }
                        else{
                                b2-=a0,a0=0;
                                // 1 1 1 1 
                                // 2 2 1 1 0 0
                                ans-=min(b2,a1)*2;
                                cout<<ans<<"\n";
                        }
                }
       }    
}