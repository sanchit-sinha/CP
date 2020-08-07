#include "bits/stdc++.h"
using namespace std; 
#define ll long long 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int main(){
    IOS;
    ll n;cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n&1) n=n*3+1;
        else n/=2;
        cout<<n<<" ";
    }
    cout<<"\n";
}
