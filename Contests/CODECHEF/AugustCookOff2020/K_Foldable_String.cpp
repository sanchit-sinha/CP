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
                string s;
                cin>> s;
                ll start=0;
                ll rem=(n-start)/k;
                ll ct[2]={0};
                for(ll i=start;i<n;i++) ct[s[i]-'0']++;
                if(ct[0]%rem || ct[1]%rem) cout<<"IMPOSSIBLE\n";
                else{
                        ll zero=ct[0]/rem , one=ct[1]/rem;
                        bool flip=1;
                        for(ll i=start;i<n;i+=k){
                                zero=ct[0]/rem , one=ct[1]/rem;
                                if(flip){
                                        for(ll j=i;j<=i+k;j++){
                                                if(zero) s[j]='0',zero--;
                                                else s[j]='1',one--;
                                        }
                                }
                                else{
                                        for(ll j=i;j<=i+k;j++){
                                                if(one) s[j]='1',one--;
                                                else s[j]='0',zero--;
                                        }
                                }
                                flip=!flip;
                        }
                        cout <<s<<"\n";
                }
       }    
}