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
        cin>>n;
        if(!(n&1)){
            cout<<(1+(n)/2)<<"\n";
        }
        else{
            cout<<(n+1)/2<<"\n";
        }
    }    
}