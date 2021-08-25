#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long
int main(){
       IOS;
       ll T;
       cin>>T;
       while(T--){
                string s;
                ll x,n;
                cin>>s>>x;
                n=(int)s.size();
                vector<char> w(n+1,'?');
                bool ok=1;
                for(ll i=0;i<n;i++){
                        if(s[i]=='0'){
                                ll index1=i-x;
                                ll index2=i+x;
                                if(index1>=0){
                                        w[index1]='0';
                                }
                                if(index2<n){
                                        w[index2]='0';
                                }
                        }
                }          
                for(ll i=0;i<n;i++){
                        if(s[i]=='1'){
                                ll index1=i-x;
                                ll index2=i+x;
                                if(index1>=0){
                                        // go to 1
                                        if(w[index1]!='0') {
                                                w[index1]='1';
                                        }
                                        else{
                                                // go to 2
                                                if(index2<n){
                                                        if(w[index2]=='0') ok=0;
                                                        else{
                                                                w[index2]='1';
                                                        }
                                                }
                                                else ok=0;
                                        }
                                }
                                else{
                                        // go to 2
                                        if(index2>=n) ok=0;
                                        else{
                                                if(w[index2]=='0') ok=0;
                                                else{
                                                        w[index2]='1';
                                                }
                                        }
                                }
                        }
                }     
                if(!ok) cout<<-1<<"\n";
                else{
                        for(ll i=0;i<n;i++){
                                if(w[i]=='?') w[i]='1';
                        }
                        for(ll i=0;i<n;i++) cout<<w[i];
                        cout<<"\n";
                }
       }    
}