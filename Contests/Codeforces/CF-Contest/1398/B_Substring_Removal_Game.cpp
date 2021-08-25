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
                cin >> s;
                ll n=(int)s.size();
                vector<ll> one;

                for(ll i=0;i<n;i++){
                        if(s[i]=='1'){
                                ll ct=0;
                                while(s[i]=='1' && i<n)i++,ct++;
                                i--;
                                one.push_back(ct);
                        }
                }              

                sort(one.begin(),one.end());
                ll len=(int)(one.size());
                if(len==0) cout<<"0\n";
                else{
                        ll ans=0;
                        for(ll i=len-1;i>=0;i-=2) ans+=one[i];
                        cout<<ans<<"\n";
                }
       }    
}