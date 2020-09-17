#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll T;
    cin>>T;
    while(T--){
        ll n;
        cin >> n;
        ll a=(3*n)%4;
        ll b=(n%4);
        if(n==1) cout<<8<<"\n";
        else{
            for(ll i=0;i<(3*n)/4;++i) cout<<9;
            if(a==0){
                for(ll i=0;i<n/4;i++) cout<<8;
            }
            else{
                for(ll i=0;i<(n/4)+1;++i) cout<<8;
            }
            cout<<"\n";
        }
    }    
}