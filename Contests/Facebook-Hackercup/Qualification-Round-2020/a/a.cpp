#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll int

int main(){
    IOS;
    ll t;cin>>t;
    for(ll ii=1;ii<=t;ii++){
        cout<<"Case #"<<ii<<":\n";
        ll n;string in,out;
        cin>>n>>in>>out;

        for(ll i=0;i<n;i++){
            string front ,back;
            bool pos=1;
            if(out[i]=='N') pos=0;
            front.push_back('Y');
            for(ll j=i+1;j<n;j++){
                if(in[j]=='N') pos=0;
                if(pos) front.push_back('Y');
                else front.push_back('N');
                if(out[j]=='N') pos=0;
            }

            pos=1;
            if(out[i]=='N') pos=0;
            for(ll j=i-1;j>=0;j--){
                if(in[j]=='N') pos=0;
                if(pos) back.push_back('Y');
                else back.push_back('N');
                if(out[j]=='N') pos=0;
            }

            reverse(back.begin(),back.end());
            cout<<back<<front<<"\n";           
        }
    }
    
}
