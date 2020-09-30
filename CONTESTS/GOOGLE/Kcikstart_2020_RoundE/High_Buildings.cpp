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
               ll n,a,b,c;
               cin>>n>>a>>b>>c;
               a-=c,b-=c;
               vector<ll> v;
               // 1 1 2 2 1 1 
                for(ll i=0;i<a;i++) v.push_back(n-1);
                for(ll i=0;i<c;i++) v.push_back(n);
                for(ll i=0;i<b;i++) v.push_back(n-1);
                ll len=(int)v.size();

                bool ok=1;
                for(ll i=0;i<(int)v.size();i++) {
                        if(v[i]<1 || v[i]>n) ok=0;
                }
                if(!ok) cout<<"IMPOSSIBLE\n";
                else{
                        if(len > n) cout<<"IMPOSSIBLE\n";
                        else if(len==n){
                                for(ll i=0;i<len;i++) cout<<v[i] <<" ";
                                cout<<"\n";
                        }
                        else{
                                ll rem=n-len;
                                bool ok=1;
                                v.clear();
                                if(b!=0){
                                        for(ll i=0;i<a;i++) v.push_back(n-1);
                                        for(ll i=0;i<c;i++) v.push_back(n);
                                        for(ll i=0;i<rem;i++) v.push_back(n-2);
                                        for(ll i=0;i<b;i++) v.push_back(n-1);
                                }
                                else if(a!=0 && b==0){
                                        for(ll i=0;i<a;i++) v.push_back(n-1);
                                        for(ll i=0;i<rem;i++) v.push_back(n-2);
                                        for(ll i=0;i<c;i++) v.push_back(n);
                                        for(ll i=0;i<b;i++) v.push_back(n-1);
                                }
                                else if(a==0 && b==0){
                                        if(c==1) ok=0;
                                        else{
                                        for(ll i=0;i<1;i++) v.push_back(n);
                                        for(ll i=0;i<rem;i++) v.push_back(n-1);
                                        for(ll i=0;i<c-1;i++) v.push_back(n);
                                        }
                                }
                                for(ll i=0;i<(int)v.size();i++) {
                                        if(v[i]<1 || v[i]>n) ok=0;
                                }
                                if(!ok) cout<<"IMPOSSIBLE\n";
                                else{
                                        for(ll i=0;i<(int)v.size();i++) cout<<v[i] <<" ";
                                        cout<<"\n";
                                }
                        }
                }
       }    
}