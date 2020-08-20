#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
       IOS;
       ll T;
       cin>>T;
       while(T--){
                ll n;cin>>n;
                string s;
                cin>>s;
                bool eq=1;
                for(ll i=0;i<n;i++) if(s[i]!=s[0]) eq=0;
                if(eq){
                        cout<<(n+2)/3<<"\n";
                        continue;
                }
                s+=s;
                ll start=0,ans=0;
                for(ll i=0;i<n;i++){
                        if(s[i]!=s[0]){
                                start=i;
                                break;
                        }
                }
                char c=s[0];
                for(ll i=start;i<n+start;i++){
                        if(s[i]==c){
                                ll ct=0;
                                while(s[i]==c) ct++,i++;
                                i--;
                                ans+=ct/3;
                        }       
                        else{
                                ll ct=0;
                                while(i<n && s[i]!=c) ct++,i++;
                                i--;
                                ans+=(ct/3);
                        }
                }
                cout<<ans<<"\n";
       }    
}